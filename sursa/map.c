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

    // Clean up
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(background1);
    SDL_DestroyTexture(background2);
}

void afisareWIN()
{
    SDL_Texture * image = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\youwin.png");
    if (!image)
    {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    const SDL_FRect srcRect = { 0, 0 , 700, 300};  
    const SDL_FRect dstRect = { 250.0f , 150.0f , 700, 300 };

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
    const SDL_FRect dstRect1 = { 550.0f , 450.0f , 100, 100 };

    SDL_RenderTexture(renderer, retry, &srcRect1, &dstRect1);
   
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(image); // Eliberăm textura după utilizare
    SDL_DestroyTexture(retry); // Eliberăm textura după utilizare
    
}
void afisareLOSE()
{
    SDL_Texture * image = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\youlose.png");
    if (!image)
    {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    const SDL_FRect srcRect = { 0, 0 , 300, 300};  
    const SDL_FRect dstRect = { 350.0f , 50.0f , 500, 500 };

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
    const SDL_FRect dstRect1 = { 550.0f , 450.0f , 100, 100 };

    SDL_RenderTexture(renderer, retry, &srcRect1, &dstRect1);
   
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(image); // Eliberăm textura după utilizare
    SDL_DestroyTexture(retry); // Eliberăm textura după utilizare
    
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
    const SDL_FRect dstRect = { 450.0f , 0.0f , 300, 500 };

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
    const SDL_FRect dstRect1 = { 550.0f , 450.0f , 100, 100 };

    SDL_RenderTexture(renderer, retry, &srcRect1, &dstRect1);
   
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(image); // Eliberăm textura după utilizare
    SDL_DestroyTexture(retry); // Eliberăm textura după utilizare
    
}
// afisare start
void afisareStart()
{
    SDL_Texture * image = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\startbutton.png");
    if (!image)
    {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    const SDL_FRect srcRect = { 0, 0 , 1200, 700};  
    const SDL_FRect dstRect = { 0, 0 , 1200, 700 };

    SDL_RenderTexture(renderer, image, &srcRect, &dstRect);

   
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(image); // Eliberăm textura după utilizare
}

int startGame(float x, float y)
{
    return (x >= 400 && x <= 700 && y >= 200 && y <= 300); // returneaza 1 daca a fost apasat butonul
}