#pragma once
#include "PushButton.h"
#include <wincrypt.h>
class SetDifficultyButton :
    public PushButton
{
public:
    SetDifficultyButton(const string text = "�Ѷ�", int x = 0, int y = 0, int w = button_width, int h = button_height,int k=1);
    void isClicked()override;
    void funcLButtonUp()override;
    void funcLButtonDown()override;
    void setActive();//����
    void setNegative();//������
    bool returnActive();
    void set_k(int K);
    int get_k();
private:
    int k=1;
    bool isActive=0;
};

