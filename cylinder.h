#ifndef __CYLINDER_H
#define __CYLINDER_H

#include "object.h"
#include "point3d.h"
#include "vector3d.h"
#include "pixel.h"


class Cylinder: public Object
{
    public:

        Cylinder();

        ~Cylinder();

        inline float get_r();
        inline Vector3d get_dir();
        inline float get_tmax();

        inline void set_radius(float r);
        inline void set_dir(const Vector3d dir);
        inline void set_tmax(float t);

        bool _has_cap;

    private:

		float _radius;

        float _tmax;
		Vector3d _dir;
};

inline float Cylinder::get_r(){return _radius;}
inline Vector3d Cylinder::get_dir(){return _dir;}
inline float Cylinder::get_tmax(){return _tmax;}
inline void Cylinder::set_radius(float r){_radius = r;}
inline void Cylinder::set_dir(const Vector3d dir){_dir = dir;}
inline void Cylinder::set_tmax(float t){_tmax = t;}

#endif // __CYLINDER_H





