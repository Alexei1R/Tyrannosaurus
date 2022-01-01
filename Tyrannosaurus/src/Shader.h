#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>


struct ShaderProgramSource {
    std::string VertexSource;
    std::string FragmentSource;
};
class Shader
{
private:
    std::string m_FilePath;
    unsigned int m_RendererID;
    std::unordered_map<std::string, int > m_UniformLocationCache;

public:

    Shader(const std::string& filepath);
    ~Shader();

public:
    void Bind() const;
    void UnBind() const;


    //Set uniform
    void SetUniformMatrix4f(const std::string name, float* value, unsigned int count);
    void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    void SetUniform1i(const std::string& name, int value);
    void SetUniform1f(const std::string& name, float value);

private:
    ShaderProgramSource ParseShader(const std::string& filepath);
    unsigned int CompileShader(unsigned int type, const std::string& source);
    unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
    int GetUniformLocation(const std::string& name);


};
