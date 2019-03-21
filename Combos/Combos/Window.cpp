#include "Window.h"
#include <iostream>

void Resize(GLFWwindow* window, int width, int height);

Window::Window(const char* name, int width, int height)
{
	m_Name = name;
	m_Width = width;
	m_Height = height;
	if (!Init()) 
	{
		glfwTerminate();
	}
}

bool Window::Init()
{
	//glfw initialisation
	if (!glfwInit())
	{
		std::cout << "GLFW initialization failed!" << std::endl;
		return false;
	}


	//window creation
	m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
	if (!m_Window) 
	{
		std::cout << "Window creation failed!" << std::endl;
	}


	glfwMakeContextCurrent(m_Window);//setcurrentcontext
	glfwSetWindowSizeCallback(m_Window, Resize);// setting up callback
	
	//glew initialisation(MAKE SURE ITS ALWAYS DONE AFTER SETTING CONTEXT OR ELSE IT FAILS)
	if (glewInit()!=GLEW_OK) 
	{
		std::cout << "GLEW initialisation failed!" << std::endl;
	}
	return true;
}

void Window::Clear() 
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void Window::Update()
{

	/*if (closeWindow) 
	{
		glfwDestroyWindow(m_Window);
	}*/
	
	
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

//flag for checking if window closing was requested
bool Window::Closed()const
{
	return glfwWindowShouldClose(m_Window);
}

Window::~Window() 
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

//callback for everytime the window is resized
void Resize(GLFWwindow* window, int width, int height) 
{
	glViewport(0, 0, width, height);
}