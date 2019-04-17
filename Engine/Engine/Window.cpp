#include <Window.h>
#include <iostream>
void Window::Init() 
{
	if(!glfwInit())
	{
		std::cout << "GLFW initialization failed!" << std::endl;
	}
	
	m_window = glfwCreateWindow(m_width, m_height, m_name, NULL, NULL);
	glfwMakeContextCurrent(m_window);
}

void Window::Update()const
{
	glfwPollEvents();
}

void Window::Closed()const
{
	
}