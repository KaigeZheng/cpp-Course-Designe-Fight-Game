#include "PushButton.h"

PushButton::PushButton():text("PushButton"),x(0), y(0), w(100), h(30)
{
}

PushButton::PushButton(const string text, int x, int y, int w, int h):text(text),x(x),y(y),w(w),h(w)
{
}

void PushButton::show(COLORREF c)
{
	setfillcolor(color);
	fillroundrect(x, y, x + w, y + h, 10, 10);//绘制圆角矩形
	setbkmode(TRANSPARENT);
	settextcolor(c);
	outtextxy(x+(w-textwidth(text.c_str()))/2, y+ (h - textheight(text.c_str())) /2, text.c_str());//居中显示文字
}

void PushButton::setTitle(const string text)
{
	this->text = text;
}

void PushButton::move(int x, int y)
{
	this->x = x;
	this->y = y;
}

void PushButton::resize(int w, int h)
{
	this->w = w;
	this->h = h;
}

void PushButton::clear()
{
	stopFlag = true;
	cleardevice();
}

bool PushButton::isIn()//判定是否在按钮相应区域内
{
	if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h) {
		return true;
	}
	return false;
}

void PushButton::isClicked()
{
	while (true) {
		if (!isIn())break;//实现多个按钮同时活动
		while (peekmessage(&msg, EM_MOUSE)) {//读取鼠标信息
			switch (msg.message) {
			case WM_LBUTTONDOWN://左键按下
				if (isIn()) {
					this->show(GREEN);
					funcLButtonDown();
				}
				break;
			case WM_LBUTTONUP://左键放开
				if (isIn()) {
					this->show(WHITE);
					funcLButtonUp();
				}
				break;
			}
		}
		if(stopFlag)break;//并非所有按钮都在被按下后需要清除，因此需要重载
		Sleep(100);//设置延迟，减少CPU压力
	}
}

void PushButton::funcLButtonUp()
{
}

void PushButton::funcLButtonDown()
{
}

void PushButton::Update()
{
	peekmessage(&msg, EM_MOUSE);
}
