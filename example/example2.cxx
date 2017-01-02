#include <GL/glut.h>
#include "yurigl.hxx"

void display(){
    cv::Mat img = cv::imread("/home/Anne/Downloads/yuri.jpg");
    
    yuri::DrawCvMat(&img);
    
    yuri::ForceRedraw();
}

int main(int argc, char **argv){
    yuri::DisplaySetting(500, 500, 100, 100);
    yuri::Init(argc, argv);
    yuri::CreateWindow("window");
    yuri::SetRedrawFunction(display);
    yuri::MainLoop();
}