#include "StartGameButton.h"

StartGameButton::StartGameButton(const string text, int x, int y, int w, int h)
{
	PushButton();
	setTitle(text);
	move(x, y);
	resize(w, h);
}

void StartGameButton::isClicked()
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

void StartGameButton::funcLButtonUp()
{
	clear();
	IMAGE img;
	loadimage(&img, "./images/img0_2.png", win_width, win_height, true);
	putimage(0, 0, &img);
	Sleep(3000);
	clear();
	isStarting = 1;
}

void StartGameButton::funcLButtonDown()
{
}

bool StartGameButton::getStarting()
{
	return isStarting;
}
