#include <GL/glut.h>
#include "yurigl.h"

namespace yuri {
      extern YURIGL_MANAGER *YuriGLManager;

      void HitDot(Point2D<double> point, RGBA color){
            glColor4d(color.getNDRED(), color.getNDGREEN(), color.getNDBLUE(), color.getNDALPHA());
            glBegin(GL_POINTS);
            glVertex2d(point.ComputeNDCSX(YuriGLManager->getWidth()), point.ComputeNDCSY(YuriGLManager->getHeight()));
            glEnd();
            glFlush();
      }

      void DrawLine(Point2D<double> start, Point2D<double> end, RGBA color){
            glColor4d(color.getNDRED(), color.getNDGREEN(), color.getNDBLUE(), color.getNDALPHA());
            glBegin(GL_LINES);
            glVertex2d(start.ComputeNDCSX(YuriGLManager->getWidth()), start.ComputeNDCSY(YuriGLManager->getHeight()));
            glVertex2d(end.ComputeNDCSX(YuriGLManager->getWidth()), end.ComputeNDCSY(YuriGLManager->getHeight()));
            glEnd();
            glFlush();
      }

      void DrawTriangle(Point2D<double> p1, Point2D<double> p2, Point2D<double> p3, RGBA color){
            glColor4d(color.getNDRED(), color.getNDGREEN(), color.getNDBLUE(), color.getNDALPHA());
            glBegin(GL_TRIANGLES);
            glVertex2d(p1.ComputeNDCSX(YuriGLManager->getWidth()), p1.ComputeNDCSY(YuriGLManager->getHeight()));
            glVertex2d(p2.ComputeNDCSX(YuriGLManager->getWidth()), p2.ComputeNDCSY(YuriGLManager->getHeight()));
            glVertex2d(p3.ComputeNDCSX(YuriGLManager->getWidth()), p3.ComputeNDCSY(YuriGLManager->getHeight()));
            glEnd();
            glFlush();
      }

      void DrawRect(Point2D<double> p1, Point2D<double> p2, Point2D<double> p3, Point2D<double> p4, RGBA color){
            glColor4d(color.getNDRED(), color.getNDGREEN(), color.getNDBLUE(), color.getNDALPHA());
            glBegin(GL_QUADS);
            glVertex2d(p1.ComputeNDCSX(YuriGLManager->getWidth()), p1.ComputeNDCSY(YuriGLManager->getHeight()));
            glVertex2d(p2.ComputeNDCSX(YuriGLManager->getWidth()), p2.ComputeNDCSY(YuriGLManager->getHeight()));
            glVertex2d(p3.ComputeNDCSX(YuriGLManager->getWidth()), p3.ComputeNDCSY(YuriGLManager->getHeight()));
            glVertex2d(p4.ComputeNDCSX(YuriGLManager->getWidth()), p4.ComputeNDCSY(YuriGLManager->getHeight()));
            glEnd();
            glFlush();
      }
}