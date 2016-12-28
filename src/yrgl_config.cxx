#include <GL/glut.h>
#include "yurigl.hxx"

namespace yuri {

      /*
      *キーボード入力の情報をリアルタイムで
      */
      void ConfigKeyboardRealTime(bool flag){
            if(flag){
                  glutIgnoreKeyRepeat(GL_TRUE);
            }else{
                  glutIgnoreKeyRepeat(GL_FALSE);
            }
      }
};