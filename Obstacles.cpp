#include <raylib.h>
#include <string>

class Obstacle{
    Texture2D Obs, Obs1, Obs2, Obs3;
    Vector2 PosObs, PosObs1, PosObs2, PosObs3;
  public:
    void LoadObs(){
        Obs = LoadTexture("tile32_dark.png");
        PosObs.x = GetRandomValue(0, 800-32);
        PosObs.y = GetRandomValue(0, 450-35);
        
        Obs1 = LoadTexture("tile32_light.png");
        PosObs1.x = GetRandomValue(0,800-32);
        PosObs1.y = GetRandomValue(0,450-35);
        
        Obs2 = LoadTexture("tile64_dark.png");
        PosObs2.x = GetRandomValue(0,800-64);
        PosObs2.y = GetRandomValue(0,450-67);
        
        Obs3 = LoadTexture("tile64_light.png");
        PosObs3.x = GetRandomValue(0,800-64);
        PosObs3.y = GetRandomValue(0,450-67);
        
    }
    void DrawObs(){
            DrawTexture(Obs,PosObs.x,PosObs.y,WHITE);
            DrawTexture(Obs1,PosObs1.x,PosObs1.y,WHITE);
            DrawTexture(Obs2,PosObs2.x,PosObs2.y,WHITE);
            DrawTexture(Obs3,PosObs3.x,PosObs3.y,WHITE);
            
    }
    void UnloadObs(){
            UnloadTexture(Obs);
            UnloadTexture(Obs1);
            UnloadTexture(Obs2);
            UnloadTexture(Obs3);
    }
};
