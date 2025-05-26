// #include <SDL3/SDL.h>
// #include <SDL3_ttf/SDL_ttf.h>
// #include <stdbool.h>
// #include "text.h"
// #include "map.h"

// #include <stdio.h>
// #include <string.h>

// void afisareScor(SDL_Renderer* renderer, TTF_Font* font, int playerScore, int botScore) {


//     SDL_Color culoare = {255, 255, 255, 255}; // Alb
//     char scorText[64];
//     snprintf(scorText, sizeof(scorText), "Player: %d   Bot: %d", playerScore, botScore);

//     SDL_Surface* textSurface = TTF_RenderText_Solid(font, scorText, strlen(scorText), culoare);
//     if (!textSurface) {
//         SDL_Log("Eroare la crearea suprafeței textului scor: %s", SDL_GetError());
//         return;
//     }

//     SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//     if (!textTexture) {
//         SDL_Log("Eroare la crearea texturii textului scor: %s", SDL_GetError());
//         SDL_DestroySurface(textSurface);
//         return;
//     }

//     const SDL_FRect textRect = {20, 10, textSurface->w, textSurface->h};
//     SDL_DestroySurface(textSurface);

//     SDL_RenderTexture(renderer, textTexture, NULL, &textRect);
//     SDL_DestroyTexture(textTexture);
    
// }