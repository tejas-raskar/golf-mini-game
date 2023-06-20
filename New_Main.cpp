#include <raylib.h>
#include <raymath.h>
#include "Obstacle.cpp"


int main(void){

    Obstacle Os;
    const int screenWidth = 800;
    const int screenHeight= 450;

      InitWindow( screenWidth, screenHeight, "Golf v1.0");
    
    Texture2D background = LoadTexture("bg.png");
    Vector2 backgroundPos{0,0};
    Os.LoadObs();
    //Texture2D obstacle = LoadTexture("tile64_light.png");
    //Texture2D obstacle1 = LoadTexture("tile32_light.png");
    
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            for(int y=0; y < screenHeight; y += background.height)
            {
                for(int x = 0; x < screenWidth; x += background.width)
                {
                    DrawTexture(background,x,y,WHITE);
                    Os.DrawObs();
                    //DrawTexture(obstacle,400,500,WHITE);
                    //DrawTexture
                }
            }
            
            
            DrawCircle(400,300,15,BLACK);
        EndDrawing();
    }
    UnloadTexture(background);
    Os.UnloadObs();
    //UnloadTexture(obstacle);

    CloseWindow();

    return 0;
        
}
