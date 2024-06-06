#include "../../Headers/background/background.h"
Background::Background(SDL_Renderer* renderer, const std::string& imagePath)
    : scrollSpeed(1){
        SDL_Surface* surface = IMG_Load(imagePath.c_str());
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        destRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    }

void Background::scroll(){
    destRect.x -= scrollSpeed;
    if (destRect.x + destRect.w <= 0) {
        destRect.x = SCREEN_WIDTH;
    }
}
void Background::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}
