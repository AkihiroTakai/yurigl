#ifndef POINT_H
#define POINT_H

#include "yurigl.h"

namespace yuri {
      template <typename Type>
      class Point2D {
            Type x;
            Type y;
            public:
            Point2D(Type x, Type y){
                  this->x = x;
                  this->y = y;
            }
            Type getX(){
                  return x;
            }
            Type getY(){
                  return y;
            }
            void setX(Type x){
                  this->x = x;
            }
            void setY(Type y){
                  this->y = y;
            }

            Type ComputeNDCSX(double width){
                  return ((this->x * 2) / width) - 1.0;
            }

            Type ComputeNDCSY(double height){
                  return -(((this->y * 2) / height) - 1.0);
            }
      };

}

#endif