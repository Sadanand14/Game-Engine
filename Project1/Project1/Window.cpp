#include "window.h"

Window::Window(const char* title, int width, int height)
{
	m_title = title;
	m_width = width;
	m_height = height;
	Init();
}

Window::~Window() 
{

}

void Window::update()const 
{

}

void Window::Init() 
{
	m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
	if (!m_window) 
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(m_window);

}