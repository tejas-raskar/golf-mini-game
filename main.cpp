#include <raylib.h>
#include <raymath.h>
#include <iostream>

#include "ball.h"

Ball ball;

int main(void)
{
    const int screenWidth = 640;
    const int screenHeight = 480;
    InitWindow(screenWidth, screenHeight, "Golf v1.0");
    SetTargetFPS(60);

    ball.position.x = (float) screenWidth / 2;
    ball.position.y = (float) screenHeight / 2;


    while (!WindowShouldClose())
    {
        BeginDrawing();

             ball.update();
             ClearBackground(BLACK);
             ball.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
