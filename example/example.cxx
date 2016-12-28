#include <GL/glut.h>
#include <string>
#include "yurigl.h"

void display(void){
      yuri::FillBackGround(yuri::RGBA(0, 0, 0, 0));
      yuri::HitDot(yuri::Point2D<double>(200, 200), yuri::RGBA(0, 0, 255, 255));
      yuri::DrawLine(yuri::Point2D<double>(100, 100), yuri::Point2D<double>(200, 200), yuri::RGBA(0, 0, 255, 255));
      yuri::DrawTriangle(yuri::Point2D<double>(100, 100), yuri::Point2D<double>(100, 200), yuri::Point2D<double>(200, 200), yuri::RGBA(0, 0, 255, 255));
      yuri::DrawRect(yuri::Point2D<double>(100, 100), yuri::Point2D<double>(200, 100), yuri::Point2D<double>(200, 200), yuri::Point2D<double>(100, 200), yuri::RGBA(0, 0, 255, 255));
}

int main(int argc, char *argv[]){
      yuri::DisplaySetting(500, 500, 100, 100);
      yuri::Init(argc, argv);
      yuri::CreateWindow("window");
      yuri::SetRedrawFunction(display);
      yuri::MainLoop();
      return 0;
}