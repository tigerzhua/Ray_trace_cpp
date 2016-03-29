#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include "object.h"
#include "point3d.h"
#include "vector3d.h"
#include "pixel.h"


class Triangle: public Object
{
    public:

        Triangle();

        ~Triangle();

        inline Point3d get_a();
        inline Point3d get_b();
        inline Point3d get_c();

        inline void set_a(Point3d a);
        inline void set_b(Point3d b);
        inline void set_c(Point3d c);

        inline void calculate_normal();
        inline Vector3d get_n();
        inline void set_n(const Vector3d n);

    private:

		Point3d 	_a;
		Point3d     _b;
		Point3d     _c;
		Vector3d 	_n;					// normal
};

inline Point3d Triangle::get_a(){return _a;}
inline Point3d Triangle::get_b(){return _b;}
inline Point3d Triangle::get_c(){return _c;}
inline void Triangle::set_a(Point3d a){_a = a;}
inline void Triangle::set_b(Point3d b){_b = b;}
inline void Triangle::set_c(Point3d c){_c = c;}
inline Vector3d Triangle::get_n(){return _n;}
inline void Triangle::set_n(const Vector3d n){_n = n;}

#endif // __TRIANGLE_H
