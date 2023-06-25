
#include "ball.cpp"
#include "Screen.cpp"
#include "arrow.cpp"
#include "cup.h"
// #include "Obstacles.cpp"
#include "Background.cpp"
#include "ScoreBoard.cpp"
#include <raylib.h>
#include <iostream>

namespace Game {

    const int screenWidth = 800;
    const int screenHeight = 450;

    typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING, WINING } GameScreen;
    GameScreen currentScreen=LOGO;

    bool gameOver = false;

    Obstacle Obs;
    Ball ball;
    UI ui;
    Arrow arrow;
    Cup cup;
    backgroundMain bg;
    ScoreBoard sb;

    void init();
    void loop();
    void end();

}

void Game::init(){
    InitWindow(screenWidth, screenHeight, "Golf v1.0");

    bg.ImportTexture();

    Obs.LoadObs();
    arrow.TexLoad();
    ball.LoadBall();
    cup.LoadImage();

    cup.radius = 10;
    cup.cupPosition.x = (float)screenWidth / 20;
    cup.cupPosition.y = (float)screenHeight / 20;

    ball.GetInput(Obs);
    ball.radius = 10;
    ball.position.x = (float)screenWidth / 2;
    ball.position.y = (float)screenHeight / 2;
    SetTargetFPS(60);

}

void Game::loop(){
    while (!gameOver){

        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(currentScreen)
            {

                case LOGO:
                {
                    currentScreen = TITLE;

                } break;
                case TITLE:
                {

                    ui.TitleScreen();
                    if (IsKeyPressed(KEY_ENTER))
                        currentScreen = GAMEPLAY;
                } break;

                case GAMEPLAY:
                {

                    arrow.ArrowCor(ball.position.x, ball.position.y);
                    BeginDrawing();

                        ClearBackground(RAYWHITE);

                        bg.DrawTexture();

                        ball.update();
                        // DrawCircleV(cup.cupPosition, cup.radius, GRAY);
                        arrow.Draw();
                        ball.draw();
                        Obs.DrawObs();
                        cup.CupDraw();

                        if (cup.checkWin(ball.position, cup))
                        {
                            ui.GetScore(sb.Score);
                            std::cout << sb.Score;
                            currentScreen = ENDING;
                        }

                    EndDrawing();
                    if (IsKeyPressed(KEY_ESCAPE))
                    {
                        currentScreen = ENDING;

                    }
                } break;

                case WINING : {
                    ui.WiningScreen();
                    if (IsKeyPressed(KEY_ENTER))
                        gameOver = true;
                } break;

                case ENDING:
                {
                    ui.EndingScreen();
                    if (IsKeyPressed(KEY_ENTER))
                    {
                        currentScreen = WINING;
                    }

                } break;

                default: break;
            }

        EndDrawing();
    }
}

void Game::end(){
    bg.UnloadTexture();
    Obs.UnloadObs();
    arrow.TextUnload();
    CloseWindow();
}
