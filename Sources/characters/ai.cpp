#include "../../Headers/characters/ai.h"
#include <algorithm>

AI::AI(int startX, int startY, int startVelX, int startVelY, double gravity, SDL_Color startColor, std::string left, std::string right, int heart, int sizep)
    : Character(startX, startY, startVelX, startVelY, gravity, startColor, left, right, heart, sizep),
      threatThreshold(100),
      isfast(false){}

double AI::calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void AI::update(const std::vector<Enemy>& enemies, const std::vector<BigE>& biges) {

    int closestThreatDistance = threatThreshold;
    blockedLeft = false;
    blockedRight = false;
    for (const auto& enemy : enemies) {
        double distance = calculateDistance(x, y, enemy.x, enemy.y);
        if (distance < closestThreatDistance) {
            closestThreatDistance = distance;
            if (x < enemy.x) {
                velX = -moveOx;
                blockedRight = true;
                timeright = SDL_GetTicks();
            } else if(x>=enemy.x){
                velX = moveOx;
                blockedLeft = true;
                timeleft = SDL_GetTicks();
            }
            if(y < enemy.y && multiJump <= 10&&SDL_GetTicks() - timejump>500){
                multiJump ++;
                velY = -5;
                timejump =SDL_GetTicks();
            }else if(y < enemy.y && multiJump > 12){
                multiJump = 0;
            }else if(y < enemy.y && multiJump > 10)multiJump ++;
            else if(y>enemy.y)velY = 5;

            if(distance > 60&&blockedLeft){
                velX = 2*moveOx;
                isfast = true;
            }else isfast = false;
            if(distance > 60 && blockedRight && !isfast){
                velX = -2*moveOx;

            }

        }
    }

    if(y==5)velY =9;
    if(x<=SQUARE_SIZE&&x>0){
        velX = moveOx;
        blockedLeft = true;
        timeleft = SDL_GetTicks();

    }
    else if(x+playersize>=SCREEN_WIDTH-SQUARE_SIZE && x+playersize < SCREEN_WIDTH){
        velX = -moveOx;
        blockedRight = true;
        timeright = SDL_GetTicks();
    }

    if(SDL_GetTicks()-timeleft<500 && SDL_GetTicks()- timeright<500&&SDL_GetTicks() - timejump>300 ){
        velY = -12;
        timejump = SDL_GetTicks();

    }
    if (blockedRight && blockedLeft&&SDL_GetTicks() - timejump>300) {
        velY = -9;
        timejump = SDL_GetTicks();
    }


}
