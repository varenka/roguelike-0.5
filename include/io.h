#ifndef IO_H
#define IO_H


#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

class io
{
    public:
        io();
        virtual ~io();
        static int randomInt(int, int);
        static int roundDown(float);
        static int roundUp(float);
};

#endif // IO_H

