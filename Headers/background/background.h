#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "../games/gameconstants.h"
class Background {
public:
    SDL_Texture* texture;
    SDL_Rect destRect;
    float scrollSpeed;

    Background(SDL_Renderer* renderer, const std::string& imagePath);

    void scroll();

    void render(SDL_Renderer* renderer) ;
};
#endif // BACKGROUND_H
