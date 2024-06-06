#include "../../Headers/items/nogravity.h"
Nogravity::Nogravity(Character& playerinvisible,Uint32 starttime)
    : player(&playerinvisible),
    inittime(starttime)
    {}
void Nogravity::endtime() {
    player->gravityx = 0.6;
    player->isgravity = true;
}
void Nogravity::initplayer() {
    player->gravityx = 0;
    player->isgravity = false;

}



