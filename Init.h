#include <raylib>

class GolfBall{
  
  public:
     GolfBall();
     ~GolfBall();
};

GolfBall::GolfBall(){
    SetTargetFPS(60);
    InitWindow(800, 600, "Golf");
}
