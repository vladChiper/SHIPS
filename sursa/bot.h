#include "player.h"

#include <stdlib.h>
#include <time.h>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "procesari.h"

extern SDL_Window* window;
extern SDL_Renderer* renderer;


Player_t * initBot(int score);
void atacBot(Player_t * player);  
void plasareAtacRatatBot(float x, float y);
void plasareNaveVizualDistrusePlayer(float x, float y);
// void afisareImagineRandom(Player_t* player);