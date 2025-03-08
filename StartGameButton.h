#pragma once
#include "PushButton.h"
class StartGameButton :
    public PushButton
{
public:
    StartGameButton(const string text = "¿ªÊ¼ÓÎÏ·", int x = 0, int y = 0, int w = button_width0, int h = button_height0);
    void isClicked()override;
    void funcLButtonUp()override;
    void funcLButtonDown()override;
    bool getStarting();
private:
    bool isStarting = 0;
};

