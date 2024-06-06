#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H
#include<vector>
#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
const float SCREEN_WIDTH = 1000;
const float SCREEN_HEIGHT = 650;
const float SQUARE_SIZE = 50;
const float ITEM_SIZE = 40;
const float BIGE_SIZE = 200;
static int ENEMY_SPAWN_INTERVAL = 5000;
static int ITEM_SPAWN_INTERVAL = 8000;
static int BIGE_SPAWN_INTERVAL = 28000;
const std::string WINDOW_TITLE = "Among us";
const int FPS = 60;
const float FrameDelay = (float)1000 / FPS;
const SDL_Color textColor = {255, 255, 255, 255};
static Mix_Chunk* sound_cls_item[4];
static Mix_Chunk* sound_gameover;
static Mix_Chunk* sound_monstereat;
static Mix_Chunk* sound_mouseclick;
static Mix_Chunk* sound_jump;
static Mix_Chunk* sound_jump2;
static Mix_Chunk* sound_bg[2];
static Mix_Chunk* sound_enemy[2];
static TTF_Font* font ;
static TTF_Font* font36 ;
static TTF_Font* font68 ;
static TTF_Font* font28 ;
static TTF_Font* font32 ;
static int widthbutton1,heightbutton1,widhbutton2,heightbutton2,widthbutton3,heightbutton3,widthbutton4,heightbutton4;
static int widthbutton5,heightbutton5,widthbutton6,heightbutton6,widthbutton7,heightbutton7,widthbutton8,heightbutton8;
static int timeghost = 4000;
static int timenogravity = 6000;
static bool isDraggingMusic = false;
static bool isDraggingSound = false;
#endif // GAME_CONSTANTS_H
