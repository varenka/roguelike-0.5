#include "tile.h"

tile::tile()
{
    //ctor
    ids.resize(1);
}

tile::~tile()
{
    //dtor
}

string tile::getString()
{
    stringstream ss;
    ss << c;
    return color::custom(ss.str(), color, flags);
}

bool tile::isPassable()
{
    cout << "Checking if a tile with an id of " << ids[0] << " is passable: ";
    switch(ids[0]) {
        case WALL:
            return false;
            break;
        case DOOR:
            return false;
            break;
        case FLOOR:
            return true;
            break;
        case STAIRS_DOWN:
            return true;
            break;
        case STAIRS_UP:
            return true;
        default:
            return false;
            break;
    }
    cout << endl;
}

//TODO
//going up checks if the player is below a downward stair, and vice versa
bool tile::isPassableUpwards()
{
    switch(ids[0]) {
        case STAIRS_DOWN:
            return true;
            break;
        default:
            return false;
            break;
    }
}

bool tile::isPassableDownwards()
{
    switch(ids[0]) {
        case STAIRS_UP:
            return true;
            break;
        default:
            return false;
            break;
    }
}

char tile::getDefault(int _id)
{
    switch(_id) {
        case PLAYER:
            return PLAYER_DEFAULT;
            break;
        case FLOOR:
            return FLOOR_DEFAULT;
            break;
        case WALL:
            return WALL_DEFAULT;
            break;
        default:
            return '?';
            break;
    }
}

void tile::reset()
{
    c = getDefault(ids[0]);
}

void tile::setup(int _id, int _color)
{
    c = getDefault(_id);
    lastc = getDefault(_id);
    color = _color;
    ids[0] = _id;
    known = false;
}

string tile::getc()
{
    string ret;
    ret = c;
    return ret;
}

string tile::getlastc()
{
    string ret;
    ret = lastc;
    return ret;
}
