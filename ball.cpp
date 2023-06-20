#include "ball.h"
#include <raylib.h>
#include <iostream>

void Ball::setInitialMousePos(float x, float y)
{
    initialMousePos.x = x;
    initialMousePos.y = y;
}

void Ball::setFinalMousePos(float x, float y)
{
    finalMousePos.x = x;
    finalMousePos.y = y;
}

void Ball::update()
{
    // Check Collision with the window
    if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0)
    {
        velocity.y *= -1;
    }
    if (position.x + radius >= GetScreenWidth() || position.x - radius <= 0)
    {
        velocity.x *= -1;
    }

    // Initial Mouse Position
    if (IsMouseButtonPressed(0))
    {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        setInitialMousePos(mouseX, mouseY);
    }

    if (IsMouseButtonReleased(0))
    {
        // Final Mouse Position
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        setFinalMousePos(mouseX, mouseY);

        // Displacement Vector
        displacement = {finalMousePos.x - initialMousePos.x, finalMousePos.y - initialMousePos.y};

        // Magnitude
        magnitude = Vector2Length(displacement);

        // Time Of Flight
        timeOfFlight = magnitude / getDistance(finalMousePos, initialMousePos);

        // Velocity
        velocity.x = (displacement.x / timeOfFlight) * -1;
        velocity.y = (displacement.y / timeOfFlight) * -1;

        // Time variables
        deltaTime = GetFrameTime() * 5.0f;
    }
    else
    {
        // Updating Position of the ball
        position.x += velocity.x * deltaTime;
        position.y += velocity.y * deltaTime;

        // Decreasing Velocity based on the friction and the time elapsed
        velocity.x *= (1.0f - friction * deltaTime);
        velocity.y *= (1.0f - friction * deltaTime);
    }
}