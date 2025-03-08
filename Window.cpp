#include "Window.h"

Window::Window(int w, int h, int flag)
{
	handle = initgraph(w, h, flag);
}

int Window::width()
{
	return getwidth();
}

int Window::height()
{
	return getheight();
}

void Window::SetTitle(const string& title)
{
	SetWindowText(handle, title.c_str());
}



