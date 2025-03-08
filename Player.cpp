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
    putimage(x, y, &img_Player[direction + status + 6], NOTSRCERASE);//画掩码图
    putimage(x, y, &img_Player[direction + status], SRCINVERT);//画原码图
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
    outtextxy(20, 40, "MP");//文字
    setfillcolor(RGB(51, 51, 51));
    fillrectangle(50, 20, 50 + HP_width, 20 + HP_height);
    fillrectangle(50, 40, 50 + MP_width, 40 + MP_height);//绘制底色
}

void Player::DrawStatus()
{
        initStatus();
        setfillcolor(RED);
        fillrectangle(50, 20, 50 + HP_width * (hp>0?hp:0) / original_HPP, 20 + HP_height);
        setfillcolor(BLUE);
        fillrectangle(50, 40, 50 + MP_width * (mp>0? mp:0) / original_MPP, 40 + MP_height);//绘制状态栏
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
    // 异步执行跳跃逻辑
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
                // 跳跃到达最大高度后开始下降
                while (y < originalY)
                {
                    y += fallSpeed;
                    // 在下降过程中实现移动
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
    // 等待跳跃异步操作完成
    jumpFuture.wait();
    // 恢复玩家位置
    y = originalY;
}

void Player::Move()
{
    unshow();
    qKeyPressed = (GetAsyncKeyState('Q') & 0x8000); // 检查当前Q键的状态
    wKeyPressed = (GetAsyncKeyState('W') & 0x8000); // 检查当前W键的状态
    eKeyPressed = (GetAsyncKeyState('E') & 0x8000); // 检查当前E键的状态
    rKeyPressed = (GetAsyncKeyState('R') & 0x8000); // 检查当前R键的状态
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
    if ((GetAsyncKeyState(VK_SPACE) & 0x8000)) {//空格
        jump();
    }
    prevQKeyPressed = qKeyPressed; // 记录当前Q键的状态供下一次比较
    prevWKeyPressed = wKeyPressed; // 记录当前W键的状态供下一次比较
    prevEKeyPressed = eKeyPressed; // 记录当前E键的状态供下一次比较
    prevRKeyPressed = rKeyPressed; // 记录当前R键的状态供下一次比较
}