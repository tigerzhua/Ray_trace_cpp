#include "object.h"

Object::Object()
{
    _center = Point3d();
    _color = Pixel();
    _type = obj_type::Invalid;
}

Object::~Object()
{
    //nothing
}

Object::Object(Point3d & ctr, Pixel & color)
{
    _center = ctr;
    _color = color;
    _type = obj_type::Invalid;
}

Object::Object(Point3d & ctr)
{
    _center = ctr;
    _color = Pixel();
    _type = obj_type::Invalid;
}
