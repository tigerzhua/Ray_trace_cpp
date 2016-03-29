#ifndef OBJECT_H
#define OBJECT_H

#include "point3d.h"
#include "pixel.h"

namespace obj_type{
    enum type
    {
            Invalid         = -1,
            Sphere          = 1,
            Plane           = 2,
            Triangle        = 3,
            Disc            = 4,
            Cylinder        = 5
    };
}

class Object
{
    public:

        Object();

        ~Object();

        Object(Point3d & ctr, Pixel & color);

        Object(Point3d & ctr);

        inline void set_center(Point3d ctr);

        inline void set_color(Pixel color);

        inline Point3d center();

        inline Pixel color();

        inline obj_type::type type();

    protected:

        Point3d _center;

        Pixel _color;

        obj_type::type _type;

};

inline obj_type::type Object::type() {return _type;}
inline void Object::set_center(Point3d ctr){_center = ctr;}
inline void Object::set_color(Pixel color){_color = color;}
inline Point3d Object::center(){return _center;}
inline Pixel Object::color(){return _color;}

#endif // OBJECT_H
