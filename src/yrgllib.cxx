#include <GL/glut.h>
#include <string>
#include "yurigl.h"

namespace yuri {

      void DefaultResize(int width, int height);

      YURIGL_MANAGER *YuriGLManager;

      void DisplaySetting(int width, int height, int display_x, int display_y){
            glutInitWindowSize(width, height);
            glutInitWindowPosition(display_x, display_y);
      }

      void Init(int argc, char *argv[]){
            YuriGLManager = new YURIGL_MANAGER();
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_RGBA);     
      }

      void CreateWindow(std::string name){
            glutCreateWindow(name.c_str());
            glClearColor(1.0, 1.0, 1.0, 1.0);
      }

      void WindowName(std::string name){
            glutSetWindowTitle(name.c_str());
      }

      void SetRedrawFunction(void (*func)(void)){
            glutDisplayFunc(func);
            glutReshapeFunc(DefaultResize);
      }

      void MainLoop(){
            glutMainLoop();
      }

      void DefaultResize(int width, int height){
            
            glViewport(0, 0, width, height);

            glLoadIdentity();

            glOrtho(-YuriGLManager->NDeviceCSX(width), YuriGLManager->NDeviceCSX(width),
             -YuriGLManager->NDeviceCSY(height), YuriGLManager->NDeviceCSY(height), -1.0, 1.0);
      }

      void FillBackGround(RGBA color){
            glClearColor(color.getNDRED(), color.getNDGREEN(), color.getNDBLUE(), color.getNDALPHA());
            glClear(GL_COLOR_BUFFER_BIT);
      }
}