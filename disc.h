#ifndef __DISC_H
#define __DISC_H

#include "object.h"
#include "point3d.h"
#include "vector3d.h"
#include "pixel.h"

class Disc: public Object
{
    public:

        Disc();

        ~Disc();

        inline float get_r();
        inline Vector3d get_n();

        inline void set_radius(float r);
        inline void set_n(const Vector3d n);

    private:

		float       _radius;
		Vector3d 	_n;					// normal
};

inline float Disc::get_r(){return _radius;}
inline Vector3d Disc::get_n(){return _n;}
inline void Disc::set_radius(float r){_radius = r;}
inline void Disc::set_n(const Vector3d n){_n = n;}

#endif // __DISC_H




