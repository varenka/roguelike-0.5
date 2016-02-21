#ifndef PLAYER_H
#define PLAYER_H

#include "vector2.h"
#include "vector3.h"
#include "item.h"
#include "colors.h"
#include "tile.h"

class player
{
    public:
        player();
        virtual ~player();
        void update();
        void spawn(vector3);
        void giveItem(item);

        void move(vector3);
        void moveToTile(tile*, tile*);

        int health, stamina, hunger, thirst;
        int sightDistance;
        /* temperatureThreshold is the minimum difference between
        the environment temp and the player's temp at which the player's
        temp will begin changing. it is increased by wearing insulated clothes,
        being in buildings, etc.*/
        /* hypothermicThreshold is the body temp at which the player is hypothermic*/
        float temperature, temperatureThreshold, hypothermicThreshold;
        vector3 position;

        char c;
};
#endif
