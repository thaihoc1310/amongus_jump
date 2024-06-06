#include "../../Headers/items/monster.h"
Monster::Monster(Character& playerinvisible)
    : playermon(&playerinvisible)
    {}
void Monster::endtime() {
    playermon->pathleft = playermonleft;
    playermon->pathright = playermonright;
    playermon->playersize = 50;
    playermon->moveOx = 5;
    playermon->ismonster=false;
    playermon->path = playermon->pathright;
}
void Monster::initplayer(string playerpathleft,string playerpathright) {
    playermonleft = playerpathleft;
    playermonright = playerpathright;
    playermon->pathleft="Sources/image/mtblackleft.png";
    playermon->playersize = 70;
    playermon->isghost = false;
    playermon->numlives = 1;
    playermon->ismonster = true;
    playermon->moveOx = 3;
    playermon->pathright="Sources/image/mtblackright.png";
    playermon->path = playermon->pathright;
}

