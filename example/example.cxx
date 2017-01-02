#include <GL/glut.h>
#include <iostream>
#include "yurigl.hxx"

#define ME_SIZE 10

void display(void){
      yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
      glutSolidCube(2);
}

void mouse(int x, int y){
      yuri::ForceRedraw();
      yuri::DrawLine(yuri::Point2DD(0, 0), yuri::Point2DD(x, y), yuri::RGBA(0, 0 ,0, 0));
}

void timer(int value){

      static int x, y;

      if(yuri::KeyPushed('s') && y < 500){
            yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
            yuri::DrawRect(yuri::Point2DD(x, y), yuri::Point2DD(x+ME_SIZE, y), yuri::Point2DD(x+ME_SIZE, y+ME_SIZE), yuri::Point2DD(x, y+ME_SIZE), yuri::RGBA(255, 255, 255, 255));
            y+=5;
      }else if(yuri::KeyPushed('w') && y > 0){
            yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
            yuri::DrawRect(yuri::Point2DD(x, y), yuri::Point2DD(x+ME_SIZE, y), yuri::Point2DD(x+ME_SIZE, y+ME_SIZE), yuri::Point2DD(x, y+ME_SIZE), yuri::RGBA(255, 255, 255, 255));
            y-=5;
      }else if(yuri::KeyPushed('d') && x < 500){
            yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
            yuri::DrawRect(yuri::Point2DD(x, y), yuri::Point2DD(x+ME_SIZE, y), yuri::Point2DD(x+ME_SIZE, y+ME_SIZE), yuri::Point2DD(x, y+ME_SIZE), yuri::RGBA(255, 255, 255, 255));
            x+=5;
      }else if(yuri::KeyPushed('a') && x > 0){
            yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
            yuri::DrawRect(yuri::Point2DD(x, y), yuri::Point2DD(x+ME_SIZE, y), yuri::Point2DD(x+ME_SIZE, y+ME_SIZE), yuri::Point2DD(x, y+ME_SIZE), yuri::RGBA(255, 255, 255, 255));
            x-=5;
      }

	yuri::ForceRedraw();
	yuri::SetTimerFunction(timer, yuri::FPS2MS(60), 1);
}


int main(int argc, char *argv[]){
      yuri::DisplaySetting(500, 500, 100, 100);
      yuri::Init(argc, argv);
      yuri::CreateWindow("window");
      yuri::SetRedrawFunction(display);
      yuri::SetDownLeftFunction(mouse);
      yuri::SetMouseDraggedFunction(mouse);
      yuri::SetTimerFunction(timer, yuri::FPS2MS(60), 1);
      yuri::MainLoop();

      return 0;
}
