#pragma once
#include "PushButton.h"
class IntroButton :
    public PushButton
{
public:
    IntroButton(const string text = "”Œœ∑ΩÈ…‹", int x = 0, int y = 0, int w = button_width0, int h = button_height0);
    void isClicked()override;
    void funcLButtonUp()override;
    void funcLButtonDown()override;
};

