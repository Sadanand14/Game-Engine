#include "WindowHandler.h"


int main() 
{
	WindowCreator mainWin = WindowCreator("MyWindow", 1920, 1080);

	while(true)
	{
		mainWin.Update();
	}
	return 0;
}	