#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <time.h>
#include "map.h"
#include "player.h"
#include "procesari.h"
#include "bot.h"

SDL_Window* window;
SDL_Renderer* renderer;

Player_t * player;
Player_t * bot;

int main()
{
    //srand(time(NULL)); // Initializează generatorul de numere aleatoare
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


    player = initPlayer("Player", 0);
    bot = initBot(0);
   
    afisareBackground();
    bool running = true;
    while(running)
    {
        SDL_Event event;
        int playerWin = 0;
        int botWin = 0;
        while(SDL_PollEvent(&event))
        {
            
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
                break;
            }
            if(SDL_EVENT_MOUSE_BUTTON_DOWN == event.type)
            {
                //SDL_Log("Mouse button pressed at (%f, %f)", event.button.x, event.button.y);
                float x = event.button.x;
                float y = event.button.y;
                if (player ->ships_counter < NUMAR_NAVE)
                {
                    plasareNave(player, x, y);
                    SDL_Log("Plasare nava la (%f, %f)", x, y);
                    for(int i = 0; i < 10; i++)
                    {
                        for(int j = 0; j < 10; j++)
                        {
                            if(player->ships[i][j] == 1)
                            {

                                afisareBackground();
                                plasareNaveVizual(j, i);
                                // SDL_Log("Nava plasata la (%d, %d)", i, j);
                            }
                        }
                    }
                }
                else if ( (bot->ships_destroyed < NUMAR_NAVE) && (player->ships_destroyed < NUMAR_NAVE) )
                {
                    if(procesareAtac(bot, x, y))
                    {
                        // SDL_Log("Atac la (%f, %f)", x, y);
                        for(int i = 0; i < 10; i++) // LOOP PT AFISAREA NAVELOR BOTILOR 
                        {
                            for(int j = 0; j < 10; j++)
                            {
                                if(bot->ships[i][j] == 2)
                                {
                                    //SDL_Log("Nava lovita la (%d, %d)", i, j);
                                    afisareBackground();
                                    plasareNaveVizualDistruseBot(i, j);
                                }
                                else if(bot->ships[i][j] == -1)
                                {
                                    //SDL_Log("Nava ratata la (%d, %d)", i, j);
                                    afisareBackground();
                                    plasareAtacRatat(i, j);
                                }
                            }
                        }
                        atacBot(player);
                        {
                            for(int i = 0; i < 10; i++) 
                            {
                                for(int j = 0; j < 10; j++) // LOOP  pt nave player / atac bot
                                {
                                    if(player->ships[i][j] == 2)
                                    {
                                        //SDL_Log("Nava lovita la (%d, %d)", i, j);
                                        afisareBackground();
                                        plasareNaveVizualDistrusePlayer(i, j);
                                    }
                                    else if(player->ships[i][j] == -1)
                                    {
                                        //SDL_Log("Nava ratata la (%d, %d)", i, j);
                                        afisareBackground();
                                        plasareAtacRatatBot(i, j);
                                    }
                                }
                            }
                        }
                    }
                }
                else 
                {
                    // verificam cine a castigat
                    if (bot->ships_destroyed == NUMAR_NAVE && player->ships_destroyed < NUMAR_NAVE)
                    {
                        playerWin = 1;
                        botWin = 0;
                        SDL_Log("Player a castigat!");
                        afisareWIN();
                    
                        // Așteaptă apăsarea pe retry
                        bool retrying = true;
                        while (retrying) {
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_EVENT_QUIT) {
                                    running = false;
                                    retrying = false;
                                    break;
                                }
                                if (SDL_EVENT_MOUSE_BUTTON_DOWN == event.type) {
                                    float x = event.button.x;
                                    float y = event.button.y;
                    
                                    if (retry(x, y)) { // Dacă utilizatorul apasă pe retry
                                        player = initPlayer("Player", player->score + 1);
                                        bot = initBot(bot->score); // Reinitializează jocul
                                        afisareBackground();
                                        retrying = false; // Ieși din bucla de retry
                                    }
                                }
                            }
                        }
                    }
                    else if (player->ships_destroyed == NUMAR_NAVE && bot->ships_destroyed < NUMAR_NAVE)
                    {
                        playerWin = 0;
                        botWin = 1;
                        SDL_Log("bot a castigat!");
                        afisareLOSE();
                    
                        // Așteaptă apăsarea pe retry
                        bool retrying = true;
                        while (retrying) {
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_EVENT_QUIT) {
                                    running = false;
                                    retrying = false;
                                    break;
                                }
                                if (SDL_EVENT_MOUSE_BUTTON_DOWN == event.type) {
                                    float x = event.button.x;
                                    float y = event.button.y;
                    
                                    if (retry(x, y)) { // Dacă utilizatorul apasă pe retry
                                        player = initPlayer("Player", player->score);
                                        bot = initBot(bot->score + 1); // Reinitializează jocul
                                        afisareBackground();
                                        retrying = false; // Ieși din bucla de retry
                                    }
                                }
                            }
                        }
                    }
                    else if (player->ships_destroyed == NUMAR_NAVE && bot->ships_destroyed == NUMAR_NAVE)
                    {
                        SDL_Log("EGALITATE!");
                        afisareTIE();
                    
                        // Așteaptă apăsarea pe retry
                        bool retrying = true;
                        while (retrying) {
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_EVENT_QUIT) {
                                    running = false;
                                    retrying = false;
                                    break;
                                }
                                if (SDL_EVENT_MOUSE_BUTTON_DOWN == event.type) {
                                    float x = event.button.x;
                                    float y = event.button.y;
                    
                                    if (retry(x, y)) { // Dacă utilizatorul apasă pe retry
                                        player = initPlayer("Player", player->score);
                                        bot = initBot(bot->score); // Reinitializează jocul
                                        afisareBackground();
                                        retrying = false; // Ieși din bucla de retry
                                    }
                                }
                            }
                        }
                    }
                    
                }
            }
        }
        
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Log("scorul final a fost player %d bot %d", player->score, bot->score);
    
    // Eliberăm memoria pentru player și bot
    if (player != NULL) {
        free(player);
       
    }
    
    if (bot != NULL) {
        free(bot);
    }
    
    SDL_Quit();

}