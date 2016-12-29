#include <GL/glut.h>
#include "yurigl.hxx"

namespace yuri {

      /*
      *タイマイベントハンドラを登録する関数
      *引数
      *1個目
      *関数ポインタ
      *２個目
      *ミリ秒でタイムリミットを設定
      *3個目
      *タイマーID
      *任意の数
      */
      void SetTimerFunction(void (*function)(int), int msec, int timerID){
            /*
            *登録
            */
            glutTimerFunc(msec, function, timerID);
      }

      /*
      *fpsからミリ秒を計算するinline関数
      */
      double FPS2MS(double fps){
            return 1000.0 / fps;
      }

}