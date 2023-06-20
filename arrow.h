#include <raylib.h>
#include <raymath.h>
#include <iostream>
#define MAX_LINE_LENGTH 200


#include "ball.h"
#include "cup.h"
//#include "arrow.h"



class Arrow
{
   public:
    Vector2 startPosition, endPosition, arrowhead, lineDirection, direction;
    Vector2 lineVector, pivot, currentMousePosition;
    bool isDragging;
    Texture2D texture2;
    float arrowLength, rotation, lineLength;
    Rectangle sourceRec, destRec;
    NPatchInfo nPatchInfo;
   
    void TexLoad(){
    texture2 = LoadTexture("assets/point.png");
    }
    void ArrowCor(float x, float y)
    {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            startPosition = {x, y};
            isDragging = true;
        }
        else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            endPosition = GetMousePosition();
            isDragging = false;
        }

        if (isDragging)
        {
            Vector2 currentMousePosition = GetMousePosition();
            Vector2 lineVector = Vector2Subtract(currentMousePosition, startPosition);
            Vector2 lineDirection = Vector2Normalize(lineVector);
            lineLength = Vector2Length(lineVector);

            if (lineLength > MAX_LINE_LENGTH)
            {
                endPosition = Vector2Add(startPosition, Vector2Scale(lineDirection, MAX_LINE_LENGTH));
                arrowhead = endPosition;
            }
            else
            {
                endPosition = currentMousePosition;
                arrowhead = endPosition;
            }
        }

        arrowLength = Vector2Length(Vector2Subtract(startPosition, arrowhead));
        Vector2 direction = Vector2Subtract(arrowhead, startPosition);
        rotation = (atan2f(direction.y, direction.x) * RAD2DEG) - 90;
       // Define the source rectangle
        sourceRec ={ 0, 0, static_cast<float>(texture2.width), static_cast<float>(texture2.height) };
        //Npatch
         nPatchInfo = { sourceRec, 0, 32, 0, 32, NPATCH_THREE_PATCH_VERTICAL};

        //DestRec
         destRec = {startPosition.x, startPosition.y, 25, arrowLength};

         pivot = {static_cast<float>(texture2.width) / 2, static_cast<float>(texture2.height )/ 2 };
    }
    void Draw()
    {
    if (isDragging)
        {
            DrawTextureNPatch(texture2, nPatchInfo, destRec, pivot, rotation, WHITE );
        }
    }
    void TextUnload(){
        UnloadTexture(texture2);
    }
};