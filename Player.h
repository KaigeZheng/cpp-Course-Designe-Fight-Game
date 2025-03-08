#pragma once
#include"games.h"
class Player
{
public:
	Player(int x=50, int y=win_height-100-130, int hp = original_HPP, int mp = original_MPP, int SkillQ=1, int SkillW=1, int SkillE=1, int SkillPassive=1);
	int get_x();
	int get_y();
	int get_hp();
	int get_mp();
	int get_direction();//指示方向（0为左，1为右）
	void change_hp(int HP);
	void change_mp(int MP);
	void show();
	void unshow();
	void initStatus();//初始化状态栏
	void DrawStatus();//绘制状态栏（HP，MP）
	void DrawSkills();//绘制技能框
	void setSkill(int sQ,int sW,int sE,int sR,int sP);
	int getAttacking();//读取是否正在攻击
	void setAttacking();//在main函数中调用，恢复初始状态
	void changeK(int K);
	void Skill1();//Q技能
	void Skill2();//W技能
	void Skill3();//E技能
	void Skill4();//R技能
	void move_x(int x,int dir);
	void jump();//跳跃
	void Move();//操控键盘
private:
	IMAGE img_Player[12];//人物贴图
	int SkillQ = 1, SkillW = 1, SkillE = 1, SkillR = 1, SkillPassive = 1;
	int x, y, hp, mp;
	int attack=1, defence=1;
	int direction=1;//指示方向（0为左边，1为右）
	int status = 0;//是否正在使用技能
	int isSkilling = 0;//是否正在使用技能
	int originalY= win_height - 100 - 130;
	int isAttacking = 0;//是否正在攻击
	int step = 10;//移动速度
	//检测按键
	bool qKeyPressed = 0;
	bool prevQKeyPressed = 0;
	bool wKeyPressed = 0;
	bool prevWKeyPressed = 0;
	bool eKeyPressed = 0;
	bool prevEKeyPressed = 0;
	bool rKeyPressed = 0;
	bool prevRKeyPressed = 0;
	int k;//难度系数
};