#include "shader.h"
#include "logger.h"
#include <fstream>
#include <sstream>
#include <iostream>

Logger logger;

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {

	// Load shader sources
	std::string vertexSource = LoadShaderSource(vertexPath);
	std::string fragmentSource = LoadShaderSource(fragmentPath);

	// Compile shaders
	GLuint vertexShader = CompileShader(vertexSource, GL_VERTEX_SHADER);
	GLuint fragmentShader = CompileShader(fragmentSource, GL_FRAGMENT_SHADER);

	// Create shader program
	ID = glCreateProgram();

	// Attach compiled shaders to shader program
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);

	// Link shader program to OpenGL
	glLinkProgram(ID);

	int success;
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		logger.log(CRITICAL, "Shader program linking failed:\n" + (std::string)infoLog);
	}

	// Delete compiled shaders
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::~Shader() {
	glDeleteProgram(ID);
}

void Shader::Use() const {
	glUseProgram(ID);
}

GLuint Shader::GetID() const { return ID; }

void Shader::SetColor(float r, float g, float b) const {
	GLuint loc = glGetUniformLocation(ID, "vertexColor");
	glUniform3f(loc, r, g, b);
}

std::string Shader::LoadShaderSource(const std::string& path) const {

	// Load file
	std::ifstream file(path);

	// Check file opened successfully
	if (!file.is_open()) {
		logger.log(CRITICAL, "Failed to load shader source: " + path);
		return "";
	}

	// Read file
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

GLuint Shader::CompileShader(const std::string& source, GLenum type) const {

	// Create shader
	GLuint shader = glCreateShader(type);

	// Convert shader source to contiguous array of characters
	const char* src = source.c_str();

	// Set shader source and compile
	glShaderSource(shader, 1, &src, NULL);
	glCompileShader(shader);

	// Check for compilation errors
	int success;
	glGetProgramiv(ID, GL_COMPILE_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		logger.log(CRITICAL, "Shader compilation failed: " + (std::string)(type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") + "\n" + (std::string)infoLog);
	}

	return shader;
}