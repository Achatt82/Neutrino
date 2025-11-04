#pragma once

#include <string>
#include <fstream>

enum LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL };

class Logger {
public:
	Logger();
	~Logger();

	void log(LogLevel level, const std::string& message);

private:
	std::ofstream logFile;

	std::string levelToString(LogLevel level);
};