#pragma once
#include <GL/glew.h>
#include <string>

class ShaderLoader
{
public:
	GLuint CreateProgram(const char* vertexShaderFileName, const char* fragmentShaderFilename);

private:
	std::string readShader(const char* fileName);
	GLuint createShader(GLenum shaderType, std::string source, const char* shaderName);
};

