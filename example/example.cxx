#include <GL/glut.h>
#include <iostream>
#include "yurigl.hxx"

void display(void){
      yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
      yuri::DrawCircle(yuri::Point2DD(200, 200), 100, yuri::RGBA(255, 255, 255, 255));
}

void mouse(int x, int y){
      std::cout << "YURIGL" << std::endl;
}

int main(int argc, char *argv[]){
      yuri::DisplaySetting(500, 500, 100, 100);
      yuri::Init(argc, argv);
      yuri::CreateWindow("window");
      yuri::SetRedrawFunction(display);
      yuri::SetDownLeftFunction(mouse);
      yuri::MainLoop();
      return 0;
}