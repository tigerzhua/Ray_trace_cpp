#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>
#include <vector>

//loacl include
#include "pixel.h"
#include "camera.h"
#include "object.h"
#include "tracer.h"
#include "scene_info.h"
#include "viewplane.h"
#include "mesh3d.h"

class World
{
    public:

        World();

        ~World();

        World(unsigned int w, unsigned int h);

        void build();//make a brand new world!

        void set_background(Pixel& bg);

        void set_pixel_size(float s);

        void resize(int w, int h);

        void render_world();

        void add_object(Object * obj);

        unsigned char* _pixels;

        unsigned char* pixels();

    private:
        //view plane info
        Viewplane vp;

        std::vector<Object*>_objects;

        Camera * _camera;

        Tracer * _tracer;

        //helpers
        void update_color(Scene_info &info, int row, int col, Vector3d &normal_hit, Vector3d &amb_dir, float factor);
        void update_spec(Scene_info &info, int row, int col, Vector3d &spec_hit, Vector3d &view_vec,
                         Directional_ray &environment_light);
        void update_dir_and_org(Scene_info &info, Directional_ray &ray, Vector3d &normal_hit);
        void copy_info_color(Scene_info &info, int row, int col);
        void trace_scene(Scene_info &info, Directional_ray &ray, Directional_ray &environment_light, int rec_ctr,
                        int cur_obj_idx, float min_distance,
                        int i, int j,
                        Vector3d &amb_dir, float factor, Point3d &cur_orig);
};

#endif // WORLD_H
