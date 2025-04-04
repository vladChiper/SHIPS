#include "player.h"

#include <stdlib.h>
#include <time.h>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;

Player_t * initBot();