#ifndef YR3D_H
#define YR3D_H

#include <string>
#include "value.h"
#include "point.h"

namespace yuri {

      class YURIGL_MANAGER {
            double width;
            double height;
            Point2D<int> DisplayPosition;
            std::string WindowName;
      public:
            YURIGL_MANAGER();
            std::string getWindowName();
            double getWidth();
            double getHeight();
            double NDeviceCSX(double width);
            double NDeviceCSY(double height);
      };

      class RGBA {
            double r;
            double g;
            double b;
            double a;
            public:
            RGBA(double r, double g, double b, double a);
            double getNDRED();
            double getNDGREEN();
            double getNDBLUE();
            double getNDALPHA();
      };

      void DisplaySetting(int width, int height, int display_x, int display_y);
      void Init(int argc, char *argv[]);
      void WindowName(std::string name);
      void SetRedrawFunction(void (*func)(void));
      void MainLoop();
      void CreateWindow(std::string name);
      void HitDot(Point2D<double> point, RGBA color);
      void DrawLine(Point2D<double> start, Point2D<double> end, RGBA color);
      void DrawTriangle(Point2D<double> p1, Point2D<double> p2, Point2D<double> p3, RGBA color);
      void DrawRect(Point2D<double> p1, Point2D<double> p2, Point2D<double> p3, Point2D<double> p4, RGBA color);

}

#endif