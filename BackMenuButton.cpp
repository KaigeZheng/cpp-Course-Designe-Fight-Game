#include "BackMenuButton.h"
#include "StartGameButton.h"
#include "ChangeDifficultyButton.h"
#include "IntroButton.h"
#include "ExitButton.h"
#include"StartGameButton.h"
#include"IntroButton.h"
#include"Player.h"
#include"Monster.h"
#include"Window.h"
#include"games.h"

BackMenuButton::BackMenuButton(const string text, int x, int y, int w, int h)
{
	PushButton();
	setTitle(text);
	move(x, y);
	resize(w, h);
}

void BackMenuButton::isClicked()
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

void BackMenuButton::funcLButtonUp()
{
	clear();
	initMenu();
	//��ʼ���˵�����ʼ��Ϸ��ѡ���Ѷȣ���Ϸ���ܣ��˳���Ϸ��
}

void BackMenuButton::funcLButtonDown()
{
}

void BackMenuButton::initMenu()
{
	StartGameButton buttonS("��ʼ��Ϸ", 60, 20, button_width, button_height);
	ChangeDifficultyButton buttonC("ѡ���Ѷ�", 60, 140, button_width, button_height);
	IntroButton buttonI("��Ϸ����", 60, 260, button_width, button_height);
	ExitButton buttonE("�˳���Ϸ", 60, 380, button_width, button_height);
	IMAGE img;
	loadimage(&img, "./images/img0_8.png", 1280, 720, true);
	putimage(0, 0, &img);
	buttonS.show();
	buttonC.show();
	buttonI.show();
	buttonE.show();
	while (true) {
		buttonS.Update();
		buttonC.Update();
		buttonI.Update();
		buttonE.Update();
		buttonS.isClicked();
		buttonC.isClicked();
		buttonI.isClicked();
		buttonE.isClicked();
		Sleep(100);
	}
}
