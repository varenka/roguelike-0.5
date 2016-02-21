#include <time.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <math.h>
#ifndef VECTOR3_H
#define VECTOR3_H

using namespace std;

class vector3
{
    public:
        vector3();
        virtual ~vector3();
        void set(int, int, int);
        void setv(vector3);
        string gets();
        int distanceTo(vector3);
        int xDistanceTo(vector3);
        int zDistanceTo(vector3);

        int x, y, z;

        static vector3 origin();
};

class vector3f
{
    public:
        vector3f();
        virtual ~vector3f();

        void set(float, float, float);
        void setv(vector3f);
        string gets();

        float distanceTo(vector3f);

        float x, y, z;
};
#endif
