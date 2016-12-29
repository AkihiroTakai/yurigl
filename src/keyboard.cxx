#include <GL/glut.h>
#include "yurigl.hxx"

namespace yuri {
      extern YURIGL_MANAGER *YuriGLManager;
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

      /*
      *デフォルトのキーボードダウンイベントハンドラ
      */
      void DefaultKeyboardDownFunction(unsigned char key, int x, int y){
            /*
            *押されたキーのキーテーブルをtrueに設定
            */
            YuriGLManager->SetKeyTable(key, true);
      }

      /*
      *デフォルトのキーボードアップイベントハンドラ
      */
      void DefaultKeyboardUpFunction(unsigned char key, int x, int y){
            /*
            *戻したキーのキーテーブルをfalseに設定
            */
            YuriGLManager->SetKeyTable(key, false);
      }

}