#pragma once
#include <string>
#include <glad/glad.h>

class Shader {
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	void Use() const;
	void SetColor(float r, float g, float b) const;
	GLuint GetID() const;

private:
	GLuint ID;

	std::string LoadShaderSource(const std::string& path) const;
	GLuint CompileShader(const std::string& source, GLenum type) const;
};