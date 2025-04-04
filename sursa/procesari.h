#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "map.h"
#include "player.h"

extern SDL_Window* window;
extern SDL_Renderer* renderer;

#define TILE_SIZE 50.0f

// Declară funcțiile
void plasareNaveVizual(float x, float y);
int procesareAtac(Player_t * bot, float x, float y);
void plasareNaveVizualDistruseBot(float x, float y);