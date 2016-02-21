#include "player.h"

player::player()
{
    position.set(0, 0, 0);
    health = 100;
    stamina = 200;
    hunger = 100;
    thirst = 100;
    temperature = 98.0f;
    temperatureThreshold = 10.0f;
    hypothermicThreshold = 95.0f;
    c = '@';
    sightDistance = 6;
}

player::~player()
{
    //dtor
}

void player::spawn(vector3 _pos)
{
    position.setv(_pos);
}

void player::giveItem(item _i)
{

}

void player::move(vector3 v)
{
    cout << color::custom("Moving player to vector: ", FG_CYAN, BOLD) << color::custom(v.gets(), FG_CYAN, BOLD) << endl;
    position = v;
}

void player::moveToTile(tile* currentTile, tile* t)
{
    currentTile->ids[0] = currentTile->ids[1];
    currentTile->ids.resize(1);
    currentTile->ids[0] = FLOOR;
    currentTile->c = FLOOR_DEFAULT;
    t->reset();
    cout << "Moving to a tile" << endl;
    t->ids.resize(2);
    t->ids[1] = FLOOR;
    t->ids[0] = PLAYER;
    t->reset();

    t->c = PLAYER_DEFAULT;
}
