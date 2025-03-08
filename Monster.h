#pragma once
#include"games.h"

class Monster
{
public:
	Monster(int x=600,int y= win_height - 100 - 200,int hp= original_HPM,int direciton=0);
	int get_x();
	int get_y();
	int get_hp();
	int get_width();
	void move_x(int x,int dir);
	void initStatus();
	void DrawStatus();
	void change_hp(int HP);
	void show();
	void attack(int Px,int Py);
	int getAttacking();
	void setAttacking();
	void LoopEvent(int Px,int Py);//朝人物移动,包含attack()的攻击逻辑与show()
	void SetK(int K);
private:
	IMAGE img[4];
	int width = 300;
	int x;
	int y;
	int hp;
	int direction;
	bool isAttacking = 0;
	int correction = 26;//修正系数
	int k=1;//难度系数
};

