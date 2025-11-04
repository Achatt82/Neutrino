#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include "logger.h"

Logger::Logger() {

	std::filesystem::path logDir = std::filesystem::current_path().parent_path().parent_path() / "logs";
	std::filesystem::create_directories(logDir);

	// Debug
	std::cout << "Working directory: " << std::filesystem::current_path() << std::endl;
	std::cout << "Log directory: " << logDir << std::endl;

	std::filesystem::path logPath = logDir / "engine.log";
	logFile.open(logPath, std::ios::app);
	if (!logFile.is_open()) {
		std::cerr << "WARNING : Log file could not be opened..." << std::endl;
	}
}

Logger::~Logger() { logFile.close(); }

void Logger::log(LogLevel level, const std::string& message) {
	// Get time info
	time_t now = time(0);
	tm timeinfo;

	#ifdef _WIN32
		localtime_s(&timeinfo, &now);  // Windows-safe version
	#else
		timeinfo = *std::localtime(&now);  // POSIX systems
	#endif

	char timestamp[20];
	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &timeinfo);

	std::ostringstream logEntry;
	logEntry << "[" << timestamp << "] " << Logger::levelToString(level) << ": " << message << std::endl;
	std::cout << logEntry.str();

	if (logFile.is_open()) {
		logFile << logEntry.str();
		logFile.flush();
	}
}

std::string Logger::levelToString(LogLevel level)
{
    switch (level) {
	case LogLevel::DEBUG:     return "DEBUG";
	case LogLevel::INFO:      return "INFO";
	case LogLevel::WARNING:   return "WARNING";
	case LogLevel::ERROR:     return "ERROR";
	case LogLevel::CRITICAL:  return "CRITICAL";
    default:                  return "UNKNOWN";
    }
}