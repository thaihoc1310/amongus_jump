#ifndef NOGRAVITY_H
#define NOGRAVITY_H
#include <SDL.h>
#include "../characters/character.h"
#include<vector>
class Nogravity {
public:
   Nogravity();
   Character* player;
   Nogravity(Character& playergravity,Uint32 starttime);
   Uint32 inittime;
//   string playerleft;
//   string playerright;
    void endtime();
    void initplayer();
};

#endif // NOGRAVITY_H




