#include "Player.h"
#include<future>

Player::Player(int x, int y, int hp, int mp, int SkillQ, int SkillW, int SkillE, int SkillPassive) :x(x), y(y), hp(hp), mp(mp),SkillQ(SkillQ),SkillW(SkillW),SkillE(SkillE),SkillR(SkillR),SkillPassive(SkillPassive)
{
    loadimage(img_Player, "./images/img2_1.png", 130, 130, true);
    loadimage(img_Player + 1, "./images/img2_2.png", 130, 130, true);
    loadimage(img_Player + 2, "./images/img2_3.png", 130, 130, true);
    loadimage(img_Player + 3, "./images/img2_4.png", 130, 130, true);
    loadimage(img_Player + 4, "./images/img2_5.png", 130, 130, true);
    loadimage(img_Player + 5, "./images/img2_6.png", 130, 130, true);
    loadimage(img_Player + 6, "./images/img2_7.png", 130, 130, true);
    loadimage(img_Player + 7, "./images/img2_8.png", 130, 130, true);
    loadimage(img_Player + 8, "./images/img2_9.png", 130, 130, true);
    loadimage(img_Player + 9, "./images/img2_10.png", 130, 130, true);
    loadimage(img_Player + 10, "./images/img2_11.png", 130, 130, true);
    loadimage(img_Player + 11, "./images/img2_12.png", 130, 130, true);
}

int Player::get_x()
{
    return this->x;
}

int Player::get_y()
{
    return this->y;
}

int Player::get_hp()
{
    return this->hp;
}

int Player::get_mp()
{
    return this->mp;
}

int Player::get_direction()
{
    return this->direction;
}

void Player::change_hp(int HP)
{
    hp -=HP;
    if (hp < -1)hp = -1;
    if (hp > original_HPP)hp = original_HPP;
}

void Player::change_mp(int MP)
{
    mp -= MP;
    if (mp < -1)mp = -1;
    if (mp > original_MPP)hp = original_MPP;
}

void Player::show()
{
   // DrawPNG(NULL, x, y, &img_Player[direction+status],BLACK);
    DrawStatus();
    putimage(x, y, &img_Player[direction + status + 6], NOTSRCERASE);//������ͼ
    putimage(x, y, &img_Player[direction + status], SRCINVERT);//��ԭ��ͼ
    if (status > 0) {
        isSkilling++;
        step = 0;
    }
    if (isSkilling == 20) {
        status = 0;
        isSkilling = 0;
        step = 10;
    }
}

void Player::unshow()
{
    clearrectangle(0, 0, win_width, win_height);
}

void Player::initStatus()
{
    setbkmode(TRANSPARENT);
    settextcolor(RED);
    outtextxy(20, 20, "HP");
    settextcolor(BLUE);
    outtextxy(20, 40, "MP");//����
    setfillcolor(RGB(51, 51, 51));
    fillrectangle(50, 20, 50 + HP_width, 20 + HP_height);
    fillrectangle(50, 40, 50 + MP_width, 40 + MP_height);//���Ƶ�ɫ
}

void Player::DrawStatus()
{
        initStatus();
        setfillcolor(RED);
        fillrectangle(50, 20, 50 + HP_width * (hp>0?hp:0) / original_HPP, 20 + HP_height);
        setfillcolor(BLUE);
        fillrectangle(50, 40, 50 + MP_width * (mp>0? mp:0) / original_MPP, 40 + MP_height);//����״̬��
}

void Player::DrawSkills()
{
}

void Player::setSkill(int sQ, int sW, int sE, int sR, int sP)
{
    SkillQ = sQ;
    SkillW = sW;
    SkillE = sE;
    SkillR = sR;
    SkillPassive = sP;
}

int Player::getAttacking()
{
    return this->isAttacking;
}

void Player::setAttacking()
{
    isAttacking = 0;
}

void Player::changeK(int K)
{
    this->k = K;
}

void Player::Skill1()
{
    isAttacking = 1;
}

void Player::Skill2()
{
    isAttacking = 2;
}

void Player::Skill3()
{
    isAttacking = 3;
}

void Player::Skill4()
{
    isAttacking = 4;
}

void Player::move_x(int x, int dir)
{
    if (this->x + 150 > win_width || this->x < 0)return;
    this->x += dir * x;
    if (this->x + 150 > win_width)this->x = win_width - 150;
    if (this->x < 0)this->x = 0;
}

void Player::jump()
{
    bool isJumping = true;
    int maxHeight = 150;
    int jumpSpeed = 15;
    int fallSpeed = 13;
    int moveSpeedUp = 5;
    int moveSpeedDown = 10;
    // �첽ִ����Ծ�߼�
    auto jumpFuture = std::async([&]() {
        while (isJumping)
        {
            y -= jumpSpeed;
            if (GetAsyncKeyState('A') & 0x8000)
            {
                if (x > -10)x -= moveSpeedUp;
                direction = 0;
            }
            if (GetAsyncKeyState('D') & 0x8000)
            {
                if (x + 150 < win_width)x += moveSpeedUp;
                direction = 1;
            }
            if (y <= originalY - maxHeight)
            {
                // ��Ծ�������߶Ⱥ�ʼ�½�
                while (y < originalY)
                {
                    y += fallSpeed;
                    // ���½�������ʵ���ƶ�
                    if (GetAsyncKeyState('A') & 0x8000)
                    {
                        if (x > -10)x -= moveSpeedDown;
                        direction = 0;
                    }
                    if (GetAsyncKeyState('D') & 0x8000)
                    {
                        if (x + 150 < win_width)x += moveSpeedDown;
                        direction = 1;
                    }
                    show();
                    FlushBatchDraw();
                    Sleep(10);
                    unshow();
                    FlushBatchDraw();
                }
                isJumping = false;
            }
            else
            {
                show();
                FlushBatchDraw();
                Sleep(10);
                unshow();
                FlushBatchDraw();
            }
        }
        });
    // �ȴ���Ծ�첽�������
    jumpFuture.wait();
    // �ָ����λ��
    y = originalY;
}

void Player::Move()
{
    unshow();
    qKeyPressed = (GetAsyncKeyState('Q') & 0x8000); // ��鵱ǰQ����״̬
    wKeyPressed = (GetAsyncKeyState('W') & 0x8000); // ��鵱ǰW����״̬
    eKeyPressed = (GetAsyncKeyState('E') & 0x8000); // ��鵱ǰE����״̬
    rKeyPressed = (GetAsyncKeyState('R') & 0x8000); // ��鵱ǰR����״̬
    if ((GetAsyncKeyState('A') & 0x8000)) {//a
        if (x > -10)x -= step;
        direction = 0;
    }
    if (GetAsyncKeyState('D') & 0x8000) {//d
        if (x + 150 < win_width)x += step;
        direction = 1;
    }
    if (qKeyPressed && !prevQKeyPressed) {//q
        status = 2;
        if (SkillQ == 1) {
            Skill1();
        }
        else if (SkillQ == 2) {
            //Q2
        }
        show();
    }
    if (wKeyPressed && !prevWKeyPressed) {//w
        if (mp > 0) {
            status = 2;
            Skill2();
            show();
        }
    }
    if (eKeyPressed && !prevEKeyPressed) {//e
        if (mp > 0) {
            status = 2;
            Skill3();
            show();
        }
    }
    if (rKeyPressed && !prevRKeyPressed) {//r
        if (mp > 0) {
            status = 4;
            Skill4();
            show();
        }
    }
    if ((GetAsyncKeyState(VK_SPACE) & 0x8000)) {//�ո�
        jump();
    }
    prevQKeyPressed = qKeyPressed; // ��¼��ǰQ����״̬����һ�αȽ�
    prevWKeyPressed = wKeyPressed; // ��¼��ǰW����״̬����һ�αȽ�
    prevEKeyPressed = eKeyPressed; // ��¼��ǰE����״̬����һ�αȽ�
    prevRKeyPressed = rKeyPressed; // ��¼��ǰR����״̬����һ�αȽ�
}