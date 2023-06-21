#include <raylib.h>
#include <raymath.h>
#include "Init.h"

int main(void)
{
    InitWindow(400, 224, "Golf v1.0");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
        
}
