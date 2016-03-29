#include "camera.h"

Camera::Camera()
{

}

Camera::~Camera()
{
    //nothing
}

Camera::Camera(const float px, const float py, const float pz,
               const float dx, const float dy, const float dz)
{
    set_camera(px, py, pz, dx, dy, dz);
}

void Camera::set_camera(const float px, const float py, const float pz,
                        const float dx, const float dy, const float dz)
{
    _pos.set_point(px, py, pz);
    _des.set_point(dx, dy, dz);
}

void Camera::set_pos(const float px, const float py, const float pz)
{
    _pos.set_point(px, py, pz);
}

void Camera::set_des(const float dx, const float dy, const float dz)
{
    _des.set_point(dx, dy, dz);
}
