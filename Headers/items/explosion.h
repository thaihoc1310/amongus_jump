#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <SDL.h>
#include "../characters/character.h"
#include "../characters/enemy.h"
#include<vector>
class Explosion {
public:
   Explosion();
   int x, y;
   string path;
   Explosion(int startX, int startY,string path,Uint32 starttime);
   void render(SDL_Renderer* renderer) const;
   void init(SDL_Renderer* renderer);
   SDL_Texture* explosionTexture;
   SDL_Rect skillArea;
   void explosion(SDL_Renderer* renderer)const;
   Uint32 inittime;

};

#endif // EXPLOSION_H

