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
	fillroundrect(x, y, x + w, y + h, 10, 10);//����Բ�Ǿ���
	setbkmode(TRANSPARENT);
	settextcolor(c);
	outtextxy(x+(w-textwidth(text.c_str()))/2, y+ (h - textheight(text.c_str())) /2, text.c_str());//������ʾ����
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

bool PushButton::isIn()//�ж��Ƿ��ڰ�ť��Ӧ������
{
	if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h) {
		return true;
	}
	return false;
}

void PushButton::isClicked()
{
	while (true) {
		if (!isIn())break;//ʵ�ֶ����ťͬʱ�
		while (peekmessage(&msg, EM_MOUSE)) {//��ȡ�����Ϣ
			switch (msg.message) {
			case WM_LBUTTONDOWN://�������
				if (isIn()) {
					this->show(GREEN);
					funcLButtonDown();
				}
				break;
			case WM_LBUTTONUP://����ſ�
				if (isIn()) {
					this->show(WHITE);
					funcLButtonUp();
				}
				break;
			}
		}
		if(stopFlag)break;//�������а�ť���ڱ����º���Ҫ����������Ҫ����
		Sleep(100);//�����ӳ٣�����CPUѹ��
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
