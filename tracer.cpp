#include "tracer.h"

#include <math.h>
#include <cmath>
#include <iostream>

#define kEpsilon_plane 0.001f
#define kEpsilon_sphere 0.001f

Tracer::Tracer()
{
    //nothing
}

Tracer::~Tracer()
{
    //nothing
}

//This is a pretty important function
bool Tracer::hit(Directional_ray& ray, Object* obj, Scene_info& info)
{
    switch( obj->type() )
    {
    case obj_type::Invalid:{
        std::cout<<"Error(Tracer): Invalid object"<<std::endl;
        return false;
        }
    case obj_type::Sphere:{
        Sphere* sph = reinterpret_cast<Sphere*>(obj);
	    double t;
	    Vector3d temp = ray.get_orig() - sph->center();
	    double a = ray.get_dir() * ray.get_dir();
	    double b = (temp * ray.get_dir()) * 2;
	    double c = temp * temp - sph->radius() * sph->radius();
	    double disc	= b * b - 4.0 * a * c;

	    if (disc < 0.0)
		    return false;
	    else
        {
		    double e = sqrt(disc);
            double denom = 2.0 * a;
            t = (-b - e) / denom;    // smaller root

		    if (t > kEpsilon_sphere)
            {
                //tmin = t;
			    //info.normal 	 = (temp + t * ray.d) / radius;
                info._hit_point.set_point(ray.get_orig().get_x() + t * ray.get_dir().get_x(),
                                          ray.get_orig().get_y() + t * ray.get_dir().get_y(),
                                          ray.get_orig().get_z() + t * ray.get_dir().get_z());
                info._color = sph->color();
			    return true;
		    }

		    t = (-b + e) / denom;    // larger root

		    if (t > kEpsilon_sphere)
            {
			    //tmin = t;
			    //info.normal   = (temp + t * ray.d) / radius;
                info._hit_point.set_point(ray.get_orig().get_x() + t * ray.get_dir().get_x(),
                                          ray.get_orig().get_y() + t * ray.get_dir().get_y(),
                                          ray.get_orig().get_z() + t * ray.get_dir().get_z());
                info._color = sph->color();
			    return true;
		    }
	    }
	    break;
        }
    case obj_type::Plane:{
        Plane* pln = reinterpret_cast<Plane*>(obj);
        float t = (pln->get_a() - ray.get_orig()) * pln->get_n() / (ray.get_dir() * pln->get_n());

        if(t > kEpsilon_plane){
            info._hit_point.set_point(ray.get_orig().get_x() + t * ray.get_dir().get_x(),
                                      ray.get_orig().get_y() + t * ray.get_dir().get_y(),
                                      ray.get_orig().get_z() + t * ray.get_dir().get_z());
            info._color = pln->color();
        }
        else
            return false;

        return true;
        break;
        }
    case obj_type::Triangle:{
        Triangle* tri = reinterpret_cast<Triangle*>(obj);
        Vector3d edgeA = tri->get_b() - tri->get_a();
        Vector3d edgeB = tri->get_c() - tri->get_b();
        Vector3d edgeC = tri->get_a() - tri->get_c();
        Vector3d norm = edgeA ^ edgeB;
        norm.normalize_vector();
        tri->set_n(norm);

        double area = std::abs(edgeA*edgeB);//2 times the area of triangle
        float t = (tri->get_a() - ray.get_orig()) * tri->get_n() / (ray.get_dir() * tri->get_n());

        //hit the plane
        if(t > kEpsilon_plane){
            //then inside triangle
            Point3d P = Point3d(ray.get_orig().get_x() + t * ray.get_dir().get_x(),
                                ray.get_orig().get_y() + t * ray.get_dir().get_y(),
                                ray.get_orig().get_z() + t * ray.get_dir().get_z());

            Vector3d edgePA = P - tri->get_a();
            Vector3d edgePB = P - tri->get_b();
            Vector3d edgePC = P - tri->get_c();

            if((norm * (edgeA ^ edgePA) > 0) &&
               (norm * (edgeB ^ edgePB) > 0) &&
               (norm * (edgeC ^ edgePC) > 0))
            {
                info._hit_point = P;
                info._color = tri->color();
                return true;
            }
        }

        break;
        }
    case obj_type::Disc:{
        Disc *dis = reinterpret_cast<Disc*>(obj);
        Point3d a = Point3d(0.f, -(dis->get_n().get_z())/dis->get_n().get_y(), 1.f);
        float t = (a - ray.get_orig()) * dis->get_n() / (ray.get_dir() * dis->get_n());
        float radiusSQ = dis->get_r() * dis->get_r();

        //hit the plane
        if(t > kEpsilon_plane){
            //then inside disc
            Point3d P = Point3d(ray.get_orig().get_x() + t * ray.get_dir().get_x(),
                                ray.get_orig().get_y() + t * ray.get_dir().get_y(),
                                ray.get_orig().get_z() + t * ray.get_dir().get_z());

            if( ((P.get_x()-dis->center().get_x())*(P.get_x()-dis->center().get_x()) +
                 (P.get_y()-dis->center().get_y())*(P.get_y()-dis->center().get_y()) +
                 (P.get_z()-dis->center().get_z())*(P.get_z()-dis->center().get_z()) ) <= radiusSQ)
            {
                info._hit_point = P;
                info._color = dis->color();
                return true;
            }
        }
        break;
        }
    case obj_type::Cylinder:{
        Cylinder* cyl = reinterpret_cast<Cylinder*>(obj);
	    double t;
	    Vector3d rayD = ray.get_dir();
	    Vector3d cylD = cyl->get_dir();
	    Vector3d deltaP = ray.get_orig() - cyl->center();
	    double a =     (rayD-(cylD*(rayD*cylD)))*(rayD-(cylD*(rayD*cylD)));
	    double b = 2*( (rayD-(cylD*(rayD*cylD)))*(deltaP-(cylD*(deltaP*cylD))) );
	    double c = (deltaP-(cylD*(deltaP*cylD)))*(deltaP-(cylD*(deltaP*cylD))) - cyl->get_r()*cyl->get_r();
	    double disc	= b * b - 4.0 * a * c;

	    if (disc < 0.0)
		    return false;
	    else
        {
		    double e = sqrt(disc);
            double denom = 2.0 * a;
            t = (-b - e) / denom;    // smaller root

		    if ( (t > kEpsilon_sphere)&&(t < cyl->get_tmax()) ){
                //tmin = t;
			    //info.normal 	 = (temp + t * ray.d) / radius;
                info._hit_point.set_point(ray.get_orig().get_x() + t * ray.get_dir().get_x(),
                                          ray.get_orig().get_y() + t * ray.get_dir().get_y(),
                                          ray.get_orig().get_z() + t * ray.get_dir().get_z());
                info._color = cyl->color();
			    return true;
		    }

		    t = (-b + e) / denom;    // larger root

		    if ( (t > kEpsilon_sphere)&&(t < cyl->get_tmax()) ){
			    //tmin = t;
			    //info.normal   = (temp + t * ray.d) / radius;
                info._hit_point.set_point(ray.get_orig().get_x() + t * ray.get_dir().get_x(),
                                          ray.get_orig().get_y() + t * ray.get_dir().get_y(),
                                          ray.get_orig().get_z() + t * ray.get_dir().get_z());
                info._color = cyl->color();
			    return true;
		    }
	    }
        break;
        }
    default:
        {
        std::cout<<"Error(Tracer): Unknown type"<<std::endl;
        break;
        }
    }
    return false;
}
