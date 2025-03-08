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
	//初始化菜单（开始游戏，选择难度，游戏介绍，退出游戏）
}

void BackMenuButton::funcLButtonDown()
{
}

void BackMenuButton::initMenu()
{
	StartGameButton buttonS("开始游戏", 60, 20, button_width, button_height);
	ChangeDifficultyButton buttonC("选择难度", 60, 140, button_width, button_height);
	IntroButton buttonI("游戏介绍", 60, 260, button_width, button_height);
	ExitButton buttonE("退出游戏", 60, 380, button_width, button_height);
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
