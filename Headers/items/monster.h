#ifndef MONSTER_H
#define MONSTER_H
#include "../characters/character.h"
class Monster {
public:
   Monster();
   Character* playermon;
   Monster(Character&playerinvisible);
   Uint32 inittime;
   string playermonleft;
   string playermonright;
    void endtime();
    void initplayer(string playerpathleft,string playerpathright);
};

#endif // MONSTER_H


