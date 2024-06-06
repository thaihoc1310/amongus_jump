#ifndef INVISIBLE_H
#define INVISIBLE_H
#include "../characters/character.h"
class Invisible {
public:
   Invisible();
   Character* player;
   Invisible(Character&playerinvisible,Uint32 starttime);
   SDL_Texture* explosionTexture;
   Uint32 inittime;
   string playerleft;
   string playerright;
   bool ghostmonster;
    void endtime();
    void initplayer(string playerpathleft,string playerpathright);
//    void maintain();
};

#endif // EXPLOSION_H

