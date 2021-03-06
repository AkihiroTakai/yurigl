#include <GL/glut.h>
#include "yurigl.hxx"

namespace yuri {

      extern YURIGL_MANAGER *YuriGLManager;

      /*
      *Down系
      */
      void SetDownLeftFunction(void (*function)(int x, int y)){
            YuriGLManager->SetMouseActionHandler(YURIGL_LEFT_DOWN, function);
      }

      void SetDownRightFunction(void (*function)(int x, int y)){
            YuriGLManager->SetMouseActionHandler(YURIGL_RIGHT_DOWN, function);
      }

      void SetDownMiddleFunction(void (*function)(int x, int y)){
            YuriGLManager->SetMouseActionHandler(YURIGL_MIDDLE_DOWN, function);
      }

      /*
      *Up系
      */
      void SetUpLeftFunction(void (*function)(int x, int y)){
            YuriGLManager->SetMouseActionHandler(YURIGL_LEFT_UP, function);
      }

      void SetUpRightFunction(void (*function)(int x, int y)){
            YuriGLManager->SetMouseActionHandler(YURIGL_RIGHT_UP, function);
      }

      void SetUpMiddleFunction(void (*function)(int x, int y)){
            YuriGLManager->SetMouseActionHandler(YURIGL_MIDDLE_UP, function);
      }

      /*
      *マウスのイベントが発生したときに実行される関数
      */
      void MouseFunction(int button, int state, int x, int y){
            switch(state){
                  case GLUT_DOWN:
                        switch(button){
                              case GLUT_LEFT_BUTTON:
                                    YuriGLManager->CallMouseFunction(YURIGL_LEFT_DOWN, x, y);
                                    break;
                              case GLUT_RIGHT_BUTTON:
                                    YuriGLManager->CallMouseFunction(YURIGL_RIGHT_DOWN, x, y);
                                    break;
                              case GLUT_MIDDLE_BUTTON:
                                    YuriGLManager->CallMouseFunction(YURIGL_MIDDLE_DOWN, x, y);
                                    break;
                              default:
                                    break;
                        }
                  case GLUT_UP:
                        switch(button){
                              case GLUT_LEFT_BUTTON:
                                    YuriGLManager->CallMouseFunction(YURIGL_LEFT_UP, x, y);
                                    break;
                              case GLUT_RIGHT_BUTTON:
                                    YuriGLManager->CallMouseFunction(YURIGL_RIGHT_UP, x, y);
                                    break;
                              case GLUT_MIDDLE_BUTTON:
                                    YuriGLManager->CallMouseFunction(YURIGL_MIDDLE_UP, x, y);
                                    break;
                              default:
                                    break;
                        }
            }
      }

      /*
      *マウスがドラッグされたときに実行される関数
      */
      void SetMouseDraggedFunction(void (*function)(int x, int y)){
            glutMotionFunc(function);
      }
}