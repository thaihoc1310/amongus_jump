#include "../../Headers/characters/bigenemy.h"
BigE::BigE(int startX, int startY, int startVelX, int startVelY,string pathbige)
   : x(startX),
     y(startY),
     velX(startVelX),
     velY(startVelY),
     path(pathbige),
     eTexture(NULL),
     conclusiontimes(1000000),
     isonscreen(false) {}

void BigE::move() {
   x += velX;
   y += velY;
    if(((x >= 0 && x + BIGE_SIZE <= SCREEN_WIDTH)&&(y >= 0 && y + BIGE_SIZE <= SCREEN_HEIGHT))&&!isonscreen){
        conclusiontimes = 5;
        isonscreen = true;
        if(this->path == "Sources/image/biggreenball.png")conclusiontimes = 3;
    }
    if ((x < 0 || x + BIGE_SIZE > SCREEN_WIDTH)&& (conclusiontimes <= 5)) {
       if(conclusiontimes){
        velX = -velX;
        conclusiontimes --;
       }
    }
    if ((y < 0 || y + BIGE_SIZE > SCREEN_HEIGHT) &&(conclusiontimes <= 5 )) {
        if(conclusiontimes){
            velY = -velY;
            conclusiontimes --;
        }
    }
}
void BigE::init(SDL_Renderer* renderer) {
   SDL_Surface* loadedSurface = IMG_Load( path.c_str());
   eTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
   SDL_FreeSurface(loadedSurface);
}
void BigE::render(SDL_Renderer* renderer) const {
    Uint32 sprite = SDL_GetTicks()/ 150 % 25;
    if(sprite >4)sprite = 0;
    SDL_Rect characterRect = {x, y, BIGE_SIZE, BIGE_SIZE};
    SDL_Rect srcrect = { 0, sprite * BIGE_SIZE, BIGE_SIZE, BIGE_SIZE };
    SDL_RenderCopy(renderer, eTexture, &srcrect, &characterRect);
    // SDL_DestroyTexture(eTexture);
}

