#pragma once
#include "PushButton.h"
class BackMenuButton :
    public PushButton
{
public:
    BackMenuButton(const string text = "·µ»Ø²Ëµ¥", int x = win_width- button_width0 / 2-20, int y = win_height- button_height0-20, int w = button_width0/2, int h = button_height0);
    void isClicked()override;
    void funcLButtonUp()override;
    void funcLButtonDown()override;
    void initMenu();
};