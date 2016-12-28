#ifndef POINT_H
#define POINT_H

#include "yurigl.h"

namespace yuri {

      class Point2DD {
            double x;
            double y;
            public:
            Point2DD(double x, double y){
                  this->x = x;
                  this->y = y;
            }
            double getX(){
                  return x;
            }
            double getY(){
                  return y;
            }
            void setX(double x){
                  this->x = x;
            }
            void setY(double y){
                  this->y = y;
            }

            double ComputeNDCSX(double width){
                  return ((this->x * 2) / width) - 1.0;
            }

            double ComputeNDCSY(double height){
                  return -(((this->y * 2) / height) - 1.0);
            }
      };

}

#endif