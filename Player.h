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
	int get_direction();//ָʾ����0Ϊ��1Ϊ�ң�
	void change_hp(int HP);
	void change_mp(int MP);
	void show();
	void unshow();
	void initStatus();//��ʼ��״̬��
	void DrawStatus();//����״̬����HP��MP��
	void DrawSkills();//���Ƽ��ܿ�
	void setSkill(int sQ,int sW,int sE,int sR,int sP);
	int getAttacking();//��ȡ�Ƿ����ڹ���
	void setAttacking();//��main�����е��ã��ָ���ʼ״̬
	void changeK(int K);
	void Skill1();//Q����
	void Skill2();//W����
	void Skill3();//E����
	void Skill4();//R����
	void move_x(int x,int dir);
	void jump();//��Ծ
	void Move();//�ٿؼ���
private:
	IMAGE img_Player[12];//������ͼ
	int SkillQ = 1, SkillW = 1, SkillE = 1, SkillR = 1, SkillPassive = 1;
	int x, y, hp, mp;
	int attack=1, defence=1;
	int direction=1;//ָʾ����0Ϊ��ߣ�1Ϊ�ң�
	int status = 0;//�Ƿ�����ʹ�ü���
	int isSkilling = 0;//�Ƿ�����ʹ�ü���
	int originalY= win_height - 100 - 130;
	int isAttacking = 0;//�Ƿ����ڹ���
	int step = 10;//�ƶ��ٶ�
	//��ⰴ��
	bool qKeyPressed = 0;
	bool prevQKeyPressed = 0;
	bool wKeyPressed = 0;
	bool prevWKeyPressed = 0;
	bool eKeyPressed = 0;
	bool prevEKeyPressed = 0;
	bool rKeyPressed = 0;
	bool prevRKeyPressed = 0;
	int k;//�Ѷ�ϵ��
};