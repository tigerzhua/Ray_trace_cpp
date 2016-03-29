#include "plane.h"

Plane::Plane()
{
    _a = Point3d();
    _n = Vector3d();
    _type = obj_type::Plane;
}

Plane::~Plane()
{
    //nothing
}

Plane::Plane(Point3d a, Vector3d n)
{
    _a = a;
    _n = n;
    _type = obj_type::Plane;
}

void Plane::set_a(Point3d a)
{
    _a = a;
}

void Plane::set_n(Vector3d n)
{
    _n = n;
}

Point3d& Plane::get_a()
{
    return _a;
}

Vector3d& Plane::get_n()
{
    return _n;
}
