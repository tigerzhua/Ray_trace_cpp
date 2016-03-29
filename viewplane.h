#ifndef VIEWPLANE_H
#define VIEWPLANE_H

#include <stdlib.h>

//loacl include
#include "point3d.h"
#include "vector3d.h"
#include "pixel.h"

class Viewplane
{
    public:

        Viewplane();

        ~Viewplane();

        Viewplane(int width, int height,
                  Vector3d A, Vector3d B);

        float pixel_size();
        int num_sample();
        Pixel background();
        Point3d ref_point();
        Vector3d A();
        Vector3d B();
        int height();
        int width();

        void resize(int width, int height);
        void set_pixel_size(float s);
        void set_background(Pixel bg);
        void set_ref(Point3d p);

    private:
        int _width;
        int _height;
        float _pixel_size;
        Pixel _background;
        Point3d _ref; //tells us the position of this plane, it's the bottom left corner
        Vector3d _A,_B;
        Vector3d _n;
        int _num_sample;
};

#endif // VIEWPLANE_H
