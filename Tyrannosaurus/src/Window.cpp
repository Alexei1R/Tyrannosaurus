#include "Window.h"
#include "mauseevent.h"



namespace Core {

	Window::Window(const std::string& name, int width, int height)
	{
		init(name, width, height);

		setfnCallback([this](Event& e)
			{
				if (e.getType() == Event::EventType::WINDOW_CLOSED_EVENT)
				{
					glfwSetWindowShouldClose(window, GL_TRUE);
				}
				std::cout << e.format() << std::endl;
			});

	}

	void Window::init(const std::string& name, int width, int height)
	{


		this->name = name;
		this->width = width;
		this->height = height;


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
		//glfwSetCursorPosCallback(window, mouseMovedCallback);
		/*glfwSetScrollCallback(window, mouseScrollCallback);
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
		glfwSetKeyCallback(window, keyCallback);
		glfwSetWindowSizeCallback(window, windowResizeCallback);
		glfwSetWindowCloseCallback(window, windowCloseCallback);*/
	}



	void Window::mouseMovedCallback(GLFWwindow* window, double x, double y)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		MauseMuvedEvent e(x, y);
		handle.fnCallback(e);
	}




	



	Window::~Window()
	{
		glfwWindowShouldClose(window);
	}

}
