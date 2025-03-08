#include "SetDifficultyButton.h"

SetDifficultyButton::SetDifficultyButton(const string text, int x, int y, int w, int h,int k)
{
	PushButton();
	setTitle(text);
	move(x, y);
	resize(w, h);
	this->k = k;
}

void SetDifficultyButton::isClicked()
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

void SetDifficultyButton::funcLButtonUp()
{
	setActive();
}

void SetDifficultyButton::funcLButtonDown()
{
}

void SetDifficultyButton::setActive()
{
	isActive = 1;
}

void SetDifficultyButton::setNegative()
{
	isActive = 0;
}

bool SetDifficultyButton::returnActive()
{
	return isActive;
}

void SetDifficultyButton::set_k(int K)
{
	this->k = K;
}


int SetDifficultyButton::get_k()
{
	return k;
}

