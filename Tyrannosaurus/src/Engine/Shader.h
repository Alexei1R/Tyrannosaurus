#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <unordered_map>



class Shader 
{
private:
	unsigned int program;
	std::string vertexData;
	std::string fragmentData;
	std::unordered_map<std::string, int > m_UniformLocationCache;

public:
	Shader(const char* vertexShader , const char* fragmentShader);
	void Bind();
	void UnBind();
	//   Set Uniform  
	void SetUniformMatrix4f(const std::string name, float value, unsigned int count);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);

private:
	std::string LoadShaderSRC(const char* filepath);
	unsigned int CompileShader(std::string& source, unsigned int type);
	unsigned int CreateShader();
	int GetUniformLocation(const std::string& name);


};