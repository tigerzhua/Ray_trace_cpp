#include "sphere.h"

Sphere::Sphere()
{
    _center = Point3d();
    _color = Pixel();
    _radius = 1;
    _type = obj_type::Sphere;
}

Sphere::~Sphere()
{
    //nothing
}

Sphere::Sphere(Point3d & ctr, float r, Pixel & color)
{
    _center = ctr;
    _radius = r;
    _color = color;
    _type = obj_type::Sphere;
}

Sphere::Sphere(Point3d & ctr, float r)
{
    _center = ctr;
    _radius = r;
    _color = Pixel();
    _type = obj_type::Sphere;
}
