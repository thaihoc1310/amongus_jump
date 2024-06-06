#ifndef CHARACTER_H
#define CHARACTER_H
#include "../games/gameconstants.h"
#include "../games/soundconstants.h"
using namespace std;
extern float soundvolume;
class Character {
public:
    int x, y;
    bool isJumping;
    bool isJumping2;
    double velX, velY;
    double aceX, aceY;
    string path, pathleft ,pathright;
    SDL_Color startColor;
    bool isKeyPressed[SDL_NUM_SCANCODES] = {false};
    SDL_Texture* chTexture;
    Character(int startX, int startY, int startVelX, int startVelY,double grvt,SDL_Color startColor,string left,string right,int heart,int sizep);
    int playersize;
    void handleInput();
    void handleInput2();
    void GravityCalculation();
    void VelocityCalculation();
    void PositionCalculation();
    void render(SDL_Renderer* renderer);
    bool ismonster,isghost,isgravity;
    int numlives;
    double gravityx;
    double moveOx,moveOy;
    int countghost;
    int countnogravity;
};

#endif // CHARACTER_H
