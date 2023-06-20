#include <raylib.h>
#include <raymath.h>
#include <iostream>

#include "ball.h"
#include "cup.h"

Ball ball;
Cup cup;

int main(void)
{
    const int screenWidth = 640;
    const int screenHeight = 480;
    InitWindow(screenWidth, screenHeight, "Golf v1.1");
    SetTargetFPS(60);

    cup.radius = 10;
    cup.cupPosition.x = screenWidth / 4;
    cup.cupPosition.y = screenHeight / 4;

    ball.radius = 7;
    ball.position.x = screenWidth / 2;
    ball.position.y = screenHeight / 2;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ball.update();

        ClearBackground(BLACK);

        DrawCircleV(cup.cupPosition, cup.radius, GRAY);

        ball.draw();

        if (cup.checkWin(ball.position, cup))
        {
            std::cout << "Congratulations! You have won!" << std:: endl;
            break;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}