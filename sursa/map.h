#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#define MAP_WIDTH 21
#define MAP_HEIGHT 13
#define TILE_SIZE 60

// Declară variabilele globale
extern SDL_Window* window;
extern SDL_Renderer* renderer;


// Declară funcțiile
void afisareBackground();
