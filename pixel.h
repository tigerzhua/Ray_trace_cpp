#ifndef PIXEL_H
#define PIXEL_H

class Pixel
{
    public:

        Pixel(); //make a white one

        ~Pixel();

        Pixel(unsigned char r, unsigned char g, unsigned char b);

		Pixel& operator= (const Pixel& rhs);

        void clear();//make it white

        void blacken();//make it black

        unsigned char red();
        unsigned char green();
        unsigned char blue();

    private:

        unsigned char _red;

        unsigned char _green;

        unsigned char _blue;
};

#endif // PIXEL_H

