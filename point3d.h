#ifndef POINT3D_H
#define POINT3D_H

#include "vector3d.h"

class Point3d
{
    public:

        Point3d();

        ~Point3d();

        Point3d& operator= (const Point3d& rhs);

        Vector3d operator- (const Point3d& rhs);

        Point3d operator+ (const Point3d& rhs);

        Point3d operator* (const double rhs);

        Point3d(const float x, const float y, const float z);

        void set_point(const float x, const float y, const float z);

        inline float get_x();
        inline float get_y();
        inline float get_z();

        inline void set_x(const float x);
        inline void set_y(const float y);
        inline void set_z(const float z);

        inline void add_x(const float x);
        inline void add_y(const float y);
        inline void add_z(const float z);

    private:

        float _x, _y, _z;
};

float Point3d::get_x(){return _x;}
float Point3d::get_y(){return _y;}
float Point3d::get_z(){return _z;}
void Point3d::set_x(const float x){_x = x;}
void Point3d::set_y(const float y){_y = y;}
void Point3d::set_z(const float z){_z = z;}
void Point3d::add_x(const float x){_x += x;}
void Point3d::add_y(const float y){_y += y;}
void Point3d::add_z(const float z){_z += z;}

#endif // POINT3D_H
