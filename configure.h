#pragma once
#include"Window.h"
#include"PushButton.h"
#include"ChangeDifficultyButton.h"
#include"SetDifficultyButton.h"
#include"ExitButton.h"
#include"BackMenuButton.h"
#include"StartGameButton.h"
#include"IntroButton.h"
#include"Player.h"
#include"Monster.h"
#include"games.h"

StartGameButton buttonS("开始游戏",60,20,button_width,button_height);
ChangeDifficultyButton buttonC("选择难度", 60, 140, button_width, button_height);
IntroButton buttonI("游戏介绍", 60, 260, button_width, button_height);
ExitButton buttonE("退出游戏", 60, 380, button_width, button_height);
IMAGE img_bk;
IMAGE img_win;
IMAGE img_lose;
Player P;Monster M;
bool gamelose = 0;//判断是否失败
bool gamewin = 0;//判断是否胜利

bool checkR() {//右攻击判定伤害范围
	if (P.get_x() + 130 + 100 > M.get_x() && P.get_x() + 130 + 100 < M.get_x() + M.get_width())return true;
	if (P.get_x() + 130 - 20 > M.get_x() && P.get_x() + 130 + 100 < M.get_x() + M.get_width())return true;
	if (P.get_x() + 130 - 20 > M.get_x() && P.get_x() + 130 - 20 < M.get_x() + M.get_width())return true;
	return false;
}

bool checkL() {//左攻击判定伤害范围
	if (P.get_x() - 100 > M.get_x() && P.get_x() - 100 < M.get_x() + M.get_width())return true;
	if (P.get_x() - 100 > M.get_x() && P.get_x() + 20 < M.get_x() + M.get_width())return true;
	if (P.get_x() + 20 > M.get_x() && P.get_x() + 20 < M.get_x() + M.get_width())return true;
	return false;
}

void Pending() {//伤害判定
	if (P.getAttacking() > 0) {
		if (P.getAttacking() == 1) {//普通攻击Q
			P.setAttacking();
			if (P.get_direction() == 1) {//向右攻击
				if (checkR()) {
					M.change_hp(100);
					M.move_x(10, 1);
				}
			}
			else if (P.get_direction() == 0) {//向左攻击
				if (checkL()) {
					M.change_hp(100);
					M.move_x(10, -1);
				}
			}
		}
		if (P.getAttacking() == 2) {//后撤攻击W
			P.setAttacking();
			P.change_mp(10);
			if (P.get_direction() == 1) {//向右攻击
				if (checkR()) {
					M.change_hp(50);
					M.move_x(8, 1);
					P.move_x(100, -1);
				}
			}
			if (P.get_direction() == 0) {//向左攻击
				if (checkL()) {
					M.change_hp(50);
					M.move_x(8, -1);
					P.move_x(100, 1);
				}
			}
		}
		if (P.getAttacking() == 3) {//突刺攻击E
			P.setAttacking();
			P.change_mp(10);
			if (P.get_direction() == 1) {
				P.move_x(400, 1);
				if (checkR()) {
					M.change_hp(50);
					M.move_x(10, 1);
				}
			}
			if (P.get_direction() == 0) {
				P.move_x(200, -1);
				if (checkL()) {
					M.change_hp(50);
					M.move_x(10, -1);
				}
			}
		}
		if (P.getAttacking() == 4) {//恢复技能R
			P.change_mp(5);
			P.setAttacking();
			P.change_hp(-4);
		}
		if (M.get_hp() <= 0)gamewin = 1;//判定玩家胜利
	}
	if (M.getAttacking() > 0) {
		if (M.getAttacking() == 1) {
			M.setAttacking();
			P.change_hp(1);
		}
	}
	if (P.get_hp() <= 0)gamelose = 1;//判定玩家失败
}

void LoopEvent1() {
	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) {//暂停功能
			settextcolor(RED);
			outtextxy(600, 200, "暂停中...");
			FlushBatchDraw();
			while (!(GetAsyncKeyState(VK_ESCAPE) & 0x0001));
			clearrectangle(600, 200, 700, 250);
		}
		P.Move();//Player移动
		clearrectangle(0, 0, win_width, win_height);
		Pending();//伤害判定（Player攻击与Monster攻击）
		M.LoopEvent(P.get_x(), P.get_y());//传入Player的x，y坐标，更新Monster的移动
		M.show();
		P.show();
		FlushBatchDraw();//更新Player与Monster画面
		Sleep(10);
		if (gamewin==1|| gamelose==1) {
			clearrectangle(0, 0, win_width, win_height);
			FlushBatchDraw();
			if (gamewin == 1) {//进入胜利结算页面
				loadimage(&img_win, "./images/img0_6.png",win_width,win_height);
				putimage(0, 0, &img_win);
				FlushBatchDraw();
			}
			else if (gamelose == 1) {//进入失败结算页面
				loadimage(&img_lose, "./images/img0_4.png", win_width, win_height);
				putimage(0, 0, &img_lose);
				FlushBatchDraw();
			}
			Sleep(3000);
			closegraph();//退出游戏
		}
	}
}

void initMenuShow() {//显示开始界面的四个按钮
	buttonS.show();
	buttonC.show();
	buttonI.show();
	buttonE.show();
}

void initMenuIsClicked() {//显示开始界面的四个按钮
	buttonS.isClicked();
	buttonC.isClicked();
	buttonI.isClicked();
	buttonE.isClicked();
}

void initMenuUpdate() {//鼠标更新
	buttonS.Update();
	buttonC.Update();
	buttonI.Update();
	buttonE.Update();
}

void initMenuLoop() {//菜单循环事件
	while (true) {
		initMenuUpdate();
		initMenuIsClicked();
		if (buttonS.getStarting()) {//当开始游戏按钮被激活
			M.SetK(buttonC.get_k());//传入难度参数
			P.show();
			P.initStatus();
			BeginBatchDraw();
			LoopEvent1();//执行循环事件
		}
		Sleep(10);
	}
}

void initMenu() {//初始化开始菜单(开始游戏，选择难度，游戏介绍，退出游戏）
	Window w(win_width, win_height);
	w.SetTitle(GAME);
	IMAGE img;
	loadimage(&img, "./images/img0_8.png", 1280, 720, true);
	putimage(0, 0, &img);
	initMenuShow();//显示四个按钮
	initMenuLoop();
	FlushBatchDraw();//刷新屏幕
}

