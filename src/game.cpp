#include "game.h"

game::game()
{
    //ctor
    shouldClose = false;
}

game::~game()
{
    //dtor
}

void game::processInput()
{
    //cout << "Executed processInput" << endl;
    string input;
    cout << "> ";
    getline(cin, input);
    cout << endl;
    switch(stringToInput(input)) {
        case A:
            cout << "Move left" << endl;
            movePlayer(A);
            break;
        case UP:
            cout << "Move up" << endl;
            movePlayer(UP);
            break;
        case D:
            cout << "Move right" << endl;
            movePlayer(D);
            break;
        case DOWN:
            cout << "Move down" << endl;
            movePlayer(DOWN);
            break;
        case EXIT:
            shouldClose = true;
            break;
        case W:
            movePlayer(W);
            break;
        case S:
            movePlayer(S);
            break;
        default:
            cout << "Unknown input." << endl;
            break;
    }
}

void game::tick()
{
    //cout << "Executed tick" << endl;
    //update all npcs, ents, and player

    /*switch(currentMap.getTile(currentPlayer.position).ids[0]) {
        case FLOOR:

            break;
        default:
            break;
    }*/
}

void game::gameLoop()
{
    processInput();
    tick();
    printMap(currentPlayer.position.y);
    cout << "Current player pos is: " << currentPlayer.position.gets() << endl;
    cout << "X distance from origin: " << currentPlayer.position.xDistanceTo(vector3::origin()) << endl;
    cout << "Z distance from origin: " << currentPlayer.position.zDistanceTo(vector3::origin()) << endl;
}

int game::stringToInput(string in)
{
    if(in == "up" || in == "u") return UP;
    if(in == "down") return DOWN;
    if(in == "d") return D;
    if(in == "a") return A;
    if(in == "exit") return EXIT;
    if(in == "w") return W;
    if(in == "s") return S;
    return UNKNOWN;
}

void game::movePlayer(int direction)
{
    switch(direction) {
        case UP:
            cout << "if " << currentPlayer.position.y  << " == " << currentMap.size.y - 1 << endl;
            if(!(currentPlayer.position.y == currentMap.size.y - 1)) {
                vector3 mpos;
                mpos.setv(currentPlayer.position);
                mpos.y ++;
                if(currentMap.getTile(mpos)->isPassableUpwards()) {
                    currentPlayer.moveToTile(currentMap.getTile(currentPlayer.position), currentMap.getTile(mpos));
                    currentPlayer.move(mpos);
                    cout << "Executed move player up" << endl;

                }
            }
            break;
        case DOWN:
            if(!(currentPlayer.position.y == 0)) {
                vector3 mpos;
                mpos.setv(currentPlayer.position);
                mpos.y --;
                if(currentMap.getTile(mpos)->isPassableDownwards()) {
                    currentPlayer.moveToTile(currentMap.getTile(currentPlayer.position), currentMap.getTile(mpos));
                    currentPlayer.move(mpos);
                    cout << "Executed move player down" << endl;
                }
            }
            break;
        case D:
            if(!(currentPlayer.position.x == currentMap.size.x - 1)) {
                vector3 mpos;
                mpos.setv(currentPlayer.position);
                mpos.x ++;
                if(currentMap.getTile(mpos)->isPassable()) {
                    currentPlayer.moveToTile(currentMap.getTile(currentPlayer.position), currentMap.getTile(mpos));
                    currentPlayer.move(mpos);
                    cout << "Executed move player right" << endl;
                }
            }
            break;
        case A:
            if(!currentPlayer.position.x == 0) {
                vector3 mpos;
                mpos.setv(currentPlayer.position);
                mpos.x --;
                if(currentMap.getTile(mpos)->isPassable()) {
                    currentPlayer.moveToTile(currentMap.getTile(currentPlayer.position), currentMap.getTile(mpos));
                    currentPlayer.move(mpos);
                    cout << "Executed move player left" << endl;
                }
            }
            break;
        case W:
            if(!currentPlayer.position.z == 0) {
                cout << "z position is not 0" << endl;
                vector3 mpos;
                mpos.setv(currentPlayer.position);
                mpos.z --;
                if(currentMap.getTile(mpos)->isPassable()) {
                    cout << "mpos is passable" << endl;
                    currentPlayer.moveToTile(currentMap.getTile(currentPlayer.position), currentMap.getTile(mpos));
                    currentPlayer.move(mpos);
                }
            }
            break;
        case S:
            if(!(currentPlayer.position.z == currentMap.size.z - 1)) {
                vector3 mpos;
                mpos.setv(currentPlayer.position);
                mpos.z ++;
                if(currentMap.getTile(mpos)->isPassable()) {
                    currentPlayer.moveToTile(currentMap.getTile(currentPlayer.position), currentMap.getTile(mpos));
                    currentPlayer.move(mpos);
                }
            }
            break;
        default:
            cout << "Error: argument to moveplayer is not defined as a direction: " << direction << endl;
            break;
    }
    cout << "The player is currently at " << currentPlayer.position.gets() << ", which has a char of " << currentMap.getTile(currentPlayer.position)->c << " and a size of " << currentMap.getTile(currentPlayer.position)->ids.size() << endl;
}

void game::spawnPlayer(vector3 target)
{
    currentPlayer.moveToTile(currentMap.getTile(target), currentMap.getTile(target));
    currentPlayer.move(target);
}

void game::printMap(int layer)
{
    vector3 dist;
    for (int j = 0; j < currentMap.size.z; j++) {
        for (int i = 0; i < currentMap.size.x; i++) {
            dist.set(i, layer, j);
            if(currentPlayer.position.distanceTo(dist) <= currentPlayer.sightDistance && isVisible(dist)) {
                cout << currentMap._map[i][layer][j].getString();
                currentMap._map[i][layer][j].known = true;
            }else if(currentMap._map[i][layer][j].known) {
                cout << color::custom(currentMap.getTile(dist)->getlastc(), FG_LIGHT_BLUE, FAINT);
            }else {
                cout << "?";
            }
            //cout << _map[i][layer][j].c;
            //cout << _map[i][layer][j].ids.size();
            //cout << _map[i][layer][j].ids[0];
        }
        cout << endl;
    }
    cout << "Layer: " << layer << endl;
}

bool game::isVisible(vector3 v)
{
    vector3f checkEndpoint;
    checkEndpoint.set(currentPlayer.position.x + 0.5, currentPlayer.position.y, currentPlayer.position.z + 0.5);
    vector3f checkDir;
    checkDir.set(v.x + 0.5, v.y, v.z + 0.5);
    ray check;
    check.set(checkEndpoint, checkDir);
    vector3f checkPoint;
    checkPoint.setv(checkEndpoint);
    float i = 0;
    while(i < checkEndpoint.distanceTo(checkDir)) {
        //cout << "There are a lot of these." << endl;
        cout << "i = " << i << endl;
        checkPoint.z += check.slope();
        checkPoint.x ++;
        cout << "checking: " << checkPoint.gets() << endl;
        if(!(isTransparent(checkPoint))) {
            return false;
        }
        i ++;
        /*if(i > checkEndpoint.distanceTo(checkDir)) {
            checkPoint += check.slope() % i;
            checkPoint.x
        }*/
    }
    return true;
}

bool game::isTransparent(vector3f v)
{
    for(int j = 0; j < currentMap.size.x; j++) {
        for(int i = 0; i < currentMap.size.z; i++) {
            vector3 check;
            check.set(j, currentPlayer.position.y, i);
            if(tileContains(check, v) && !(currentMap.getTile(check)->isPassable())) {
                return false;
            }
        }
    }
    return true;
}

void game::updateLighting()
{

}

//returns true if the tile at t contains point p
bool game::tileContains(vector3 t, vector3f p)
{
    vector3f topLeft, bottomRight;
    bottomRight.set(t.x + 1, t.y, t.z + 1);
    topLeft.set(t.x, t.y, t.z);
    if(p.x <= bottomRight.x && p.x >= topLeft.x ) {
        if(p.z <= topLeft.z && p.z >= bottomRight.z) {
            return true;
        }
    }
    return false;
}
