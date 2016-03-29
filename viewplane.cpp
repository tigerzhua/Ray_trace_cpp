#include "viewplane.h"
#include "math.h"

Viewplane::Viewplane()
{
    _width = 0;
    _height = 0;
    _pixel_size = 1;
    _num_sample = 1;
    _background.blacken();
    _ref = Point3d();
    _A = Vector3d();
    _B = Vector3d();
}

Viewplane::Viewplane(int width, int height,
                     Vector3d A, Vector3d B)
{
    _width = width;
    _height = height;
    _pixel_size = 1;
    _A = A;
    _B = B;
    _background.blacken();

    _n = A ^ B;
}

void Viewplane::set_pixel_size(float s)
{
    _pixel_size = s;
}

Viewplane::~Viewplane()
{
    //nothing
}

float Viewplane::pixel_size()
{
    return _pixel_size;
}

int Viewplane::num_sample()
{
    return _num_sample;
}

Pixel Viewplane::background()
{
    return _background;
}

Vector3d Viewplane::A()
{
    return _A;
}

Vector3d Viewplane::B()
{
    return _B;
}

int Viewplane::height()
{
    return _height;
}

int Viewplane::width()
{
    return _width;
}

Point3d Viewplane::ref_point()
{
    return _ref;
}

void Viewplane::set_background(Pixel bg)
{
    _background = bg;
}

void Viewplane::set_ref(Point3d p)
{
    _ref = p;
}

void Viewplane::resize(int width, int height)
{
    _width = width;
    _height = height;
}
