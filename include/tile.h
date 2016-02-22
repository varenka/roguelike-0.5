#ifndef TILE_H
#define TILE_H

#include "entity.h"
#include "vector3.h"
#include "colors.h"
#include <vector>

using namespace std;

class tile
{
    public:
        tile();
        virtual ~tile();
        char c;
        int color;
        int flags;
        int size;
        //true if the player has seen the tile
        bool known;
        bool visible;
        //the character the tile had the last time the player saw it
        char lastc;
        //int id;
        vector3 position;

        vector<int> ids;
        //returns a string containing c with flags and color applied
        string getString();
        string getc();
        string getlastc();

        bool isPassable();
        bool isPassableUpwards();
        bool isPassableDownwards();

        void reset();
        void setup(int, int);

        static char getDefault(int);

};

#define PLAYER 0
#define FLOOR 1
#define WALL 2
#define STAIRS_UP 3
#define STAIRS_DOWN 4
#define AIR 5
#define GRASS 6
#define NPC 7
#define DOOR 8
#define DOOR_OPEN 9

#define PLAYER_DEFAULT '@'
#define FLOOR_DEFAULT '.'
#define WALL_DEFAULT '#'
#define STAIRS_UP_DEFAULT '<'
#define STAIRS_DOWN_DEFAULT '>'
#define AIR_DEFAULT '.'
#define GRASS_DEFAULT '~'
#define NPC_DEFAULT 'N'
#define DOOR_DEFAULT '+'
#define DOOR_OPEN_DEFAULT '*'

#endif
