#pragma once
#include <string>
#include <functional>


#include "GL/glew.h"
#include "GLFW/glfw3.h"


namespace CoreNative
{
	class Window final
	{
	public:
		float dots[6] = {
				-0.5f, -0.5f,
				0.0f, 0.5f,
				0.5f, -0.5f
		};
	private:
		std::string name;
		int width = 0;
		int height = 0;
		GLFWwindow* window = nullptr;
	public:
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
		
	private:
		Window(const std::string& name, int width, int height);
	private:
		~Window();
	public:
		static Window& getInstanse() { static Window instanse("Window", 1280, 720); return instanse; }
	public:
		void init(const std::string& name, int width, int height);
		__forceinline GLFWwindow* getGLFWwindow() const { return window; }
	
	};
}