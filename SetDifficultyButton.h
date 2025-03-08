#pragma once
#include "PushButton.h"
#include <wincrypt.h>
class SetDifficultyButton :
    public PushButton
{
public:
    SetDifficultyButton(const string text = "难度", int x = 0, int y = 0, int w = button_width, int h = button_height,int k=1);
    void isClicked()override;
    void funcLButtonUp()override;
    void funcLButtonDown()override;
    void setActive();//激活
    void setNegative();//不激活
    bool returnActive();
    void set_k(int K);
    int get_k();
private:
    int k=1;
    bool isActive=0;
};

