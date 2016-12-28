#include "yurigl.hxx"

namespace yuri {
      /*
      *コンストラクタ
      */
      YURIGL_MANAGER::YURIGL_MANAGER()
      : DisplayPosition(DEFAULT_DISPLAY_X, DEFAULT_DISPLAY_Y)
      {
            width = DEFAULT_WINDOW_WIDTH;
            height = DEFAULT_WINDOW_HEIGHT;
            WindowName = "YuriGL";
      }

      double YURIGL_MANAGER::getWidth(){
            return this->width;
      }
      
      double YURIGL_MANAGER::getHeight(){
            return this->height;
      }

      std::string YURIGL_MANAGER::getWindowName(){
            return WindowName;
      }

      double YURIGL_MANAGER::NDeviceCSX(double width){
            return width / this->width;
      }

      double YURIGL_MANAGER::NDeviceCSY(double height){
            return height / this->height;
      }

}