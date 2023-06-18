#pragma once
#include <raylib.h>
#include <raymath.h>

class Ball
{
private:
    Vector2 initialMousePos;
    float friction = 0.01;
    float dx, dy, d;

public:
    Vector2 velocity;
    Vector2 position;
    int radius;

    void draw()
    {
        DrawCircleV(position, radius, WHITE);
    }

    Vector2 getVelocity()
    {
        return velocity;
    }

    Vector2 getInitialMousePos()
    {
        return initialMousePos;
    }

    void update();
    void setInitialMousePos(float x, float y);
    void setVelocity(float x, float y);
};