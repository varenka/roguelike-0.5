#ifndef RAY_H
#define RAY_H
#include "vector3.h"

class ray
{
    public:
        ray();
        virtual ~ray();
        void set(vector3f, vector3f);
        void setr(ray);

        vector3f endpoint, direction;

        //converts endpoint to a unit vector
        void unit();
        float slope();

        string gets();
};

#endif // RAY_H
