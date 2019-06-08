#include "WindowHandler.h"

WindowCreator::WindowCreator(const char* name, int width, int height)
{
	glewInitialized = false;
	m_name = name;
	m_height = height;
	m_width = width;
	Init();
}

WindowCreator::~WindowCreator()
{
	if (mainWindow)
	{
		glfwDestroyWindow(mainWindow);
	}
	glfwTerminate();
}

void WindowCreator::Init()
{
	if (!glfwInit()) 
	{
		std::cout << "glfw failed to initialize.\n";
		glfwTerminate();
		return;
	}

	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	mainWindow = glfwCreateWindow(m_width, m_height, m_name , NULL, NULL);
	if (!mainWindow) 
	{
		std::cout << "window creation failed!\n";
		glfwTerminate();
		return;
	}

	int bufferwidth, bufferheight;
	glfwGetFramebufferSize(mainWindow,&bufferwidth, &bufferheight);

	glfwMakeContextCurrent(mainWindow);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) 
	{
		glewInitialized = true;
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return;
	}

	//glViewport(0, 0, bufferwidth, bufferheight);
}

void WindowCreator::Update() 
{
	glfwPollEvents();
	glClearColor(0.0f,0.5f,0.5f,1.0f);
	//glClear(GL_COLOR_BUFFER_BIT);
}