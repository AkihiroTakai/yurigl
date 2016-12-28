#ifndef YR3D_H
#define YR3D_H

#include <string>
#include "value.h"
#include "point.h"

namespace yuri {

      class YURIGL_MANAGER {
            double width;
            double height;
            Point2DD DisplayPosition;
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
      void HitDot(Point2DD point, RGBA color);
      void DrawLine(Point2DD start, Point2DD end, RGBA color);
      void DrawTriangle(Point2DD p1, Point2DD p2, Point2DD p3, RGBA color);
      void DrawRect(Point2DD p1, Point2DD p2, Point2DD p3, Point2DD p4, RGBA color);
      void FillBackGround(RGBA color);
      void DrawCircle(Point2DD center, double r, RGBA color);
      double ComputeNDCSD(double value, double limit);
}

#endif