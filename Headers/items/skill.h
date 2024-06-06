#ifndef SKILL_H
#define SKILL_H
#include "../games/gameconstants.h"
#include "../characters/character.h"
#include "../characters/enemy.h"
class Skill {
public:
    Skill();
    int x, y;
    Skill(int startX, int startY,string path,string optionpower);
    void render(SDL_Renderer* renderer) const;
    void init(SDL_Renderer* renderer);
    SDL_Texture* skillTexture;
    SDL_Texture* explosionTexture;
    string path;
    void power(vector<Enemy> &enemies,Character &player);
    bool isCollision(const SDL_Rect& rect1, const SDL_Rect& rect2);
    bool checkEnemySkillCollision(const Enemy& enemy, const Skill& skill);
    string option;

};

#endif // SKILL_H
