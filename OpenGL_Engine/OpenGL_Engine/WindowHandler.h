#ifndef WINDOW_HANDLER_H
#define WINDOW_HANDLER_H

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class WindowCreator 
{
private:
	int m_width;
	int m_height;
	const char* m_name;
	GLFWwindow* mainWindow;
	bool glewInitialized;

public:
	WindowCreator(const char*, int, int);
	~WindowCreator();

	void Init();
	void Update();
};

#endif // !WINDOW_H
