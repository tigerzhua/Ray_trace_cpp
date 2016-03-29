#ifndef __SCENE_INFO__
#define __SCENE_INFO__

#include"point3d.h"
#include"pixel.h"

class Scene_info{

    public:
        Point3d _hit_point;
        Pixel _color;

        Scene_info();

        Scene_info(Scene_info &source);

        ~Scene_info();
};

#endif // __SCENE_INFO__
