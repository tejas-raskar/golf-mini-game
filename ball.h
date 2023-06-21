#pragma once
#include <raylib.h>
#include <raymath.h>



class Ball
{
private:
    Vector2 initialMousePos, finalMousePos, displacement;
    float magnitude, deltaTime, timeOfFlight;
    float friction = 0.1f;

public:
    Vector2 position, velocity;
    int radius;

    void draw()
    {
        //DrawTextureV(ballimg, position, WHITE);
    }

    Vector2 getInitialMousePos()
    {
        return initialMousePos;
    }

    void update();
    void setInitialMousePos(float x, float y);
    void setFinalMousePos(float x, float y);

    float getDistance(Vector2 a, Vector2 b)
    {
        return sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
    }
};