#include <GL/glut.h>

namespace yuri {
      void SetDownLeftFunction(void (*func)(int x, int y)){

      }

      
      void MouseFunction(int button, int state, int x, int y){
            switch(state){
                  case GLUT_UP:
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
                  case GLUT_DOWN:
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
            }
      }
}