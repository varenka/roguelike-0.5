#include "vector3.h"

vector3::vector3()
{
    //ctor
}

vector3::~vector3()
{
    //dtor
}

void vector3::set(int _x, int _y, int _z)
{
    x = _x;
    y = _y;
    z = _z;
}

void vector3::setv(vector3 _v)
{
    x = _v.x;
    y = _v.y;
    z = _v.z;
}

string vector3::gets()
{
    stringstream ss;
    ss << "(" << x << ", " << y << ", " << z << ")";
    return ss.str();
}

int vector3::distanceTo(vector3 v)
{
    float x1 = x;
    float z1 = z;
    float x2 = v.x;
    float z2 = v.z;

    float xs = pow((x2 - x1), 2);
    float zs = pow((z2 - z1), 2);
    return sqrt(xs + zs);
}

int vector3::xDistanceTo(vector3 v)
{
    if(x > v.x) {
        return x - v.x;
    }else if(x < v.x) {
        return v.x - x;
    }
    /*if x == v.x*/
    return 0;
}

int vector3::zDistanceTo(vector3 v)
{
    if(z > v.z) {
        return z - v.z;
    }else if(z < v.z) {
        return v.z - z;
    }
    return 0;
}

vector3 vector3::origin()
{
    vector3 o;
    o.set(0, 0, 0);
    return o;
}

vector3f::vector3f()
{

}

vector3f::~vector3f()
{

}

void vector3f::set(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}

void vector3f::setv(vector3f v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

string vector3f::gets()
{
    stringstream ss;
    ss << "(" << x << ", " << y << ", " << z << ")";
    return ss.str();
}

float vector3f::distanceTo(vector3f v)
{
    float x1 = x;
    float z1 = z;
    float x2 = v.x;
    float z2 = v.z;

    float xs = pow((x2 - x1), 2);
    float zs = pow((z2 - z1), 2);
    return sqrt(xs + zs);
}
