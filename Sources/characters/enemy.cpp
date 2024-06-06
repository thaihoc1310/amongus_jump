#include "../../Headers/characters/enemy.h"
Enemy::Enemy(int startX, int startY, int startVelX, int startVelY,string pathenemy)
    : x(startX),
      y(startY),
      velX(startVelX),
      velY(startVelY),
      path(pathenemy),
      eTexture(NULL) {}

void Enemy::move() {
    x += velX;
    y += velY;

    if (x < 0 || x + SQUARE_SIZE > SCREEN_WIDTH) {
        velX = -velX;
    }
    if (y < 0 || y + SQUARE_SIZE > SCREEN_HEIGHT) {
        velY = -velY;
    }
}
void Enemy::init(SDL_Renderer* renderer) {
    SDL_Surface* loadedSurface = IMG_Load( path.c_str());
    eTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    SDL_FreeSurface(loadedSurface);
}
void Enemy::render(SDL_Renderer* renderer) const {
    Uint32 sprite = SDL_GetTicks()/ 150 % 25;
    if(sprite >4)sprite = 0;
    SDL_Rect characterRect = {x, y, SQUARE_SIZE, SQUARE_SIZE};
    SDL_Rect srcrect = { 0, sprite * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE };
    SDL_RenderCopy(renderer, eTexture, &srcrect, &characterRect);
    // SDL_DestroyTexture(eTexture);
}

