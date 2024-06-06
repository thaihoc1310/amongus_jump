#ifndef AI_H
#define AI_H
#include "../games/gameconstants.h"
#include "character.h"
#include "enemy.h"
#include "bigenemy.h"
#include <vector>
#include <cmath>
class AI : public Character {
public:
    AI(int startX, int startY, int startVelX, int startVelY, double gravity, SDL_Color startColor, std::string left, std::string right, int heart, int sizep);
    void update(const std::vector<Enemy>& enemies, const std::vector<BigE>& biges);

    int threatThreshold;
    int multiJump = 0;
    double calculateDistance(int x1, int y1, int x2, int y2);
    bool blockedLeft,blockedRight;
    Uint32 timeleft,timeright,timejump;
    bool isfast ;
};

#endif // AI_H
