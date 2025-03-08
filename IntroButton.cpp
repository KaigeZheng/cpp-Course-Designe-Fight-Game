#include "IntroButton.h"
#include "BackMenuButton.h"

IntroButton::IntroButton(const string text, int x, int y, int w, int h)
{
	PushButton();
	setTitle(text);
	move(x, y);
	resize(w, h);
}

void IntroButton::isClicked()
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

void IntroButton::funcLButtonUp()
{
	clear();
	IMAGE img;
	loadimage(&img, "./images/img0_9.png", 1280, 720, true);
	putimage(0, 0, &img);
	BackMenuButton buttonB("·µ»Ø²Ëµ¥", win_width - button_width0 / 2 - 20, win_height - button_height0 - 20, button_width0 / 2, button_height0);
	buttonB.show();
	while (1) {
		buttonB.Update();
		buttonB.isClicked();
		Sleep(100);
	}
}

void IntroButton::funcLButtonDown()
{
}
