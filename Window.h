#pragma once
#include"games.h"
class Window
{
public:
	Window(int w, int h, int flag = NULL);
	static int width();//��ȡ���
	static int height();//��ȡ�߶�
	void SetTitle(const string& title);//���ô������
private:
	HWND handle;//���ش��ھ��
};

