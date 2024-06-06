#include "../../Headers/items/skill.h"
Skill::Skill(int startX, int startY,string pathskill,string optionpower)
    : x(startX),
      y(startY),
      path(pathskill),
      option(optionpower) {}

void Skill::init(SDL_Renderer* renderer) {
    SDL_Surface* loadedSurface = IMG_Load( path.c_str());
    skillTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    SDL_FreeSurface(loadedSurface);
}
void Skill::render(SDL_Renderer* renderer) const {
    SDL_Rect skillRect = {x, y, ITEM_SIZE, ITEM_SIZE};
    SDL_RenderCopy(renderer, skillTexture, NULL, &skillRect);
}




void Skill::power(vector<Enemy> &enemies,Character &player){
    if(option == "bomb"){
        SDL_Rect skillArea = {x - 110, y - 110, 260, 260};
        for (auto it = enemies.begin(); it != enemies.end();) {
            SDL_Rect enemyRect = {it->x, it->y, SQUARE_SIZE, SQUARE_SIZE};
            if (isCollision(skillArea, enemyRect)) {
                it = enemies.erase(it);
            } else {
                ++it;
            }
        }
    }
}
bool Skill::isCollision(const SDL_Rect& rect1, const SDL_Rect& rect2) {
        return (rect1.x < rect2.x + rect2.w &&
                rect1.x + rect1.w > rect2.x &&
                rect1.y < rect2.y + rect2.h &&
                rect1.y + rect1.h > rect2.y);
}
bool Skill::checkEnemySkillCollision(const Enemy& enemy, const Skill& skill) {
    SDL_Rect enemyRect = {enemy.x, enemy.y, SQUARE_SIZE, SQUARE_SIZE};
    SDL_Rect skillRect = {skill.x, skill.y, ITEM_SIZE, ITEM_SIZE};
    return isCollision(enemyRect, skillRect);
}
