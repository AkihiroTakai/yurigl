#include <GL/glut.h>
#include <iostream>
#include "yurigl.hxx"

void display(void){
      yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
}

void mouse(int x, int y){
      yuri::ForceRedraw();
      yuri::DrawLine(yuri::Point2DD(0, 0), yuri::Point2DD(x, y), yuri::RGBA(0, 0 ,0, 0));
}

void timer(int value){

      static int xx, yy;

      if(yuri::KeyPushed('s')){
            yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
            yuri::DrawRect(yuri::Point2DD(xx, yy), yuri::Point2DD(xx+50, yy), yuri::Point2DD(xx+50, yy+50), yuri::Point2DD(xx, yy+50), yuri::RGBA(255, 255, 255, 255));
            yy+=5;
      }else if(yuri::KeyPushed('w')){
            yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
            yuri::DrawRect(yuri::Point2DD(xx, yy), yuri::Point2DD(xx+50, yy), yuri::Point2DD(xx+50, yy+50), yuri::Point2DD(xx, yy+50), yuri::RGBA(255, 255, 255, 255));
            yy-=5;
      }else if(yuri::KeyPushed('d')){
            yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
            yuri::DrawRect(yuri::Point2DD(xx, yy), yuri::Point2DD(xx+50, yy), yuri::Point2DD(xx+50, yy+50), yuri::Point2DD(xx, yy+50), yuri::RGBA(255, 255, 255, 255));
            xx+=5;
      }else if(yuri::KeyPushed('a')){
            yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
            yuri::DrawRect(yuri::Point2DD(xx, yy), yuri::Point2DD(xx+50, yy), yuri::Point2DD(xx+50, yy+50), yuri::Point2DD(xx, yy+50), yuri::RGBA(255, 255, 255, 255));
            xx-=5;
      }

	yuri::ForceRedraw();
	glutTimerFunc(50 , timer , 0);
}


int main(int argc, char *argv[]){
      yuri::DisplaySetting(500, 500, 100, 100);
      yuri::Init(argc, argv);
      yuri::CreateWindow("window");
      yuri::SetRedrawFunction(display);
      yuri::SetDownLeftFunction(mouse);
      yuri::SetMouseDraggedFunction(mouse);
      glutTimerFunc(100 , timer , 0);
      yuri::MainLoop();
      return 0;
}
