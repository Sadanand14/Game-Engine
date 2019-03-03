#pragma once

#include "glfw3.h"
#include <iostream>

class Window 
{
private:
	const char* m_title;
	int m_width, m_height;
	GLFWwindow* m_window;
public:

	Window(const char* title, int width, int height);
	~Window();
	void update() const;

private:
	void Init();
};