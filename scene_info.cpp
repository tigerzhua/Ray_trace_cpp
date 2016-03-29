#include"scene_info.h"

Scene_info::Scene_info()
{
    //nothing
}

Scene_info::Scene_info(Scene_info &source)
{
    if(this != &source)
    {
        this->_hit_point = source._hit_point;
        this->_color = source._color;
    }
}

Scene_info::~Scene_info()
{
    //nothing
}
