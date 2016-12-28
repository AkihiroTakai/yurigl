#include <GL/glut.h>
#include "yurigl.hxx"

namespace yuri {

      /*
      *SetKeyboardFunction関数
      *キーボードイベントが来たときに実行される関数を設定する関数
      *引数
      *=>関数ポインタ
      */
      void SetKeyboardFunction(void (*function)(unsigned char key, int x, int y)){
            /*
            *関数ポインタを渡す
            */
            glutKeyboardFunc(function);
      }

}