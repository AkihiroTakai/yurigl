#include <GL/glut.h>
#include <opencv2/opencv.hpp>
#include "yurigl.hxx"

void display(){
    cv::Mat img = cv::imread("/home/Anne/Downloads/yuri.jpg");
    
    cv::flip(img, img, 0);
    cv::cvtColor(img, img, CV_BGR2RGB);

    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(img.cols, img.rows,
               GL_RGB, GL_UNSIGNED_BYTE, img.data);
    yuri::ForceRedraw();
}

int main(int argc, char **argv){
    yuri::DisplaySetting(500, 500, 100, 100);
    yuri::Init(argc, argv);
    yuri::CreateWindow("window");
    yuri::SetRedrawFunction(display);
    yuri::MainLoop();
}