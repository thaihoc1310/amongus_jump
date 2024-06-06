#ifndef GAME_H
#define GAME_H
#include <iomanip>
#include <algorithm>
#include <thread>
#include <fstream>
#include "gameconstants.h"
#include "../characters/character.h"
#include "../characters/Enemy.h"
#include "../items/Skill.h"
#include "../items/monster.h"
#include "../items/explosion.h"
#include "../items/invisible.h"
#include "../items/nogravity.h"
#include "../characters/bigenemy.h"
#include "../background/background.h"
#include "../characters/ai.h"
using namespace std;
enum GameState {
        MENU,
        PLAYING,
        GAMEOVER,
        HIGHSCORE,
        OPTIONS,
        MULTIPLAYER,
        // Add more states if needed
    };
extern float soundvolume;
extern float musicvolume;
class Game {
public:
    Game();
    ~Game();

    void run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Background* background1;
    Background* background2;
    Character player;
    Character player2;
    AI ai;
    vector<Enemy> enemies;
    vector<BigE> biges;
    vector<Skill> skills;
    vector<Explosion> explosions;
    vector<Invisible> invisibles;
    vector<Monster> monsters;
    vector<Nogravity> nogravities;
    Uint32 startTime;
    Uint32 lastPlayTime;
    GameState gameState;
    string formatTime(int timeInSeconds);
    void initSDL();
    void logSDLError(std::ostream& os, const std::string &msg, bool fatal);
    void drawMenu();
    void drawGameover();
    void drawOptions();
    void drawMulti();
    void handleMenuInput(SDL_Event& e,bool& quit);
    void handlePlayingInput(SDL_Event& e,bool& quit);
    void handleGameoverInput(SDL_Event& e,bool& quit);
    void handleHighscore(SDL_Event& e,bool& quit);
    void handleOptions(SDL_Event& e,bool& quit);
    void handleMulti(SDL_Event& e,bool& quit);
    void update();
    void render();
    void quitSDL();
    void spawnEnemy();
    void spawnBigE();
    void spawnItem();
    void drawHighscore();
    Uint32 getElapsedTime();
    void waitUntilKeyPressed();
    void initElement();
    bool isCollision( const SDL_Rect& rect1,const SDL_Rect& rect2);
    bool ismulti,player1lose,resultSaved,isai,player2win,aiwin;
    void singerplayer();
    void multiplayer();
    void aiplayer();
    Uint32 frameStart;
    Uint32 lastEnemySpawnTime;
    Uint32 lastItemSpawnTime;
    Uint32 lastBigeSpawnTime;
    bool checkPlayerEnemyCollision( Character& player,  Enemy& enemy);
    bool checkPlayerSkillCollision( Character& player,  Skill& skill);
    bool checkPlayerCharacterCollision( Character& player,  Character& player2);
    bool checkPlayerBigeCollision( Character& player,  BigE& bige);
    void buttoncantclick(const string& text, SDL_Color color, int x,int y, TTF_Font* font);
    void buttonclick(const string& path, int x,int y,int &widthtexture,int &heighttexture);
    string easyimage,hardimage,mediumimage;
    bool mousexy(SDL_Rect rect,int mousex,int mousey);

    float frameTime;

};

#endif // GAME_H
