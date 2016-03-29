void World::build()
{

    //add a triangle
    //color is red
    //Triangle *tri = new Triangle();
    //tri->set_color(red);
    //tri->set_a(Point3d(50.f, -50.f, 50.f));
    //tri->set_b(Point3d(-50.f, -30.f, 0.f));
    //tri->set_c(Point3d(100.f, -20.f, -50.f));
    //tri->calculate_normal();

    //add_object(tri);
    //vp.set_pixel_size(0.01);

//    for (int i = 0; i < teapot.mesh_faces_tri.size(); i+=3)
//    {
        //add triangles
        //color is red
//        Triangle *tri = new Triangle();
//        tri->set_color(Pixel(255,0,0));

//        tri->set_a( Point3d(teapot.mesh_faces_tri[i].get_x(),
//                            teapot.mesh_faces_tri[i].get_y(),
//                            teapot.mesh_faces_tri[i].get_z()) );
        /*if((int)(vp.height()/2+tri->get_a().get_y()/vp.pixel_size()) >= 0 &&
           (int)(vp.height()/2+tri->get_a().get_y()/vp.pixel_size()) < vp.height() &&
           (int)(vp.width()/2+tri->get_a().get_x()/vp.pixel_size()) >= 0 &&
           (int)(vp.width()/2+tri->get_a().get_x()/vp.pixel_size()) < vp.width() )*/
/*
        tri->set_b( Point3d(teapot.mesh_faces_tri[i+1].get_x(),
                            teapot.mesh_faces_tri[i+1].get_y(),
                            teapot.mesh_faces_tri[i+1].get_z()) );

        tri->set_c( Point3d(teapot.mesh_faces_tri[i+2].get_x(),
                            teapot.mesh_faces_tri[i+2].get_y(),
                            teapot.mesh_faces_tri[i+2].get_z()) );

        tri->set_n( Vector3d(teapot.mesh_face_normal[i/3].get_x(),
                             teapot.mesh_face_normal[i/3].get_y(),
                             teapot.mesh_face_normal[i/3].get_z()) );

        add_object(tri);
    }*/

    //srand (time(NULL));
    //for (int i = 0; i < 5; ++i)
    //{
    //    Sphere *sph1 = new Sphere();
    //    sph1->set_color(Pixel(rand()%256,rand()%256,rand()%256));
    //    sph1->set_center(Point3d(-(rand()%1000-500), -(rand()%800-400),-(rand()%200-100)));
    //    sph1->set_radius(-(rand()%200+50));

    //    add_object(sph1);
    //}

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
    /*
    //add a plane
    //color is green
    Plane *pln = new Plane();
    pln->set_color(Pixel(0,255,0));
    pln->set_center(Point3d(0,0,-50));
    Vector3d norm_p(0.f,0.f,1.f);
    pln->set_n(norm_p);
    pln->set_a(Point3d(0.f,1.f,1.f));


    //add_object(pln);
    //add a sphere
    //color is blue
    Sphere *sph1 = new Sphere();
    sph1->set_color(Pixel(125,233,17));
    sph1->set_center(Point3d(-280.f, -200.f, -50.f));
    sph1->set_radius(75.f);

    add_object(sph1);

    //add_object(pln);
    //add a sphere
    //color is blue
    Sphere *sph = new Sphere();
    sph->set_color(Pixel(0,0,255));
    sph->set_center(Point3d(80.f, 200.f, 50.f));
    sph->set_radius(100.f);

    add_object(sph);
*/
    //add a triangle
    //color is red
    //Triangle *tri = new Triangle();
    //tri->set_color(Pixel(255,0,0));
    //tri->set_a(Point3d(50.f, -50.f, 50.f));
    //tri->set_b(Point3d(-50.f, -30.f, 0.f));
    //tri->set_c(Point3d(100.f, -20.f, -50.f));

    //add_object(tri);
/*
    //add a disc
    //color is red+green=yellow
    Disc *dis = new Disc();
    dis->set_radius(75.f);
    dis->set_center(Point3d(200.f,20.f,-50.f));
    Vector3d norm_d(0.f,3.f,4.f);
    norm_d.normalize_vector();
    dis->set_n(norm_d);
    dis->set_color(Pixel(255,255,0));

    //add_object(dis);

    //add a cylinder
    //color is green+blue
    Cylinder* cyl = new Cylinder();
    cyl->set_color(Pixel(0,255,255));
    cyl->set_center(Point3d(-100.f,20.f,0.f));
    Vector3d dir = Vector3d(0.f,3.f,4.f);
    //Vector3d dir = Vector3d(0.f,0.f,1.f);
    dir.normalize_vector();
    cyl->set_dir(dir);
    cyl->set_radius(30.f);
    cyl->set_tmax(450.f);

    add_object(cyl);
    */
}

void World::render_world()
{
    //set all pixels: alpha to 255, color to 0
    for (int l = 0; l < vp.width()*vp.height()*4; ++l)
    {
        if((l+1)%4 == 0)//alpha
        {
            _pixels[l] = 255;
        }
        else
        {
            _pixels[l] = 0;
        }
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

	float zw = 100.0;				// hard-coded
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

            for (int sample_count = 0; sample_count<SAMPLE_PER_PIXEL; ++sample_count)
            {
                //rand sample point
                float yr = (rand() % (int)vp.pixel_size()*100)/100;
                float xr = (rand() % (int)vp.pixel_size()*100)/100;
                float zr = (rand() % (int)vp.pixel_size()*100)/100;

                //reset path tracer
                factor = TRACE_FACTOR;
                rec_ctr = MAX_RECURSE_NUM;

                //TODO: dont forget to change this back
                if( !PERSPECTIVE )
                {
                    cur_orig.set_point(y_off + vp.pixel_size() * (i - vp.height() / 2.0 + 0.5) * ay_step
                                             + vp.pixel_size() * (j - vp.width()  / 2.0 + 0.5) * by_step+yr,
                                       x_off + vp.pixel_size() * (i - vp.height() / 2.0 + 0.5) * ax_step
                                             + vp.pixel_size() * (j - vp.width()  / 2.0 + 0.5) * bx_step+xr,
                                       z_off + vp.pixel_size() * (i - vp.height() / 2.0 + 0.5) * az_step
                                             + vp.pixel_size() * (j - vp.width()  / 2.0 + 0.5) * bz_step+zr);
                }
                else
                {
                    ray.set_destination(Point3d(0.f,0.f,-10800.f));
                    Vector3d dir = ray.get_dest() - cur_orig;
                    dir.normalize_vector();
                    ray.set_direction(dir);

                    cur_orig.set_point(y_off+vp.pixel_size() * (j - vp.width() / 2.0 + 0.5),
                                       x_off+vp.pixel_size() * (i - vp.height() / 2.0 + 0.5),
                                       z_off+zw);
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
            _pixels[i*vp.width()*4 + j*4 + 0] = red_sum/SAMPLE_PER_PIXEL;
            _pixels[i*vp.width()*4 + j*4 + 1] = green_sum/SAMPLE_PER_PIXEL;
            _pixels[i*vp.width()*4 + j*4 + 2] = blue_sum/SAMPLE_PER_PIXEL;

            //trace spec light
            /*for (int o = 0; o < _objects.size(); ++o)
            {
            //std::cout<<"Calculate spec light... "<<o<<std::endl;
                if( _tracer->hit(spec_light, _objects[o], info) )
                {
                    //calculate the cos value
                    if(_objects[o]->type() == 3)//triangle
                    {
                        Triangle* cur_tri = reinterpret_cast<Triangle*>(_objects[o]);
                        float cos_val = (cur_tri->get_n())*(environment_dir);
                        if(cos_val < 0)
                            cos_val = 0;

                        _pixels[i*vp.width()*4 + j*4 + 0] = info._color.red()*cos_val + (1-cos_val)*vp.background().red();
                        _pixels[i*vp.width()*4 + j*4 + 1] = info._color.green()*cos_val + (1-cos_val)*vp.background().green();
                        _pixels[i*vp.width()*4 + j*4 + 2] = info._color.blue()*cos_val + (1-cos_val)*vp.background().blue();
                        _pixels[i*vp.width()*4 + j*4 + 3] = 255;//alpha
                    }
                    else if(_objects[o]->type() == 1)//sphere
                    {
                        Sphere* cur_sph = reinterpret_cast<Sphere*>(_objects[o]);
                        Vector3d normal_hit = info._hit_point - cur_orig;
                        normal_hit.normalize_vector();

                        update_spec(info, i, j, normal_hit, amb_dir, spec_light);

                    }
                }
            }*/
        }
    }

    std::cout<<"Ray tracing finished!"<<std::endl;
}
