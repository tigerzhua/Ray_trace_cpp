#include"cylinder.h"

Cylinder::Cylinder()
{
    _radius = 1;
    _center = Point3d(0.f,0.f,0.f);
    _tmax = 1;
    _dir = Vector3d(1.f,0.f,0.f);
    _has_cap = true;
    _type = obj_type::Cylinder;
}

Cylinder::~Cylinder()
{
    //nothing
}
