#ifndef VECTOR3D_H
#define VECTOR3D_H

//#include "point3d.h"

//vector that indicates direction
class Vector3d
{
    public:

        Vector3d();

        ~Vector3d();

        Vector3d(const float ox, const float oy, const float oz,
                 const float dx, const float dy, const float dz);

        Vector3d(const float x, const float y, const float z);

		Vector3d& operator= (const Vector3d& rhs);

		Vector3d operator- (const Vector3d& rhs);

        //dot product
		double operator* (const Vector3d& rhs);

        //cross product
		Vector3d operator^ (const Vector3d& rhs);

		//scale
		Vector3d operator* (const float rhs);

        void set_vector(const float ox, const float oy, const float oz,
                        const float dx, const float dy, const float dz);
        //void set_vector(const Point3d& orig, const Point3d& dest);

        void set_origin(const float ox, const float oy, const float oz);
        //void set_origin(const Point3d& orig);

        void set_destination(const float dx, const float dy, const float dz);
        //void set_destination(const Point3d& dest);

        void normalize_vector();

        inline const float get_x();
        inline const float get_y();
        inline const float get_z();

    private:

        float _x, _y, _z;
        float _ox, _oy, _oz;
        float _dx, _dy, _dz;
};

inline const float Vector3d::get_x(){return _x;}
inline const float Vector3d::get_y(){return _y;}
inline const float Vector3d::get_z(){return _z;}

#endif // VECTOR3D_H
