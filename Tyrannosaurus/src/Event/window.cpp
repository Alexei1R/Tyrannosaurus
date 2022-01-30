#include <iostream>
#include "window.h"


#include "mouse.h"
#include "keyboard.h"

#include <sstream>

namespace CoreNative
{
	Window::Window(const std::string& name, int width, int height)
	{
		init(name, width, height);

		

	}

	void Window::init(const std::string& name, int width, int height)
	{


		this->name = name;
		this->width = width;
		this->height = height;


		if (!glfwInit())
		{
			std::cout << "glfw don't init";
		}

		window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);


		

		if (!window)
		{
			std::cout << "window don't init";
		}


		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK)
			std::cout << "GLEW failed..." << std::endl;



		glfwSetCursorPosCallback(window, Mouse::cursorPosCallback);
		glfwSetMouseButtonCallback(window, Mouse::mouseButtonCallback);
		glfwSetScrollCallback(window, Mouse::mouseWheelCallback);
		glfwSetKeyCallback(window, Keyboard::keyCallback);
	}



	




	Window::~Window()
	{
		glfwWindowShouldClose(window);
	}

}