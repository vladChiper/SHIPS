#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


// Declară variabilele globale
extern SDL_Window* window;
extern SDL_Renderer* renderer;

#define TILE_SIZE 50.0f

// Declară funcțiile
void afisareBackground();
void plasareAtacRatat(float x, float y);
void afisareWIN();
