#include "yurigl.h"

namespace yuri {
      RGBA::RGBA(double r, double g, double b, double a){
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
      }
      double RGBA::getNDRED(){
            return this->r / 255;
      }
      double RGBA::getNDGREEN(){
            return this->g / 255;
      }
      double RGBA::getNDBLUE(){
            return this->b / 255;
      }
      double RGBA::getNDALPHA(){
            return this->a / 255;
      }
}