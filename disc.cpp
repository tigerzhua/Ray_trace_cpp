#include "disc.h"

Disc::Disc()
{
    _center = (Point3d(0.f,0.f,0.f));
    _radius = 1;
    _n = Vector3d(0.f,0.f,1.f);
    _type = obj_type::Cylinder;
}

Disc::~Disc()
{
    //nothing
}
