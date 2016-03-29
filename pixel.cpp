#include "pixel.h"

Pixel::Pixel()
{
    //build a white pixel
    _red = 255;
    _green = 255;
    _blue = 255;
}

Pixel::~Pixel()
{
    //dtor
}

Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b)
{
    _red = r;
    _green = g;
    _blue = b;
}

Pixel& Pixel::operator= (const Pixel& rhs)
{
    if(&rhs != this)
    {
        _red = rhs._red;
        _green = rhs._green;
        _blue = rhs._blue;
    }
}

void Pixel::clear()
{
    _red = 255;
    _green = 255;
    _blue = 255;
}

void Pixel::blacken()
{
    _red = 0;
    _green = 0;
    _blue = 0;
}

unsigned char Pixel::red()
{
    return _red;
}

unsigned char Pixel::green()
{
    return _green;
}

unsigned char Pixel::blue()
{
    return _blue;
}
