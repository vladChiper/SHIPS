#include "procesari.h"


void plasareNaveVizual(float x, float y)
{
    //SDL_Log("Plasare nava vizual la (%f, %f)", x, y);
    SDL_Texture * nava1 = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\Pixel-Art-Ship.png");
    if (!nava1)
    {
        SDL_Log("Failed to load nava 1: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    const SDL_FRect srcRect = { 0, 0 , 301, 312};  
    const SDL_FRect dstRect = {  100.0f+ y* TILE_SIZE, 100.0f + x * TILE_SIZE, TILE_SIZE, TILE_SIZE };

    
    SDL_RenderTexture(renderer, nava1, &srcRect, &dstRect);
   
    SDL_RenderPresent(renderer);
}

void plasareNaveVizualDistruseBot(float x, float y)
{
    SDL_Texture * nava1 = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\Tokens.png");
    if (!nava1)
    {
        SDL_Log("Failed to load nava 1: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    const SDL_FRect srcRect = { 96, 0 , 32, 32};  
    const SDL_FRect dstRect = {  100.0f+ y* TILE_SIZE, 650.0f + x * TILE_SIZE, TILE_SIZE, TILE_SIZE };

    
    SDL_RenderTexture(renderer, nava1, &srcRect, &dstRect);
   
    SDL_RenderPresent(renderer);

}

int procesareAtac(Player_t * bot, float x, float y)
{
    // Verifică dacă coordonatele sunt valide
    if (x < 649.0f || x >= 1150.0f || y < 100.0f || y >= 650.0f) {
        return -1; // Coordonate invalide
    }
    SDL_Log("Coordonate valide pentru atac: (%f, %f)", x, y);
    x -= 650.0f; // Ajustează coordonatele pentru a fi pe marginea pătratului de 50x50
    y -= 100.0f; // Ajustează coordonatele pentru a fi pe marginea pătratului de 50x50

    // Ajustează coordonatele pentru a fi pe marginea pătratului de 50x50
    int gridX = ((int)x / 50); // Rotunjire la cel mai apropiat multiplu de 50
    int gridY = ((int)y / 50);

    SDL_Log("Coordonate ajustate pentru atac: (%d, %d)", gridX, gridY);

    if(bot->ships[gridX][gridY] == 1) // Dacă nava este lovită
    {
        bot->ships[gridX][gridY] = 2; // Elimină nava din matrice
        bot->ships_destroyed++ ; // Decrementăm contorul de nave plasate
        return 1; // Lovitură reușită
    }


    
}