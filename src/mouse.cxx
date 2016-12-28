#include <GL/glut.h>

namespace yuri {
      void SetDownLeftFunction(void (*func)(int x, int y)){
            
      }

      
      void MouseFunction(int button, int state, int x, int y){
            switch(button){
                  case GLUT_LEFT_BUTTON:
                        break;
                  case GLUT_MIDDLE_BUTTON:
                        break;
                  case GLUT_RIGHT_BUTTON:
                        break;
                  default:
                        break;
            }

            switch(state){
                  case GLUT_UP:
                        break;
                  case GLUT_DOWN:
                        break;
                  default:
                        break;
            }

      }
}