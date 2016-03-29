#ifndef DIRECTIONAL_RAY_H
#define DIRECTIONAL_RAY_H

#include "vector3d.h"
#include "point3d.h"
#include "pixel.h"

class Directional_ray
{
    public:

        Directional_ray(); //make a white one

        ~Directional_ray();

        Directional_ray(Vector3d & dir, Pixel & color);

        Directional_ray(const Directional_ray &source);

        void set_origin(Point3d & orig);

        void set_direction(Vector3d & dir);

        void set_destination(Point3d p);

        void set_color(Pixel & color);

        Point3d get_orig();

        Point3d get_dest();

        Vector3d get_dir();

        Pixel get_color();

    private:

        Vector3d _dir;

        Point3d _orig;

        Point3d _dest;

        Pixel _color;

};

#endif // DIRECTIONAL_RAY_H
