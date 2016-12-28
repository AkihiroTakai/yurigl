#include <GL/glut.h>
#include "yurigl.hxx"

namespace yuri {

      extern YURIGL_MANAGER *YuriGLManager;

      void SetDownLeftFunction(void (*function)(int x, int y)){
            YuriGLManager->SetMouseActionHandler(YURIGL_LEFT_DOWN, function);
      }

      
      void MouseFunction(int button, int state, int x, int y){
            switch(state){
                  case GLUT_DOWN:
                        switch(button){
                              case GLUT_LEFT_BUTTON:
                                    break;
                              case GLUT_RIGHT_BUTTON:
                                    break;
                              case GLUT_MIDDLE_BUTTON:
                                    break;
                              default:
                                    break;
                        }
                  case GLUT_UP:
                        switch(button){
                              case GLUT_LEFT_BUTTON:
                                    break;
                              case GLUT_RIGHT_BUTTON:
                                    break;
                              case GLUT_MIDDLE_BUTTON:
                                    break;
                              default:
                                    break;
                        }
            }
      }
}