#include "player.h"

#include <stdlib.h>
#include <time.h>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;

#define TILE_SIZE 50.0f

Player_t * initBot();
void atacBot(Player_t * player);
void plasareAtacRatatBot(float x, float y);
void plasareNaveVizualDistrusePlayer(float x, float y);