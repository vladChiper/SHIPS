#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "player.h"
#include "map.h"


extern SDL_Window* window;
extern SDL_Renderer* renderer;

#define WIDTH 1080
#define TILE_SIZE_W WIDTH / 24
#define HEIGHT 720
#define TILE_SIZE_H HEIGHT / 14

// Declară funcțiile
void plasareNaveVizual(float x, float y);

void plasareNaveVizualDistruseBot(float x, float y);
void plasareAtacRatat(float x, float y);
int retry(float x, float y);