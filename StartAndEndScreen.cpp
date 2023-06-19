

#include "raylib.h"

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;


int main(void)
{
   
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Causual Golf Game");

    GameScreen currentScreen = LOGO;

    // TODO: Initialize all required variables and load all required data here!

    int framesCounter = 0;          // Useful to count frames

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch(currentScreen)
        {
            case LOGO:
            {
             currentScreen = TITLE;
            } break;
            case TITLE:
            {
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = ENDING;
                }
            } break; 
            case ENDING:
            {
                
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = TITLE;
                }
            } break;
            default: break;
        }
        
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(currentScreen)
            {

                case TITLE:
                {
                   
                    DrawRectangle(0, 0, screenWidth, screenHeight, RAYWHITE);
                    DrawText("Casual Mini Golf Game", 180, 20, 40, DARKGREEN);
                    DrawText("Press Enter or Tap to Start Game ", 120, 150, 30, DARKGREEN);

                } break;
                
                //below gameplay case might not be used by us just leave it as a comment
               /* case GAMEPLAY:
                {
                   
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

                } break; */
                case ENDING:
                {
                
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("Congratulatons", 250, 20, 40, DARKBLUE);
                    DrawText("You Have Completed The Game", 100,100, 40, DARKBLUE);
                    DrawText(" ", 120, 220, 20, DARKBLUE);

                } break;
                default: break;
            }

        EndDrawing();
    }

    CloseWindow();        
   

    return 0;
}
