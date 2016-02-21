#ifndef MAP_H
#define MAP_H

#include "tile.h"
#include "io.h"
#include "vector3.h"
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <sstream>

using namespace std;

class map
{
    public:
        map();
        virtual ~map();
        void randomizeTiles();
        void setSize(vector3);
        void print(int, int);
        tile* getTile(vector3);
        void setTile(vector3, tile);
        void setTileId(vector3, int, int);

        vector3 size;
        vector<vector<vector<tile> > > _map;
        string name;
        vector<char> tileset;
};
#endif //MAP_H
