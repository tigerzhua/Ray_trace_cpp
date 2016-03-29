#include "world.h"
#include <math.h>
#include <iostream>
#include <time.h>

#define MAX_RECURSE_NUM 1
#define SAMPLE_PER_PIXEL 0
#define PERSPECTIVE 1
#define TRACE_FACTOR 0.7

//Set colors
Pixel black(0,0,0);
Pixel white(255,255,255);
Pixel red(255,0,0);
Pixel green(0,255,0);
Pixel blue(0,0,255);

//read demo mesh
Mesh3d teapot = Mesh3d("teapot.obj");

World::World()
{
    _objects.clear();
    _camera = NULL;
    _tracer = new Tracer();
    vp.set_background(black);
    vp.set_pixel_size(0.5);
    vp = Viewplane(0,0, Vector3d(1.f,0.f,0.f), Vector3d(0.f,1.f,0.f));
    vp.set_ref( Point3d(0,0,500) );
    _pixels = NULL;
}

World::~World()
{
    if(_camera != NULL){
        delete _camera;
        _camera = NULL;
    }
    if(_tracer != NULL){
        delete _tracer;
        _tracer = NULL;
    }

    for (int i=0; i<_objects.size(); ++i){
        if(_objects[i] != NULL){
            delete _objects[i];
            _objects[i] = NULL;
        }
    }
}

World::World(unsigned int w, unsigned int h)
{
    _camera = NULL;
    _tracer = new Tracer();
    vp.set_background(black);
    vp.set_pixel_size(0.5);
    vp = Viewplane(w,h, Vector3d(1.f,0.f,0.f), Vector3d(0.f,1.f,0.f));
    vp.set_ref(Point3d(0,0,100));
    _pixels = new unsigned char[w*h*4];
}

void World::build()
{
        //a sample scene with 5 spheres
        Sphere *sph1 = new Sphere();
        sph1->set_color(Pixel(123, 255, 45));
        sph1->set_center(Point3d(-400, 200, -300));
        sph1->set_radius(250);
        add_object(sph1);


        Sphere *sph2 = new Sphere();
        sph2->set_color(Pixel(255, 123, 45));
        sph2->set_center(Point3d(400, -200,-100));
        sph2->set_radius(200);
        add_object(sph2);

        Sphere *sph3 = new Sphere();
        sph3->set_color(Pixel(45, 123, 255));
        sph3->set_center(Point3d(400, 200,-100));
        sph3->set_radius(150);
        add_object(sph3);

        Sphere *sph4 = new Sphere();
        sph4->set_color(Pixel(123, 123, 45));
        sph4->set_center(Point3d(-600, -200,-100));
        sph4->set_radius(150);
        add_object(sph4);

        Sphere *sph5 = new Sphere();
        sph5->set_color(Pixel(235, 34, 45));
        sph5->set_center(Point3d(0, 0,-100));
        sph5->set_radius(50);
        add_object(sph5);
}

void World::set_background(Pixel& bg)
{
    vp.set_background(bg);
}

void World::resize(int w, int h)
{
    vp.resize(w,h);
}

float find_min(float a, float b)
{
    if(a<=b)
        return a;
    else
        return b;
}

void World::render_world()
{
    //set all pixels: alpha to 255, color to 0
    for (int l = 0; l < vp.width()*vp.height()*4; ++l){
        if((l+1)%4 == 0)//alpha
            _pixels[l] = 255;
        else
            _pixels[l] = 0;
    }

    //setup ambient light
    Directional_ray amb_ray;//used for shading
    Vector3d amb_dir = Vector3d(1.f,1.f,0.f);
    amb_dir.normalize_vector();
    amb_ray.set_direction(amb_dir);

    //the tracing ray
    Directional_ray ray;
    Directional_ray spec_light;

    //The place to hold pixel data
    Scene_info info;

    //start point of ray
    Point3d cur_orig;

    float x_off = vp.ref_point().get_x();
    float y_off = vp.ref_point().get_y();
    float z_off = vp.ref_point().get_z();

    float ax_step = vp.A().get_x();
    float bx_step = vp.B().get_x();

    float ay_step = vp.A().get_y();
    float by_step = vp.B().get_y();

    float az_step = vp.A().get_z();
    float bz_step = vp.B().get_z();

	float zw = 100.0;			// hard-coded
    vp.set_pixel_size(2.0);
    Vector3d dir(0.f,0.f,-1.f);
    ray.set_direction(dir);

    //setup environment light
    Vector3d environment_dir(3.f,4.f,-5.f);
    environment_dir.normalize_vector();
    spec_light.set_direction(environment_dir);

    std::cout<<"Start ray tracing"<<std::endl;
    std::cout<<_objects.size()<<" objects involve(s)."<<std::endl;

    //build the pixel buffer
    int red_sum = 0;
    int green_sum = 0;
    int blue_sum = 0;
    int rec_ctr = MAX_RECURSE_NUM;
    float factor = TRACE_FACTOR;
    srand (time(NULL));

    for (int i = 0; i < vp.height(); ++i)
    {
        std::cout<<"Processing line "<<i<<std::endl;
        for (int j = 0; j < vp.width(); ++j)
        {
            red_sum = 0;
            green_sum = 0;
            blue_sum = 0;

            //reset pixel color
            _pixels[i*vp.width()*4 + j*4 + 0] = 0;
            _pixels[i*vp.width()*4 + j*4 + 1] = 0;
            _pixels[i*vp.width()*4 + j*4 + 2] = 0;

            for (int sample_count = 0; sample_count<SAMPLE_PER_PIXEL; ++sample_count){
                //rand sample point
                float yr = (rand() % (int)(vp.pixel_size()*100) )*0.01;
                float xr = (rand() % (int)(vp.pixel_size()*100) )*0.01;
                float zr = (rand() % (int)(vp.pixel_size()*100) )*0.01;

                //reset path tracer
                factor = TRACE_FACTOR;
                rec_ctr = MAX_RECURSE_NUM;

                //TODO: dont forget to change this back
                if( !PERSPECTIVE ){
                    cur_orig.set_point(y_off + vp.pixel_size() * (i - vp.height() / 2.0 + 0.5) * ay_step
                                             + vp.pixel_size() * (j - vp.width()  / 2.0 + 0.5) * by_step+yr,
                                       x_off + vp.pixel_size() * (i - vp.height() / 2.0 + 0.5) * ax_step
                                             + vp.pixel_size() * (j - vp.width()  / 2.0 + 0.5) * bx_step+xr,
                                       z_off + vp.pixel_size() * (i - vp.height() / 2.0 + 0.5) * az_step
                                             + vp.pixel_size() * (j - vp.width()  / 2.0 + 0.5) * bz_step+zr);
                }
                else{
                    ray.set_destination(Point3d(0.f,0.f,-10800.f));
                    Vector3d dir = ray.get_dest() - cur_orig;
                    dir.normalize_vector();
                    ray.set_direction(dir);

                    cur_orig.set_point(y_off+vp.pixel_size() * (j - vp.width() / 2.0 + 0.5)+yr,
                                       x_off+vp.pixel_size() * (i - vp.height() / 2.0 + 0.5)+xr,
                                       z_off+zw+zr);
                }

                //set the origin and dir of the tracing ray
                ray.set_origin(cur_orig);
                ray.set_direction(dir);

                //"z-buffer"
                float min_distance = 3.4e38;//set as the max value of float
                int cur_obj_idx = -1;

                trace_scene(info, ray, spec_light, rec_ctr, cur_obj_idx, min_distance, i, j, amb_dir, factor, cur_orig);

                red_sum += _pixels[i*vp.width()*4 + j*4 + 0];
                green_sum += _pixels[i*vp.width()*4 + j*4 + 1];
                blue_sum += _pixels[i*vp.width()*4 + j*4 + 2];
            }

            //calculate final color
            if(SAMPLE_PER_PIXEL != 0){
                _pixels[i*vp.width()*4 + j*4 + 0] = red_sum/SAMPLE_PER_PIXEL;
                _pixels[i*vp.width()*4 + j*4 + 1] = green_sum/SAMPLE_PER_PIXEL;
                _pixels[i*vp.width()*4 + j*4 + 2] = blue_sum/SAMPLE_PER_PIXEL;
            }
        }
    }

    std::cout<<"Ray tracing finished!"<<std::endl;
}

//recursive function
void World::trace_scene(Scene_info &info, Directional_ray &ray, Directional_ray &spec_light, int rec_ctr,
                        int cur_obj_idx, float min_distance,
                        int i, int j,
                        Vector3d &amb_dir, float factor, Point3d &cur_orig)
{
    if(rec_ctr <= 0)
        return;

        for (int o = 0; o < _objects.size(); ++o){
            if((o != cur_obj_idx)){//dont hit yourself again
                if( _tracer->hit(ray, _objects[o], info) ){
                    //get the color
                    //lambertian shading
                    //calculate the cos value

                    if(_objects[o]->type() == obj_type::Triangle){
                        Triangle* cur_tri = reinterpret_cast<Triangle*>(_objects[o]);
                        Vector3d tri_normal = cur_tri->get_n();
                        update_color(info, i, j, tri_normal, amb_dir, 1.f);
                    }
                    else if(_objects[o]->type() == obj_type::Sphere){//sphere
                        Sphere* cur_sph = reinterpret_cast<Sphere*>(_objects[o]);
                        Vector3d normal_hit = info._hit_point - cur_sph->center();
                        normal_hit.normalize_vector();

                        if(rec_ctr == MAX_RECURSE_NUM)//first time
                            update_color(info, i, j, normal_hit, amb_dir, 1.f);
                        else//average color
                            update_color(info, i, j, normal_hit, amb_dir, factor);

                        Directional_ray new_ray(ray);
                        Scene_info new_info(info);
                        update_dir_and_org(new_info, new_ray, normal_hit);

                        trace_scene(new_info, new_ray, spec_light, (rec_ctr-1), o, min_distance, i, j, amb_dir, factor/2, cur_orig);
                        //calaulate spec
                        Vector3d view_vec = info._hit_point - cur_orig;
                        view_vec.normalize_vector();

                        Directional_ray new_spec(spec_light);
                        update_dir_and_org(new_info, new_spec, normal_hit);
                        Vector3d spec_hit = new_spec.get_dir();

                        update_spec(info, i, j, spec_hit, view_vec, spec_light);
                    }
                    else
                    {
                        //simply copy the color
                        copy_info_color(info, i, j);
                    }
                }
            }
        }

}

//BRDF for diffusion as reflection equation
void World::update_color(Scene_info &info, int row, int col, Vector3d &normal_hit, Vector3d &amb_dir, float factor)
{
    float cos_val = normal_hit*amb_dir;
    if(cos_val < 0)
        cos_val = 0;
    if(factor == 1)//first time
    {
        _pixels[row*vp.width()*4 + col*4 + 0] = info._color.red()*(1-cos_val) + (1-cos_val)*vp.background().red()*factor;
        _pixels[row*vp.width()*4 + col*4 + 1] = info._color.green()*(1-cos_val) + (1-cos_val)*vp.background().green()*factor;
        _pixels[row*vp.width()*4 + col*4 + 2] = info._color.blue()*(1-cos_val) + (1-cos_val)*vp.background().blue()*factor;
        _pixels[row*vp.width()*4 + col*4 + 3] = 255;//alpha
    }
    else
    {
        _pixels[row*vp.width()*4 + col*4 + 0] = info._color.red()*(factor)*(1-cos_val) + _pixels[row*vp.width()*4 + col*4 + 0]*(1-factor);
        _pixels[row*vp.width()*4 + col*4 + 1] = info._color.green()*(factor)*(1-cos_val) + _pixels[row*vp.width()*4 + col*4 + 1]*(1-factor);
        _pixels[row*vp.width()*4 + col*4 + 2] = info._color.blue()*(factor)*(1-cos_val) + _pixels[row*vp.width()*4 + col*4 + 2]*(1-factor);
    }
}

//BRDF for spec as well as reflection equation
void World::update_spec(Scene_info &info, int row, int col, Vector3d &spec_hit, Vector3d &view_vec,
                        Directional_ray &spec_light)
{
    float cos_val = spec_hit*view_vec;
    if(cos_val < 0)
        cos_val = 0;

    //adjust model
    cos_val+=0.05;

    cos_val = pow(cos_val, 2);

    if(cos_val > 1)
        cos_val = 1;
    float sin_val = pow( 1-cos_val, 25);

    _pixels[row*vp.width()*4 + col*4 + 0] = find_min(spec_light.get_color().red()*sin_val*0.3 + _pixels[row*vp.width()*4 + col*4 + 0],255.f);
    _pixels[row*vp.width()*4 + col*4 + 1] = find_min(spec_light.get_color().green()*sin_val*0.3 + _pixels[row*vp.width()*4 + col*4 + 1],255.f);
    _pixels[row*vp.width()*4 + col*4 + 2] = find_min(spec_light.get_color().blue()*sin_val*0.3 + _pixels[row*vp.width()*4 + col*4 + 2],255.f);
    _pixels[row*vp.width()*4 + col*4 + 3] = 255;//alpha
}

void World::update_dir_and_org(Scene_info &info, Directional_ray &ray, Vector3d &normal_hit)
{
    Vector3d recurse_dir;//new direction

    Vector3d two_times_recurse_dir = ray.get_dir()*2;
    double para = two_times_recurse_dir*normal_hit;
    recurse_dir = ray.get_dir() - normal_hit*para;

    ray.set_direction(recurse_dir);
    ray.set_origin(info._hit_point);
}

void World::copy_info_color(Scene_info &info, int row, int col)
{
    _pixels[row*vp.width()*4 + col*4 + 0] = info._color.red();
    _pixels[row*vp.width()*4 + col*4 + 1] = info._color.green();
    _pixels[row*vp.width()*4 + col*4 + 2] = info._color.blue();
    _pixels[row*vp.width()*4 + col*4 + 3] = 255;//alpha
}

void World::add_object(Object * obj)
{
    _objects.push_back(obj);
}

unsigned char* World::pixels()
{
    return _pixels;
}

void World::set_pixel_size(float s)
{
    vp.set_pixel_size(s);
}
