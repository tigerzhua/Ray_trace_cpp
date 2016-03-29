#ifndef CAMERA_H
#define CAMERA_H

#include "point3d.h"

class Camera
{
    public:

        Camera();

        ~Camera();

        Camera(const float px, const float py, const float pz,
               const float dx, const float dy, const float dz);

        void set_camera(const float px, const float py, const float pz,
                        const float dx, const float dy, const float dz);

        void set_pos(const float px, const float py, const float pz);

        void set_des(const float dx, const float dy, const float dz);

    private:

        Point3d _pos;

        Point3d _des;
};

#endif // CAMERA_H

