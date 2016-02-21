#include "map.h"

map::map()
{
    size.set(1, 1, 1);
    name = "uninitialized";
    tileset.resize(25);
    stringstream ss;
    for(int i = 0; i < 24; i ++) {
        ss << random();
        char p;
        ss >> p;
        tileset[i] = p;
    }
}

map::~map()
{
    //dtor
    _map.clear();
}

void map::setSize(vector3 _v)
{
    size.setv(_v);
    _map.resize(size.y);
    for (int i = 0; i < size.y; i++) {
    _map[i].resize(size.x);

    for (int j = 0; j < size.x; j++)
      _map[i][j].resize(size.z);
    }
}

void map::randomizeTiles()
{
    for (int i = 0; i < size.y; i++) {
        for (int j = 0; j < size.x; j++) {
            for (int f = 0; f < size.z; f++) {
                //cout << "set _map[" << j << "][" << i << "][" << f << "] to a w" << endl;
                if(io::randomInt(1, 10) == 1) {
                    _map[j][i][f].c = WALL_DEFAULT;
                    _map[j][i][f].lastc = WALL_DEFAULT;
                    _map[j][i][f].color = FG_GRAY;
                    _map[j][i][f].ids[0] = WALL;
                    _map[j][i][f].known = false;
                    _map[j][i][f].visible = false;
                }else {
                    _map[j][i][f].c = FLOOR_DEFAULT;
                    _map[j][i][f].lastc = FLOOR_DEFAULT;
                    _map[j][i][f].color = FG_LIGHT_GRAY;
                    _map[j][i][f].ids[0] = FLOOR;
                    _map[j][i][f].known = false;
                    _map[j][i][f].visible = false;
                }
            }
        }
    }
}

/*void map::print(int layer, int width)
{
    vector3 dist;
    for (int j = 0; j < size.z; j++) {
        for (int i = 0; i < size.x; i++) {
            dist.set(i, layer, j);
            if()
            cout << _map[i][layer][j].getString();
            //cout << _map[i][layer][j].c;
            //cout << _map[i][layer][j].ids.size();
            //cout << _map[i][layer][j].ids[0];
        }
        cout << endl;
    }
    cout << "Layer: " << layer << endl;
}*/

tile* map::getTile(vector3 pos)
{
    return &_map[pos.x][pos.y][pos.z];
}

void map::setTile(vector3 pos, tile t)
{
    _map[pos.x][pos.y][pos.z] = t;
}

void map::setTileId(vector3 pos, int index, int _id)
{
    _map[pos.x][pos.y][pos.z].ids[index] = _id;
}
