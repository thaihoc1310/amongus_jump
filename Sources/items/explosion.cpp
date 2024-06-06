#include "../../Headers/items/explosion.h"
Explosion::Explosion(int startX, int startY,string pathExplosion,Uint32 starttime)
    : x(startX),
      y(startY),
      path(pathExplosion),
      explosionTexture(NULL),
      inittime(starttime),
      skillArea({startX - 130, startY - 130, 300, 300}) {}

void Explosion::init(SDL_Renderer* renderer) {
    SDL_Surface* explosionSurface = IMG_Load( path.c_str());
    explosionTexture = SDL_CreateTextureFromSurface( renderer, explosionSurface );
    SDL_FreeSurface(explosionSurface);
}
void Explosion::render(SDL_Renderer* renderer) const {

    Uint32 sprite = (SDL_GetTicks()-inittime)/ 40 % 9;
    SDL_Rect srcexplosionrect = { sprite*298, 0, 299, 303 };
    SDL_RenderCopy(renderer, explosionTexture, &srcexplosionrect, &skillArea);
}



