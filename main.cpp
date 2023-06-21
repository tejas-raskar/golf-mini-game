#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>

#include "ball.h"
#include "cup.h"

Ball ball;
Cup cup;

struct obstacle
{
    Rectangle rect;
    Color color;
};

Vector2 Reflect(Vector2 v, Vector2 normal)
{
    return Vector2Subtract(v, Vector2Scale(normal, 2 * Vector2DotProduct(v, normal)));
}

int main(void)
{
    const int screenWidth = 240;
    const int screenHeight = 480;
    InitWindow(screenWidth, screenHeight, "Golf v2.1");
    SetTargetFPS(60);

    std::vector<obstacle> obstacles;
    obstacles.push_back({{50, 350, 64, 64}, BLUE});
    obstacles.push_back({{150, 150, 64, 64}, GREEN});
    obstacles.push_back({{40, 20, 64, 64}, RED});

    cup.radius = 10;
    cup.cupPosition.x = screenWidth / 4;
    cup.cupPosition.y = screenHeight / 4;

    ball.radius = 10;
    ball.position.x = screenWidth / 2;
    ball.position.y = screenHeight / 2;

    Image ob = LoadImage("assets/tile64_dark.png");
    Texture2D obstacle64 = LoadTextureFromImage(ob);
    UnloadImage(ob);

    Image bl = LoadImage("assets/ball.png");
    Texture2D ball32 = LoadTextureFromImage(bl);
    UnloadImage(bl);

    Image background = LoadImage("assets/bg.png");
    Texture2D bg = LoadTextureFromImage(background);
    UnloadImage(background);

    Image hole = LoadImage("assets/hole.png");
    Texture2D hl = LoadTextureFromImage(hole);
    UnloadImage(hole);

    while (!WindowShouldClose())
    {
        for (const auto obstacle : obstacles)
        {
            if (CheckCollisionCircleRec(ball.position, ball.radius, obstacle.rect))
            {
                // Calculate collision normal
                Vector2 collisionNormal = {0, 0};
                if (ball.position.x < obstacle.rect.x)
                {
                    collisionNormal.x = -1;
                }
                else if (ball.position.x > obstacle.rect.x + obstacle.rect.width)
                {
                    collisionNormal.x = 1;
                }
                if (ball.position.y < obstacle.rect.y)
                {
                    collisionNormal.y = -1;
                }
                else if (ball.position.y > obstacle.rect.y + obstacle.rect.height)
                {
                    collisionNormal.y = 1;
                }

                // Reflect ball velocity using the collision normal
                ball.velocity = Reflect(ball.velocity, collisionNormal);
            }
        };

        BeginDrawing();

        DrawTexture(bg, 0, 0 , WHITE);

        ball.update();

        ClearBackground(BLACK);

        DrawTextureV(hl, cup.cupPosition, WHITE);

        //ball.draw();
        DrawTextureV(ball32, ball.position, WHITE);

        // Drawing the Obstacles
        for (const auto obstacle : obstacles)
        {
            DrawTexture(obstacle64, obstacle.rect.x, obstacle.rect.y, WHITE);
        }

        if (cup.checkWin(ball.position, cup))
        {
            std::cout << "Congratulations! You have won!" << std::endl;
            break;
        }

        EndDrawing();
    }
    UnloadTexture(obstacle64);
    UnloadTexture(ball32);
    UnloadTexture(bg);
    UnloadTexture(hl);


    CloseWindow();

    return 0;
}