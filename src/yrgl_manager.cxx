#include "yurigl.hxx"

namespace yuri {

      /*
      *何もしない関数
      */
      void DoNothing(int x, int y);

      /*
      *コンストラクタ
      */
      YURIGL_MANAGER::YURIGL_MANAGER()
      : DisplayPosition(DEFAULT_DISPLAY_X, DEFAULT_DISPLAY_Y)
      {
            unsigned char c;
            width = DEFAULT_WINDOW_WIDTH;
            height = DEFAULT_WINDOW_HEIGHT;
            WindowName = "YuriGL";
            EventHandlerFlags = 0xffffffff;

            for(c = 0;c < 6;c++)
                  MouseActionHandlers[c] = DoNothing;
            
            for(c = 0;c < 128;c++)
                  KeyTable[c] = false;
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

      void YURIGL_MANAGER::SetMouseActionHandler(int index, void (*function)(int x, int y)){
            MouseActionHandlers[index] = function;
      }

      void YURIGL_MANAGER::CallMouseFunction(int index, int x, int y){
            MouseActionHandlers[index](x, y);
      }

      void DoNothing(int x, int y){}

}