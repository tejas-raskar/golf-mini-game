#include "ball.h"
#include <raylib.h>
#include <iostream>

void Ball::setVelocity(float x, float y)
{
    velocity.x = x;
    velocity.y = y;
}

void Ball::setInitialMousePos(float x, float y)
{
    initialMousePos.x = x;
    initialMousePos.y = y;
}

void Ball::update()
{
    //Check Collision with the window
    if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0)
    {
        velocity.y *= -1;
    }
    if (position.x + radius >= GetScreenWidth() || position.x - radius <= 0)
    {
        velocity.x *= -1;
    }

    //Initial Mouse Position
    if (IsMouseButtonPressed(0))
    {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        setInitialMousePos(mouseX, mouseY);
    }

    //Final Mouse Position
    if (IsMouseButtonDown(0))
    {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        //Calculations of Velocity
        dx = mouseX - getInitialMousePos().x;
        dy = mouseY - getInitialMousePos().y;

        d = sqrt((dx * dx) + (dy * dy));

        velocity.x = dx / d * -5;
        velocity.y = dy / d * -5;
    }
    else
    {
        //Updating Position of the ball
        position.x += velocity.x;
        position.y += velocity.y;
    }
}