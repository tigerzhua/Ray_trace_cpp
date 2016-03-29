#include "triangle.h"

Triangle::Triangle()
{
    _center = Point3d(0.f, 0.f, 0.f);
    _a = Point3d(1.f, 1.f, 0.f);
    _b = Point3d(-1.f, 1.f, 0.f);
    _c = Point3d(0.f, 1.f, 0.f);
    _type = obj_type::Triangle;
}

Triangle::~Triangle()
{
    //nothing
}

void Triangle::calculate_normal()
{
    Vector3d va = Vector3d(_b.get_x()-_a.get_x(), _b.get_y()-_a.get_y(), _b.get_z()-_a.get_z());
    Vector3d vb = Vector3d(_c.get_x()-_a.get_x(), _c.get_y()-_a.get_y(), _c.get_z()-_a.get_z());
    _n = va^vb;
    _n.normalize_vector();
}
