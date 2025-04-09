#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#define NUMAR_NAVE 3 // Numărul de nave pentru fiecare jucător

// Declară variabilele globale
extern SDL_Window* window;
extern SDL_Renderer* renderer;


typedef struct {
    char name[50]; // Numele jucătorului
    int score;     // Punctajul jucătorului
    int ships[10][10];  // Lista de nave ale jucătorului (exemplu: 5 nave)
    int ships_counter;      // Numărul de lovituri primite
    int ships_destroyed;     // Numărul de nave distruse
    
} Player_t ; // Structura pentru jucător

// Declară funcțiile
int plasareNave(Player_t * player, float x, float y);
Player_t * initPlayer(const char * name);
void plasareAtacRatat(float x, float y);
