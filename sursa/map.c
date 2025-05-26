#include "map.h"

void afisareBackground(){
    SDL_RenderClear(renderer);
    SDL_Texture * background = IMG_LoadTexture(renderer, "assets/Naval Battle Assets/marebg.png");
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

    /*typedef struct SDL_FRect
{
    float x;
    float y;
    float w;
    float h;
} SDL_FRect;
*/
    SDL_FRect dest = { 0.0f, 0.0f , WIDTH, HEIGHT}; // Full screen
    if (!SDL_RenderTexture(renderer, background, NULL, &dest)) {
    SDL_Log("Failed to render background1: %s", SDL_GetError());
    }
    // Render the first background image
    SDL_FRect dest1 = { TILE_SIZE_W, TILE_SIZE_H, 11*TILE_SIZE_W, 11*TILE_SIZE_H }; // Left half of the screen
    if (!SDL_RenderTexture(renderer, background1, NULL, &dest1)) {
     SDL_Log("Failed to render background1: %s", SDL_GetError());
    }
    
     // Render the second background image
    SDL_FRect dest2 = { 12*TILE_SIZE_W, TILE_SIZE_H, 11*TILE_SIZE_W, 11*TILE_SIZE_H }; // Right half of the screen
    if (!SDL_RenderTexture(renderer, background2, NULL, &dest2)) {
        SDL_Log("Failed to render background2: %s", SDL_GetError());
    }
    // Present the renderer
    SDL_RenderPresent(renderer);

    // Clean up
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(background1);
    SDL_DestroyTexture(background2);
}

void afisareWIN()
{
    SDL_Texture * image = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\winpage.png");
    if (!image)
    {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    const SDL_FRect srcRect = { 0, 0 , 1536, 1024};  
    const SDL_FRect dstRect = { 0 , 0 , WIDTH, HEIGHT };

    SDL_RenderTexture(renderer, image, &srcRect, &dstRect);

    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(image); // Eliberăm textura după utilizare
    
}
void afisareLOSE()
{
    SDL_Texture * image = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\losepage.png");
    if (!image)
    {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    const SDL_FRect srcRect = { 0, 0 , 1536, 1024};  
    const SDL_FRect dstRect = { 0, 0 , WIDTH, HEIGHT };

    SDL_RenderTexture(renderer, image, &srcRect, &dstRect);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(image); // Eliberăm textura după utilizare
    
}
void afisareTIE()
{
    SDL_Texture * image = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\tie.png");
    if (!image)
    {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    const SDL_FRect srcRect = { 0, 0 , 1700, 2800};  
    const SDL_FRect dstRect = { 9*TILE_SIZE_W , 0 , 6*TILE_SIZE_W, 10*TILE_SIZE_H };

    SDL_RenderTexture(renderer, image, &srcRect, &dstRect);

    SDL_Texture * retry = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\playagain.png");
    if (!image)
    {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    const SDL_FRect srcRect1 = { 0, 0 , 100, 100};  
    const SDL_FRect dstRect1 = { 11*TILE_SIZE_W , 9*TILE_SIZE_H , 2*TILE_SIZE_W, 2*TILE_SIZE_H };

    SDL_RenderTexture(renderer, retry, &srcRect1, &dstRect1);
   
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(image); // Eliberăm textura după utilizare
    SDL_DestroyTexture(retry); // Eliberăm textura după utilizare
    
}
void afisareStart()
{
    SDL_Texture * image = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\startmenu.png");
    if (!image)
    {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    const SDL_FRect srcRect = { 0, 0 ,1536, 1024};  
    const SDL_FRect dstRect = { 0, 0 , WIDTH, HEIGHT };

    SDL_RenderTexture(renderer, image, &srcRect, &dstRect);

   
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(image); // Eliberăm textura după utilizare
}

int startGame(float x, float y)
{
    return (x >= 0.4*WIDTH && x <= 0.66*WIDTH && y >= 0.6*HEIGHT && y <= 0.75*  HEIGHT); // returneaza 1 daca a fost apasat butonul
}

void afisareBackground1(){
    SDL_RenderClear(renderer);
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

    
    // Clear the screen

    SDL_FRect dest = { 0.0f, 0.0f , WIDTH, HEIGHT}; // Full screen
    if (!SDL_RenderTexture(renderer, background, NULL, &dest)) {
    SDL_Log("Failed to render background1: %s", SDL_GetError());
    }
    // Render the first background image
    SDL_FRect dest1 = { 6.5*TILE_SIZE_W, TILE_SIZE_H, 11*TILE_SIZE_W, 11*TILE_SIZE_H }; // Left half of the screen
    if (!SDL_RenderTexture(renderer, background1, NULL, &dest1)) {
     SDL_Log("Failed to render background1: %s", SDL_GetError());
    }
    
     // Render the second background image
    // Present the renderer
    SDL_RenderPresent(renderer);

    // Clean up
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(background1);
}