#include "ray_dir.h"

Directional_ray::Directional_ray()
{
    _dir = Vector3d();
    _color = Pixel();
}

Directional_ray::~Directional_ray()
{
    //nothing
}

void Directional_ray::set_direction(Vector3d & dir)
{
    _dir = dir;
}

Directional_ray::Directional_ray(Vector3d & dir, Pixel & color)
{
    _dir = dir;
    _color = color;
}

Directional_ray::Directional_ray(const Directional_ray &source)
{
    if( this != &source)
    {
        this->_dir = source._dir;
        this->_orig = source._orig;
        this->_dest = source._dest;
        this->_color = source._color;
    }
}

void Directional_ray::set_destination(Point3d p)
{
    _dest = p;
}

void Directional_ray::set_origin(Point3d & orig)
{
    _orig = orig;
}

void Directional_ray::set_color(Pixel & color)
{
    _color = color;
}

Point3d Directional_ray::get_orig()
{
    return _orig;
}

Point3d Directional_ray::get_dest()
{
    return _dest;
}

Vector3d Directional_ray::get_dir()
{
    return _dir;
}

Pixel Directional_ray::get_color()
{
    return _color;
}
