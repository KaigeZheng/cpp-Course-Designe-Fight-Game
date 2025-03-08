#include "ExitButton.h"

ExitButton::ExitButton(const string text, int x, int y, int w, int h)
{
	PushButton();
	setTitle(text);
	move(x, y);
	resize(w, h);
}

void ExitButton::isClicked()
{
	while (true) {
		if (!isIn())break;
		while (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				if (isIn()) {
					this->show(GREEN);
					funcLButtonDown();
				}
				break;
			case WM_LBUTTONUP:
				if (isIn()) {
					this->show(WHITE);
					funcLButtonUp();
				}
				break;
			}
		}
		if (stopFlag)break;
		Sleep(100);
	}
}

void ExitButton::funcLButtonUp()
{
	clear();
	loadimage(&img, "./images/img0_3.png",1280,720,true);
	putimage(0, 0,&img);
	Sleep(3000);
	closegraph();
}

void ExitButton::funcLButtonDown()
{
}
