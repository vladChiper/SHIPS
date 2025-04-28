#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "procesari.h"


// Declară variabilele globale
extern SDL_Window* window;
extern SDL_Renderer* renderer;



// Declară funcțiile
int startGame(float x, float y); // returneaza 1 daca a fost apasat butonul
void afisareStart();
void afisareBackground();
void plasareAtacRatat(float x, float y);
void afisareWIN();
void afisareLOSE();
void afisareTIE();
void afisareBackground1();