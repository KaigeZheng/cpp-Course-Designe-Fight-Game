#pragma once
#include"games.h"
class PushButton
{
public:
	PushButton();
	PushButton(const string text, int x = 0, int y = 0, int w = 100, int h = 30);
	void show(COLORREF c=WHITE);
	void setTitle(const string text);
	void move(int x,int y);
	void resize(int w,int h);
	bool isIn();
	virtual void clear();
	virtual void isClicked();
	virtual void funcLButtonUp();
	virtual void funcLButtonDown();
	void Update();
protected:
	string text;
	int x, y, w, h;
	COLORREF color = RGB(51, 51, 51);
	ExMessage msg;
	bool stopFlag = false;
};


