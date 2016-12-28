#include <GL/glut.h>
#include <cmath>
#include "yurigl.hxx"

namespace yuri {
      extern YURIGL_MANAGER *YuriGLManager;

      void HitDot(Point2DD point, RGBA color){
            glColor4d(color.getNDRED(), color.getNDGREEN(), color.getNDBLUE(), color.getNDALPHA());
            glBegin(GL_POINTS);
            glVertex2d(point.ComputeNDCSX(YuriGLManager->getWidth()), point.ComputeNDCSY(YuriGLManager->getHeight()));
            glEnd();
            glFlush();
      }

      void DrawLine(Point2DD start, Point2DD end, RGBA color){
            glColor4d(color.getNDRED(), color.getNDGREEN(), color.getNDBLUE(), color.getNDALPHA());
            glBegin(GL_LINES);
            glVertex2d(start.ComputeNDCSX(YuriGLManager->getWidth()), start.ComputeNDCSY(YuriGLManager->getHeight()));
            glVertex2d(end.ComputeNDCSX(YuriGLManager->getWidth()), end.ComputeNDCSY(YuriGLManager->getHeight()));
            glEnd();
            glFlush();
      }

      void DrawTriangle(Point2DD p1, Point2DD p2, Point2DD p3, RGBA color){
            glColor4d(color.getNDRED(), color.getNDGREEN(), color.getNDBLUE(), color.getNDALPHA());
            glBegin(GL_TRIANGLES);
            glVertex2d(p1.ComputeNDCSX(YuriGLManager->getWidth()), p1.ComputeNDCSY(YuriGLManager->getHeight()));
            glVertex2d(p2.ComputeNDCSX(YuriGLManager->getWidth()), p2.ComputeNDCSY(YuriGLManager->getHeight()));
            glVertex2d(p3.ComputeNDCSX(YuriGLManager->getWidth()), p3.ComputeNDCSY(YuriGLManager->getHeight()));
            glEnd();
            glFlush();
      }

      void DrawRect(Point2DD p1, Point2DD p2, Point2DD p3, Point2DD p4, RGBA color){
            glColor4d(color.getNDRED(), color.getNDGREEN(), color.getNDBLUE(), color.getNDALPHA());
            glBegin(GL_QUADS);
            glVertex2d(p1.ComputeNDCSX(YuriGLManager->getWidth()), p1.ComputeNDCSY(YuriGLManager->getHeight()));
            glVertex2d(p2.ComputeNDCSX(YuriGLManager->getWidth()), p2.ComputeNDCSY(YuriGLManager->getHeight()));
            glVertex2d(p3.ComputeNDCSX(YuriGLManager->getWidth()), p3.ComputeNDCSY(YuriGLManager->getHeight()));
            glVertex2d(p4.ComputeNDCSX(YuriGLManager->getWidth()), p4.ComputeNDCSY(YuriGLManager->getHeight()));
            glEnd();
            glFlush();
      }

      void DrawCircle(Point2DD center, double r, RGBA color){
            int i;
            
            /*
            *密度の計算(適当)
            *直径のピクセル数
            */
            int density = r * 2.0;
            
            double x, y;
            glColor4d(color.getNDRED(), color.getNDGREEN(), color.getNDBLUE(), color.getNDALPHA());
            
            r = ComputeNDCSD(r, YuriGLManager->getWidth());
            //ポリゴンとして描画
            glBegin(GL_POLYGON);
            /*
            *0->ｎまで分割してX座標とY座標を求める
            */
		for(i = 0;i < density;i++){
                  /*
                  *2π * (進行度的な)
                  *座標を計算
                  */
                  x = r * std::cos(2.0 * 3.14 * ((double)i/density)) + center.ComputeNDCSX(YuriGLManager->getWidth());
                  y = r * std::sin(2.0 * 3.14 * ((double)i/density)) + center.ComputeNDCSY(YuriGLManager->getWidth());
			glVertex2d(x, y);
		}
            glEnd();
            glFlush();
      }

      double ComputeNDCSD(double value, double limit){
            return (value * 2.0) / limit - 1.0;
      }
}