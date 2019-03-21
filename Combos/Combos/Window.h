#ifndef WINDOW_H_
#define WINDOW_H_

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

class Window
{
private:
	const char* m_Name;
	int m_Width, m_Height;
	GLFWwindow* m_Window;
	bool closeWindow;
public:
	Window(const char*, int, int);
	virtual ~Window();
		
	inline bool GetStatus() const { return closeWindow;}
	inline GLFWwindow* GetWindow() const{ return m_Window;}

	void Update();
	void Clear();
		
	bool Closed()const;

private:
	bool Init();
};

#endif // !