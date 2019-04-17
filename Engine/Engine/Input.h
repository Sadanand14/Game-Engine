#ifndef INPUT_H
#define	INPUT_H
#include <glfw3.h>
#define Max_keys 1024
#define Max_Buttons 32
class Input 

{
private:
	static bool m_keys[Max_keys];
	static bool m_mouse_buttons[Max_Buttons];
	static double mouseX, mouseY;
public:

private:
	friend void key_callback(GLFWwindow*, int key, int scancode, int action, int mods);
};

#endif // !INPUT_H


