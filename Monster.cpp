#include "Monster.h"

Monster::Monster(int x, int y, int hp, int direciton):x(x),y(y),hp(hp),direction(direciton)
{
	loadimage(img, "./images/img1_1.png", 300, 250, true);
	loadimage(img + 1, "./images/img1_2.png", 300, 250, true);
	loadimage(img + 2, "./images/img1_3.png", 300, 250, true);
	loadimage(img + 3, "./images/img1_4.png", 300, 250, true);
}

int Monster::get_x()
{
	return this->x;
}

int Monster::get_y()
{
	return this->y;
}

int Monster::get_hp()
{
	return this->hp;
}

int Monster::get_width()
{
	return this->width;
}

void Monster::move_x(int x, int dir)
{
	this->x += dir * x;
}

void Monster::initStatus()
{
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	outtextxy(win_width-40, 20, "HP");
	setfillcolor(RGB(51, 51, 51));
	fillrectangle(win_width - 50, 20, win_width - 50 - HP_width, 20 + HP_height);
}

void Monster::DrawStatus()
{
	initStatus();
	setfillcolor(RED);
	fillrectangle(win_width - 50, 20, win_width - 50 - HP_width * (hp > 0 ? hp : 0) / original_HPM, 20 + HP_height);
}

void Monster::change_hp(int HP)
{
	hp -= HP;
}



void Monster::show()
{
	DrawStatus();
	putimage(x, y, &img[direction+ 2], NOTSRCERASE);//»­ÑÚÂëÍ¼
	putimage(x, y, &img[direction], SRCINVERT);//»­Ô­ÂëÍ¼
}

void Monster::attack(int Px, int Py)
{
	if (x+width>Px+correction&&x+width<Px+130) {//ÓÒ±ß
		isAttacking = 1;
		return;
	}
	if (x<Px&&x+width>Px+130) {//ÖÐ¼ä
		isAttacking = 1;
		return;
	}
	if (x>Px&&x<Px+130-correction) {//×ó±ß
		isAttacking = 1;
		return;
	}
}

int Monster::getAttacking()
{
	return this->isAttacking;
}

void Monster::setAttacking()
{
	isAttacking = 0;
}


void Monster::LoopEvent(int Px,int Py)
{
	int step = 2;
	if (x + 30 > Px + 130) {
		x -= step;
		direction = 0;
	}
	else if (x + width - 30 < Px) {
		x += step;
		direction = 1;
	}
	attack(Px,Py);
}

void Monster::SetK(int K)
{
	k = K;
	hp = k * hp;
}
