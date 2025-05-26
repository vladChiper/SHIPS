#include "procesari.h"


void plasareNaveVizual(float x, float y)
{
    //SDL_Log("Plasare nava vizual la (%f, %f)", x, y);
    SDL_Texture * nava1 = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\ship.png");
    if (!nava1)
    {
        SDL_Log("Failed to load nava 1: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    const SDL_FRect srcRect = { 0, 0 , 780, 688};  
    const SDL_FRect dstRect = {  2*TILE_SIZE_W + x* TILE_SIZE_W, 2*TILE_SIZE_H + y * TILE_SIZE_H, TILE_SIZE_W, TILE_SIZE_H };

    
    SDL_RenderTexture(renderer, nava1, &srcRect, &dstRect);
   
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(nava1); // Eliberăm textura după utilizare
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
    const SDL_FRect dstRect = {1 + 13*TILE_SIZE_W + x * TILE_SIZE_W , 2*TILE_SIZE_H+ y* TILE_SIZE_H , TILE_SIZE_W, TILE_SIZE_H };

    
    SDL_RenderTexture(renderer, nava1, &srcRect, &dstRect);
   
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(nava1); // Eliberăm textura după utilizare

}
void plasareAtacRatat(float x, float y)
{
    SDL_Texture * image = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\Tokens.png");
    if (!image)
    {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    const SDL_FRect srcRect = { 64, 0 , 32, 32};  
    const SDL_FRect dstRect = {13*TILE_SIZE_W + x * TILE_SIZE_W , 2*TILE_SIZE_H+ y* TILE_SIZE_H , TILE_SIZE_W, TILE_SIZE_H };

    
    SDL_RenderTexture(renderer, image, &srcRect, &dstRect);
   
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(image); // Eliberăm textura după utilizare

}


int retry(float x, float y)
{
    if(y > 0.79 * HEIGHT && y < 0.91 * HEIGHT){
        if(x > 0.12 * WIDTH && x < 0.31 * WIDTH) // Verifică dacă coordonatele sunt în interiorul butonului "Retry"
        {
            return 1; // Returnează 1 pentru a indica că utilizatorul a apăsat pe butonul "Retry"
        }
        if( x > 0.64 * WIDTH && x < 0.87 * WIDTH) // Verifică dacă coordonatele sunt în interiorul butonului "exit"
        {
            return 2; // Returnează 2 pentru a indica că utilizatorul a apăsat pe butonul "exit"
        }
        if( x > 0.35 * WIDTH && x < 0.61 * WIDTH) // Verifică dacă coordonatele sunt în interiorul butonului "Leaderboard"
        {
            return 3; // Returnează 3 pentru a indica că utilizatorul a apăsat pe butonul "Leaderboard"
        }
    }

}