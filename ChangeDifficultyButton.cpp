#include "ChangeDifficultyButton.h"
#include"SetDifficultyButton.h"
#include"BackMenuButton.h"

ChangeDifficultyButton::ChangeDifficultyButton(const string text, int x, int y, int w, int h)
{
	PushButton();
	setTitle(text);
	move(x, y);
	resize(w, h);
}

void ChangeDifficultyButton::isClicked()
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

void ChangeDifficultyButton::funcLButtonUp()
{
	clear();
	IMAGE img;
	loadimage(&img, "./images/img0_8.png", 1280, 720, true);
	putimage(0, 0, &img);
	SetDifficultyButton buttonD1("简单", 20, 100, button_width, button_height, 1);
	SetDifficultyButton buttonD2("普通", 20, 250, button_width, button_height, 2);
	SetDifficultyButton buttonD3("困难", 20, 400, button_width, button_height, 3);
	buttonD1.set_k(1);
	buttonD2.set_k(2);
	buttonD3.set_k(3);
	buttonD1.show();
	buttonD2.show();
	buttonD3.show();
	BackMenuButton buttonB("返回菜单", win_width - button_width0 / 2 - 20, win_height - button_height0 - 20, button_width0 / 2, button_height0);
	buttonB.show();
	while (1) {
		buttonD1.Update();buttonD2.Update();buttonD3.Update();buttonB.Update();
		buttonB.isClicked();
		buttonD1.isClicked();
		buttonD2.isClicked();
		buttonD3.isClicked();
		if (buttonD1.returnActive() == 1) {
			buttonD2.setNegative();
			buttonD3.setNegative();
			this->k = buttonD1.get_k();
		}
		if (buttonD2.returnActive() == 1) {
			buttonD1.setNegative();
			buttonD3.setNegative();
			this->k = buttonD2.get_k();
		}
		if (buttonD3.returnActive() == 1) {
			buttonD1.setNegative();
			buttonD2.setNegative();
			this->k = buttonD3.get_k();
		}
		Sleep(100);
	}
}

void ChangeDifficultyButton::funcLButtonDown()
{
}

int ChangeDifficultyButton::get_k()
{
	return this->k;
}
