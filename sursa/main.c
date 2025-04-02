#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "map.h"

SDL_Window* window;
SDL_Renderer* renderer;

int main()
{
    if ( !(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) )
    {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    window = SDL_CreateWindow(
        "BATTLESHIPS",          // Titlul ferestrei
        1150,                   // Lățimea ferestrei
        700,                   // Înălțimea ferestrei
        0    // Opțiuni ale ferestrei
    );
    if (!window) 
    {
        SDL_Log("Error creating window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    renderer = SDL_CreateRenderer(window, NULL);
    SDL_SetRenderVSync(renderer, 1);
    SDL_Rect viewport = { 0, 0, 1150, 700 }; // Dimensiunea ferestrei
    SDL_SetRenderViewport(renderer, &viewport);
    if(renderer == NULL)
    {
        SDL_Log("SDL_CreateRenderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

   

    bool running = true;
    while(running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
                break;
            }
        }
        afisareBackground();
    }
     

SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

}
