#include "ray.h"

ray::ray()
{
    //ctor
}

ray::~ray()
{
    //dtor
}

void ray::set(vector3f e, vector3f d)
{
    endpoint = e;
    direction = d;
}

void ray::setr(ray r)
{
    endpoint = r.endpoint;
    direction = r.direction;
}

void ray::unit()
{
    ray r;
    r.set(endpoint, direction);
    float sx, sz;
    sx = endpoint.x;
    sz = endpoint.z;
    endpoint.x -= sx;
    endpoint.z -= sz;
    direction.x -= sx;
    direction.z -= sz;
}

float ray::slope()
{
    ray r;
    r.set(endpoint, direction);
    r.unit();
    //cout << "Returning the result "
    return r.direction.z / r.direction.x;
}

string ray::gets()
{
    stringstream ss;
    ss << endpoint.gets() << " | " << direction.gets();
    return ss.str();
}
