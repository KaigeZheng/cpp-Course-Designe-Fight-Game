#pragma once
#include "PushButton.h"
#include"SetDifficultyButton.h"
#include"BackMenuButton.h"
class ChangeDifficultyButton :
    public PushButton
{
public:
    ChangeDifficultyButton(const string text = "Ñ¡ÔñÄÑ¶È", int x = 0, int y = 0, int w = button_width0, int h = button_height0);
    void isClicked()override;
    void funcLButtonUp()override;
    void funcLButtonDown()override;
    int get_k();
private:
    int k=1;
};

