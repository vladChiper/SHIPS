#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "map.h"
#include "player.h"

SDL_Window* window;
SDL_Renderer* renderer;

Player_t * player;
Player_t * bot;

int main()
{
    if ( !(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) )
    {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    window = SDL_CreateWindow(
        "BATTLESHIPS",          // Titlul ferestrei
        1200,                   // Lățimea ferestrei
        700,                   // Înălțimea ferestrei
        0    // Opțiuni ale ferestrei
    );

    SDL_SetWindowIcon(window, IMG_Load("assets/Naval Battle Assets/Pixel-Art-Ship.png"));

    if (!window) 
    {
        SDL_Log("Error creating window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    renderer = SDL_CreateRenderer(window, NULL);
    SDL_SetRenderVSync(renderer, 1);
    
    if(renderer == NULL)
    {
        SDL_Log("SDL_CreateRenderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }


    player = initPlayer("Player");
   

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
            if(SDL_EVENT_MOUSE_BUTTON_DOWN == event.type)
            {
                SDL_Log("Mouse button pressed at (%f, %f)", event.button.x, event.button.y);
                float x = event.button.x;
                float y = event.button.y;
                plasareNave(player, x, y);
                for(int i = 0; i < 10; i++)
                {
                    for(int j = 0; j < 10; j++)
                    {
                        if(player->ships[i][j] == 1)
                        {
                           
                            SDL_Log("Ship placed at (%c, %d)", i + 'A' , j + 1);
                        }
                    }
                }
            }

        }
        afisareBackground();
    }
     

SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

}
