#pragma once
#include <raylib.h>
#include <raymath.h>
#include <iostream>

#include "ball.h"

class Cup
{
    private:
    bool win;

    public:
    Vector2 cupPosition;
    int radius;

    bool checkWin(Vector2 ballPos, Cup cup)
    {
        float distance = Vector2Distance(ballPos, cup.cupPosition);
        return distance < cup.radius;
    }
};
