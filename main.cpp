#include <raylib.h>
#include <raymath.h>
#include <iostream>
#define MAX_LINE_LENGTH 200


#include "ball.h"
#include "cup.h"
#include "arrow.h"





Ball ball;
Cup cup;
Arrow arrow;

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
    
    arrow.TexLoad();
   
    while (!WindowShouldClose())
    {
        arrow.ArrowCor(ball.position.x, ball.position.y);

        BeginDrawing();

        ClearBackground(SKYBLUE);
        arrow.Draw();
        
        ball.update();
        

        DrawCircleV(cup.cupPosition, cup.radius, GRAY);

        ball.draw();

        if (cup.checkWin(ball.position, cup))
        {
            std::cout << "Congratulations! You have won!" << std:: endl;
            break;
        }

        EndDrawing();
    }
   
    arrow.TextUnload();
    CloseWindow();

    return 0;

}
