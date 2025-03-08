#pragma once
#include"games.h"
class Window
{
public:
	Window(int w, int h, int flag = NULL);
	static int width();//获取宽度
	static int height();//获取高度
	void SetTitle(const string& title);//设置窗体标题
private:
	HWND handle;//返回窗口句柄
};

