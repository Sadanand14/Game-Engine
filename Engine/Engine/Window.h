#pragma once
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

class Window
{
private:
	const char* m_name;
	int m_width, m_height;
	GLFWwindow* m_window;
public:
	void Init();
	void Update ()const;
	void Closed ()const;
};