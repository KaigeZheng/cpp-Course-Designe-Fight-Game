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

StartGameButton buttonS("��ʼ��Ϸ",60,20,button_width,button_height);
ChangeDifficultyButton buttonC("ѡ���Ѷ�", 60, 140, button_width, button_height);
IntroButton buttonI("��Ϸ����", 60, 260, button_width, button_height);
ExitButton buttonE("�˳���Ϸ", 60, 380, button_width, button_height);
IMAGE img_bk;
IMAGE img_win;
IMAGE img_lose;
Player P;Monster M;
bool gamelose = 0;//�ж��Ƿ�ʧ��
bool gamewin = 0;//�ж��Ƿ�ʤ��

bool checkR() {//�ҹ����ж��˺���Χ
	if (P.get_x() + 130 + 100 > M.get_x() && P.get_x() + 130 + 100 < M.get_x() + M.get_width())return true;
	if (P.get_x() + 130 - 20 > M.get_x() && P.get_x() + 130 + 100 < M.get_x() + M.get_width())return true;
	if (P.get_x() + 130 - 20 > M.get_x() && P.get_x() + 130 - 20 < M.get_x() + M.get_width())return true;
	return false;
}

bool checkL() {//�󹥻��ж��˺���Χ
	if (P.get_x() - 100 > M.get_x() && P.get_x() - 100 < M.get_x() + M.get_width())return true;
	if (P.get_x() - 100 > M.get_x() && P.get_x() + 20 < M.get_x() + M.get_width())return true;
	if (P.get_x() + 20 > M.get_x() && P.get_x() + 20 < M.get_x() + M.get_width())return true;
	return false;
}

void Pending() {//�˺��ж�
	if (P.getAttacking() > 0) {
		if (P.getAttacking() == 1) {//��ͨ����Q
			P.setAttacking();
			if (P.get_direction() == 1) {//���ҹ���
				if (checkR()) {
					M.change_hp(100);
					M.move_x(10, 1);
				}
			}
			else if (P.get_direction() == 0) {//���󹥻�
				if (checkL()) {
					M.change_hp(100);
					M.move_x(10, -1);
				}
			}
		}
		if (P.getAttacking() == 2) {//�󳷹���W
			P.setAttacking();
			P.change_mp(10);
			if (P.get_direction() == 1) {//���ҹ���
				if (checkR()) {
					M.change_hp(50);
					M.move_x(8, 1);
					P.move_x(100, -1);
				}
			}
			if (P.get_direction() == 0) {//���󹥻�
				if (checkL()) {
					M.change_hp(50);
					M.move_x(8, -1);
					P.move_x(100, 1);
				}
			}
		}
		if (P.getAttacking() == 3) {//ͻ�̹���E
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
		if (P.getAttacking() == 4) {//�ָ�����R
			P.change_mp(5);
			P.setAttacking();
			P.change_hp(-4);
		}
		if (M.get_hp() <= 0)gamewin = 1;//�ж����ʤ��
	}
	if (M.getAttacking() > 0) {
		if (M.getAttacking() == 1) {
			M.setAttacking();
			P.change_hp(1);
		}
	}
	if (P.get_hp() <= 0)gamelose = 1;//�ж����ʧ��
}

void LoopEvent1() {
	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) {//��ͣ����
			settextcolor(RED);
			outtextxy(600, 200, "��ͣ��...");
			FlushBatchDraw();
			while (!(GetAsyncKeyState(VK_ESCAPE) & 0x0001));
			clearrectangle(600, 200, 700, 250);
		}
		P.Move();//Player�ƶ�
		clearrectangle(0, 0, win_width, win_height);
		Pending();//�˺��ж���Player������Monster������
		M.LoopEvent(P.get_x(), P.get_y());//����Player��x��y���꣬����Monster���ƶ�
		M.show();
		P.show();
		FlushBatchDraw();//����Player��Monster����
		Sleep(10);
		if (gamewin==1|| gamelose==1) {
			clearrectangle(0, 0, win_width, win_height);
			FlushBatchDraw();
			if (gamewin == 1) {//����ʤ������ҳ��
				loadimage(&img_win, "./images/img0_6.png",win_width,win_height);
				putimage(0, 0, &img_win);
				FlushBatchDraw();
			}
			else if (gamelose == 1) {//����ʧ�ܽ���ҳ��
				loadimage(&img_lose, "./images/img0_4.png", win_width, win_height);
				putimage(0, 0, &img_lose);
				FlushBatchDraw();
			}
			Sleep(3000);
			closegraph();//�˳���Ϸ
		}
	}
}

void initMenuShow() {//��ʾ��ʼ������ĸ���ť
	buttonS.show();
	buttonC.show();
	buttonI.show();
	buttonE.show();
}

void initMenuIsClicked() {//��ʾ��ʼ������ĸ���ť
	buttonS.isClicked();
	buttonC.isClicked();
	buttonI.isClicked();
	buttonE.isClicked();
}

void initMenuUpdate() {//������
	buttonS.Update();
	buttonC.Update();
	buttonI.Update();
	buttonE.Update();
}

void initMenuLoop() {//�˵�ѭ���¼�
	while (true) {
		initMenuUpdate();
		initMenuIsClicked();
		if (buttonS.getStarting()) {//����ʼ��Ϸ��ť������
			M.SetK(buttonC.get_k());//�����ѶȲ���
			P.show();
			P.initStatus();
			BeginBatchDraw();
			LoopEvent1();//ִ��ѭ���¼�
		}
		Sleep(10);
	}
}

void initMenu() {//��ʼ����ʼ�˵�(��ʼ��Ϸ��ѡ���Ѷȣ���Ϸ���ܣ��˳���Ϸ��
	Window w(win_width, win_height);
	w.SetTitle(GAME);
	IMAGE img;
	loadimage(&img, "./images/img0_8.png", 1280, 720, true);
	putimage(0, 0, &img);
	initMenuShow();//��ʾ�ĸ���ť
	initMenuLoop();
	FlushBatchDraw();//ˢ����Ļ
}

