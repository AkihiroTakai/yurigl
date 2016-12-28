#include <GL/glut.h>
#include <string>
#include "yurigl.hxx"

namespace yuri {

      void DefaultResize(int width, int height);
      void MouseFunction(int button, int state, int x, int y);

      /*
      *YuriGL管理クラス
      */
      YURIGL_MANAGER *YuriGLManager;

      /*
      *DisplaySetting関数
      *ウィンドウのサイズとかディスプレイ上の表示場所を設定する関数
      */
      void DisplaySetting(int width, int height, int display_x, int display_y){
            /*
            *ウィンドウのサイズを設定
            */
            glutInitWindowSize(width, height);
            /*
            *ウィンドウの表示位置を設定
            */
            glutInitWindowPosition(display_x, display_y);
      }

      /*
      *Init関数
      *YuriGLを初期化する関数
      */
      void Init(int argc, char *argv[]){
            /*
            *YuriGL管理構造体を確保(初期化)
            */
            YuriGLManager = new YURIGL_MANAGER();
            /*
            *内部のGLUTを初期化
            */
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_RGBA);     
      }

      /*
      *CreateWindow関数
      *ウィンドウを生成する関数
      *引数
      *std::string name
      *=>ウィンドウの名前
      */
      void CreateWindow(std::string name){
            /*
            *GLUTの関数でウィンドウを生成
            */
            glutCreateWindow(name.c_str());
            /*
            *デフォルトのウィンドウの背景
            *白(RGBA 255 255 255 255)
            */
            glClearColor(1.0, 1.0, 1.0, 1.0);
      }

      /*
      *WindowName関数
      *ウィンドウの名前を設定する関数
      *引数
      *std::string name
      *=>ウィンドウの名前
      */
      void WindowName(std::string name){
            /*
            *ウィンドウの名前を設定
            */
            glutSetWindowTitle(name.c_str());
      }
      /*
      *SetRedrawFunction関数
      *画面に再描画指示が来たときに実行する関数を設定する関数
      *引数
      *=>関数ポインタ
      */
      void SetRedrawFunction(void (*func)(void)){
            /*
            *関数ポインタを渡す
            */
            glutDisplayFunc(func);
      }
      
      /*
      *MainLoop関数
      *ループ状態に入る関数
      *設定されていないハンドラをここで設定（デフォルトのもの）
      */
      void MainLoop(){
            /*
            *画面サイズ変更時のハンドラをセット
            */
            glutReshapeFunc(DefaultResize);

            /*
            *マウスのイベントハンドラをセット
            */
            glutMouseFunc(MouseFunction);

            /*
            *ループ
            */
            glutMainLoop();
      }

      /*
      *DefaultResize関数
      *デフォルトのりサイズハンドラ
      */
      void DefaultResize(int width, int height){
            /*
            *ビューポートは全域に設定
            */
            glViewport(0, 0, width, height);

            /*
            *行列をロード
            */
            glLoadIdentity();

            /*
            *ワールド座標系に変換
            */
            glOrtho(-YuriGLManager->NDeviceCSX(width), YuriGLManager->NDeviceCSX(width),
             -YuriGLManager->NDeviceCSY(height), YuriGLManager->NDeviceCSY(height), -1.0, 1.0);
      }

      /*
      *背景を塗りつぶす関数
      *引数
      *RGBA color
      *=>色
      */
      void FillBackGround(RGBA color){
            /*
            *色を指定
            */
            glClearColor(color.getNDRED(), color.getNDGREEN(), color.getNDBLUE(), color.getNDALPHA());

            /*
            *塗りつぶす
            */
            glClear(GL_COLOR_BUFFER_BIT);
      }
}