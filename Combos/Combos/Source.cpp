#include "Window.h"
#include "InputPoller.h"

int main()
{
	Window win1 = Window("InputWindow", 1920, 1080);
	Input input = Input(win1.GetWindow());
	
	glClearColor(1.0f, 0.1f, 0.1f, 1.0f);
	while (!win1.Closed())
	{
		//std::cout << input.GetX() << "," << input.GetY()<< std::endl;
		win1.Clear();
		glBegin(GL_QUADS);
		glVertex2f(0.5f,0.5f);
		glVertex2f(0.5f,-0.5f);
		glVertex2f(-0.5f,-0.5f);
		glVertex2f(-0.5f,0.5f);
		glEnd();
		win1.Update();
	}
	return 0;
}