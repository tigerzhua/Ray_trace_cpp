#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"
#include "point3d.h"
#include "pixel.h"

class Sphere: public Object
{
    public:

        Sphere();

        ~Sphere();

        Sphere(Point3d & ctr, float r, Pixel & color);

        Sphere(Point3d & ctr, float r);

        inline void set_radius(float ctr);

        inline float radius();

    private:

        float _radius;

};

inline void Sphere::set_radius(float r){_radius = r;}
inline float Sphere::radius(){return _radius;}

#endif // SPHERE_H

