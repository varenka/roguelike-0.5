#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "map.h"
#include "player.h"
#include "ray.h"

using namespace std;


class game
{
    public:
        game();
        virtual ~game();

        void processInput();
        //update all ents based on input
        void tick();
        //print layer that player is on, after processing 1 tick
        void gameLoop();
        void movePlayer(int);
        void spawnPlayer(vector3);
        void spawnItem(item, vector3);
        bool isTransparent(vector3f);
        bool isVisible(vector3);
        bool tileContains(vector3, vector3f);
        void updateLighting();

        map currentMap;
        void printMap(int);
        player currentPlayer;
        bool shouldClose;

        static int stringToInput(string);
};

#define UNKNOWN 0
#define UP 1
#define DOWN 2
#define D 3
#define A 4
#define EXIT 5
#define W 6
#define S 7

#endif // GAME_H
