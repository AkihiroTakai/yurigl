#include <GL/glut.h>
#include <iostream>
#include "yurigl.hxx"

void display(void){
      yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
      yuri::DrawCircle(yuri::Point2DD(200, 200), 100, yuri::RGBA(255, 255, 255, 255));
}

void mouse(int x, int y){
      yuri::FillBackGround(yuri::RGBA(255, 255, 255, 0));
      yuri::DrawLine(yuri::Point2DD(0, 0), yuri::Point2DD(x, y), yuri::RGBA(0, 0 ,0, 0));
}

void key(unsigned char key, int x, int y){
      static int i;
      yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
      yuri::DrawRect(yuri::Point2DD(i, 0), yuri::Point2DD(i+50, 0), yuri::Point2DD(i+50, 50), yuri::Point2DD(i, 50), yuri::RGBA(255, 255, 255, 255));
      i++;
}

int main(int argc, char *argv[]){
      yuri::DisplaySetting(500, 500, 100, 100);
      yuri::Init(argc, argv);
      yuri::CreateWindow("window");
      yuri::SetRedrawFunction(display);
      yuri::SetDownLeftFunction(mouse);
      yuri::SetKeyboardFunction(key);
      yuri::SetMouseDraggedFunction(mouse);
      yuri::MainLoop();
      return 0;
}
