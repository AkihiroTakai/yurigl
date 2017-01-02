#include <opencv2/opencv.hpp>
#include <GL/glut.h>

namespace yuri {
void DrawCvMat(cv::Mat *img){
    cv::flip(*img, *img, 0);
    cv::cvtColor(*img, *img, CV_BGR2RGB);

    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(img->cols, img->rows,
               GL_RGB, GL_UNSIGNED_BYTE, img->data);
}
}