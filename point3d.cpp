#include "point3d.h"

Point3d::Point3d()
{
    _x = 0;
    _y = 0;
    _z = 0;
}

Point3d::~Point3d()
{
    //nothing
}

Point3d& Point3d::operator= (const Point3d& rhs)
{
    if(&rhs != this)
    {
        _x = rhs._x;
        _y = rhs._y;
        _z = rhs._z;
    }
}

Vector3d Point3d::operator- (const Point3d& rhs)
{
    Vector3d result;

    result.set_vector(rhs._x, rhs._y, rhs._z,
                      this->_x, this->_y, this->_z);

    return result;
}

Point3d Point3d::operator+ (const Point3d& rhs)
{
    Point3d result;

    result._x = this->_x + rhs._x;
    result._y = this->_y + rhs._y;
    result._z = this->_z + rhs._z;

    return result;
}

Point3d Point3d::operator* (const double rhs)
{
    Point3d result;

    result._x = this->_x * rhs;
    result._y = this->_y * rhs;
    result._z = this->_z * rhs;

    return result;
}

Point3d::Point3d(const float x, const float y, const float z)
{
    set_point(x, y, z);
}

void Point3d::set_point(const float x, const float y, const float z)
{
    _x = x;
    _y = y;
    _z = z;
}
