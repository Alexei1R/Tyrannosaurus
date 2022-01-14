#include "Window.h"



namespace Core {

	Window::Window(const std::string& name, int width, int height)
	{
		init(name, width, height);

	

	}

	void Window::init(const std::string& name, int width, int height)
	{


		this->name = name;
		this->width = width;
		this->height = height;


		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


		if (!glfwInit())
		{
			std::cout << "glfwInit()";
		}

		window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);




		if (!window)
		{
			std::cout << "windowInit";
		}


		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK)
			std::cout << "GLEW failed..." << std::endl;

		glfwSetWindowUserPointer(window, this);
		
	}



	Window::~Window()
	{
		glfwWindowShouldClose(window);
		glfwTerminate();
	}

}