#ifndef PLANE_H
#define PLANE_H

#include "object.h"
#include "point3d.h"
#include "vector3d.h"
#include "pixel.h"


class Plane: public Object
{
    public:

        Plane();

        ~Plane();

        Plane(Point3d a, Vector3d n);

        Point3d& get_a();

        Vector3d& get_n();

        void set_a(Point3d a);

        void set_n(Vector3d n);

    private:

		Point3d 	_a;   				// point through which plane passes

		Vector3d 	_n;					// normal to the plane
};

#endif // PLANE_H


