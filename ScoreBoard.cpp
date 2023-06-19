#include "raylib.h"

class ScoreBoard{
   GolfBall ball; Hole hole;
   Vector2 ballPos, holePos;
   int score;
 public:
 
   ScoreBoard(GolfBall tempb, Hole temph){
       ball = tempb;
       hole = temph;
   }
   
   void GetPositions(){
       ballPos = ball.CurrentPos;
       holePos = hole.CurrentPos;
   }
   void CheckIfIn(){
       if (abs(holePos - ballPos) <= hole.radii) 
           score++;
   }
   int ReturnScoreValue(){
       return score;
   }
};
