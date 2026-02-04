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
        //y+radius =bottom edge || y-radius top edge
        if(y + radius >= GetScreenHeight() || y - radius <= 0){
            speedy *= -1;
        }//x+radius = right edge || y-radius left edge
        if( x+ radius >= GetScreenWidth() || x - radius <= 0){
            speedx *= -1;
        }
    };
};

class Padle{
    public:
    float x,y;
    float widht;
    float height; 
    float speed; 

    void Draw(){

         DrawRectangle(x,y,widht,height, GREEN);

    };

    void Update(){
        if(IsKeyDown(KEY_UP)){
            y = y - speed;
        }
        if(IsKeyDown(KEY_DOWN)){
            y = y + speed;
        }   

        if(y <= 0 ){
            y = 0;
        }
        if(y + height >= GetScreenHeight()){
            y = GetScreenHeight() - height;
        }
    }
};

class CpuPadle : public Padle{
    public:
    void Update(int ball_y){
        if(y + height/2 > ball_y){
            y = y - speed;
        }
        if(y + height/2 <= ball_y){
            y = y + speed;
        }   
        
    }
};

Ball ball;
Padle player;
CpuPadle cpu;
int main(){

    Color green = {20,160,133,255};

    cout << "starting the gem";
    const int res_width = 1280;
    const int res_height = 800; 

   InitWindow(res_width, res_height, "nyoba game di raylib");
   SetTargetFPS(60);


   //ball
   ball.radius = 20;
   ball.x = res_width/2;
   ball.y = res_height/2;
   ball.speedx = 7;
   ball.speedy = 7;
    //padle player
    player.widht = 25;
    player.height = 120;
    player.x = res_width - player.widht - 10;
    player.y =  res_height/2 - player.height/2;
    player.speed = 6;

    //cpu padle
    cpu.height = 120;
    cpu.widht = 25;
    cpu.x = 10;
    cpu.y = GetScreenHeight()/2 - cpu.height/2;
    cpu.speed = 6; 

   while(WindowShouldClose() == false){
    BeginDrawing();

    
    //update
    ball.Update();
    player.Update();
    cpu.Update(ball.y);
    ClearBackground(BLACK);
    
   


    //board
    DrawLine(res_width/2,0,res_width/2,res_height,WHITE);
    ball.Draw();
    player.Draw();
    cpu.Draw();

    EndDrawing();

   }

  
   




   CloseWindow();
    return 0;
}