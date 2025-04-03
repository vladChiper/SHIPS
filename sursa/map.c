#include "map.h"

void afisareBackground(){
    SDL_Texture * background = IMG_LoadTexture(renderer, "assets/Naval Battle Assets/bground.png");
    if (!background)
    {
        SDL_Log("Failed to load background: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    SDL_Texture * background1 = IMG_LoadTexture(renderer, "assets/Naval Battle Assets/oceangrid_final.png");
    if (!background1)
    {
        SDL_Log("Failed to load background1: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    // Load the second image
    SDL_Texture * background2 = IMG_LoadTexture(renderer, "assets/Naval Battle Assets/radargrid_final.png");
    if (!background2)
    {
        SDL_Log("Failed to load background2: %s", SDL_GetError());
        SDL_DestroyTexture(background1);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    // Clear the screen
    SDL_RenderClear(renderer);

    /*typedef struct SDL_FRect
{
    float x;
    float y;
    float w;
    float h;
} SDL_FRect;
*/
    SDL_FRect dest = { 0.0f, 0.0f , 1200.0f, 700.0f}; // Full screen
    if (!SDL_RenderTexture(renderer, background, NULL, &dest)) {
    SDL_Log("Failed to render background1: %s", SDL_GetError());
    }
    // Render the first background image
    SDL_FRect dest1 = { 50.0f, 50.0f, 550.0f, 550.0f }; // Left half of the screen
    if (!SDL_RenderTexture(renderer, background1, NULL, &dest1)) {
     SDL_Log("Failed to render background1: %s", SDL_GetError());
    }
    
     // Render the second background image
    SDL_FRect dest2 = { 600.0f, 50.0f, 550.0f, 550.0f }; // Right half of the screen
    if (!SDL_RenderTexture(renderer, background2, NULL, &dest2)) {
        SDL_Log("Failed to render background2: %s", SDL_GetError());
    }
    // Present the renderer
    SDL_RenderPresent(renderer);
}