#include "colors.h"

color::color()
{

}

color::~color()
{

}

string color::custom(string in, int _color, int modifier)
{
    stringstream ss;
    ss << "\033[" << modifier << ";" << _color << "m" << in << "\033[0m";
    return ss.str();
}
