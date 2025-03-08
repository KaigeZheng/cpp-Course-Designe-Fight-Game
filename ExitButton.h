#pragma once
#include "PushButton.h"
class ExitButton :
    public PushButton
{
public:
    ExitButton(const string text = "ÍË³öÓÎÏ·", int x = 0, int y = 0, int w = button_width0, int h = button_height0);
    void isClicked()override;
    void funcLButtonUp()override;
    void funcLButtonDown()override;
private:
    IMAGE img;
};

