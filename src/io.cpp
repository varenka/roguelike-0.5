#include "io.h"

io::io()
{
    //ctor
}

io::~io()
{
    //dtor
}

int io::randomInt(int _min, int _max)
{
    return rand() % _max + _min;
}

int io::round(float f)
{
    return (int)f/*+ 0.5*/;
}
