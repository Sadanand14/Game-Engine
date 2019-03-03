
int main() 
{
	if (!glfwInit()) 
	{
		std::cout << "ERROR in Intialization" << std::endl;
	}

	GLFWwindow* window = glfwCreateWindow(1270, 720, "My window", glfwGetPrimaryMonitor(), NULL);

	if (!window) 
	{
		std::cout << "Failed to create window" << std::endl;
	}
	glfwMakeContextCurrent(window);
	
	
	while (glfwWindowShouldClose(window)) 
	{
		print a = "user requested window should close.";
		std::cout << a << std::endl;
	}
	getchar();
	return 0;
}

