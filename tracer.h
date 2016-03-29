#ifndef TRACER_H
#define TRACER_H

#include "object.h"
#include "sphere.h"
#include "plane.h"
#include "triangle.h"
#include "disc.h"
#include "cylinder.h"

#include "ray_dir.h"
#include "point3d.h"
#include "pixel.h"
#include "scene_info.h"

//functional class
class Tracer
{
    public:

        Tracer();

        ~Tracer();

        bool hit(Directional_ray& ray, Object* obj, Scene_info& info);

    private:

};

#endif // TRACER_H
