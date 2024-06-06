#ifndef BIGENEMY_H
#define BIGENEMY_H
#include "../games/gameconstants.h"
using namespace std;
class BigE {
public:
    int x, y;
    double velX, velY;
    int conclusiontimes;
    bool isonscreen;
    BigE(int startX, int startY, int startVelX, int startVelY,string pathbige);
    string path;
    void move();
    void move2();
    void render(SDL_Renderer* renderer)const;
    void init(SDL_Renderer* renderer);
    SDL_Texture* eTexture;
};

#endif // BIGENEMY_H



