#include <raylib.h>
#include <iostream>

using namespace std;

class Ball{
    public:
    float x, y;
    int speedx,speedy;
    int radius;

    void Draw(){
        //Cirlce
    DrawCircle(x,y,radius, WHITE);

    };

    void Update(){
        x += speedx;
        y += speedy;
    };
};

Ball ball;
int main(){

    Color green= {20,160,133,255};

    cout << "starting the gem";
    const int res_width = 1280;
    const int res_height = 800; 

   InitWindow(res_width, res_height, "nyoba game di raylib");
   SetTargetFPS(60);

   ball.radius = 20;
   ball.x = res_width/2;
   ball.y = res_height/2;
   ball.speedx = 7;
   ball.speedy = 7;

   while(WindowShouldClose() == false){
    BeginDrawing();

    
    
    ball.Update();
    //rectanggle
    DrawRectangle(0,res_height/2-60,25, 120, WHITE);
    DrawRectangle(res_width - 20, res_height/2-60,25,120,WHITE);


    //board
    DrawLine(res_width/2,0,res_width/2,res_height,WHITE);
    ball.Draw();

    EndDrawing();

   }

  
   




   CloseWindow();
    return 0;
}