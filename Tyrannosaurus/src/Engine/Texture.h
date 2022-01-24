#pragma once
#include <iostream>
#include <string>
#include "stb_image.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Texture
{
private:
	unsigned int textureID;
	const char* filepath;
	unsigned char* data;
	int tex_w, tex_h, tex_ch;

public:

	 Texture(const char* path);
	
	void Bind(unsigned int slot = 0);
	void UnBind();




	inline int GetWidth() const { return tex_w; }
	inline int GetHight() const { return tex_h; }

public:
	~Texture();
};



Texture::Texture(const char* path)
	:textureID(0), filepath(path), data(nullptr), tex_w(0), tex_h(0), tex_ch(0)
{
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	data = stbi_load(filepath, &tex_w, &tex_h, &tex_ch, 0);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex_w, tex_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}




}

Texture::~Texture()
{
	glDeleteTextures(1,&textureID);
}

void Texture::Bind(unsigned int slot)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::UnBind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}




