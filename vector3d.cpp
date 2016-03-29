#include "vector3d.h"
#include <math.h>

Vector3d::Vector3d()
{
    _x = 0;
    _y = 0;
    _z = 0;

    _dx = 0;
    _dy = 0;
    _dz = 0;

    _ox = 0;
    _oy = 0;
    _oz = 0;
}

Vector3d::~Vector3d()
{
    //nothing
}

Vector3d::Vector3d(const float ox, const float oy, const float oz,
                   const float dx, const float dy, const float dz)
{
    set_vector(ox, oy, oz, dx, dy, dz);
}

Vector3d::Vector3d(const float x, const float y, const float z)
{
    set_vector(0.f, 0.f, 0.f, x, y, z);
}

Vector3d& Vector3d::operator= (const Vector3d& rhs)
{
    if(&rhs != this)
    {
        _x = rhs._x;
        _y = rhs._y;
        _z = rhs._z;

        _ox = rhs._ox;
        _oy = rhs._oy;
        _oz = rhs._oz;

        _dx = rhs._dx;
        _dy = rhs._dy;
        _dz = rhs._dz;
    }
}

Vector3d Vector3d::operator- (const Vector3d& rhs)
{
    Vector3d result;

    result._x = this->_x - rhs._x;
    result._y = this->_y - rhs._y;
    result._z = this->_z - rhs._z;

    result._ox = 0;
    result._oy = 0;
    result._oz = 0;

    result._dx = result._x;
    result._dy = result._y;
    result._dz = result._z;

    return result;
}

double Vector3d::operator* (const Vector3d& rhs)
{
    //dot product
    double result;
    result = this->_x*rhs._x +
             this->_y*rhs._y +
             this->_z*rhs._z;

    return result;
}

Vector3d Vector3d::operator* (const float rhs)
{
    //scale
    Vector3d result;
    result = Vector3d(rhs*this->_x, rhs*this->_y, rhs*this->_z);
    return result;
}

Vector3d Vector3d::operator^ (const Vector3d& rhs)
{
    Vector3d result;
    result._x = this->_y*rhs._z - this->_z*rhs._y;
    result._y = this->_z*rhs._x - this->_x*rhs._z;
    result._z = this->_x*rhs._y - this->_y*rhs._x;

    result._ox = 0;
    result._oy = 0;
    result._oz = 0;

    result._dx = result._x;
    result._dy = result._y;
    result._dz = result._z;

    return result;
}

void Vector3d::set_vector(const float ox, const float oy, const float oz,
                          const float dx, const float dy, const float dz)
{
    _ox = ox;
    _oy = oy;
    _oz = oz;

    _dx = dx;
    _dy = dy;
    _dz = dz;

    _x = _dx-_ox;
    _y = _dy-_oy;
    _z = _dz-_oz;
}

void Vector3d::set_origin(const float ox, const float oy, const float oz)
{
    _ox = ox;
    _oy = oy;
    _oz = oz;
}

void Vector3d::set_destination(const float dx, const float dy, const float dz)
{
    _dx = dx;
    _dy = dy;
    _dz = dz;
}

void Vector3d::normalize_vector()
{
    float length = sqrt( (_dx-_ox)*(_dx-_ox)+(_dy-_oy)*(_dy-_oy)+(_dz-_oz)*(_dz-_oz) );
    _x = (_dx-_ox)/length;
    _y = (_dy-_oy)/length;
    _z = (_dz-_oz)/length;
}
