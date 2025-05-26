#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <time.h>
#include "map.h"
#include "player.h"
#include "procesari.h"
#include "bot.h"
#include "text.h"

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
        WIDTH,                   // Lățimea ferestrei
        HEIGHT,                   // Înălțimea ferestrei
        0    // Opțiuni ale ferestrei
    );

    SDL_SetWindowIcon(window, IMG_Load("assets\\Naval Battle Assets\\Pixel-Art-Ship.png"));

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

    
    // if (TTF_Init() == -1) {
    //     SDL_Log( "Eroare la initializarea SDL_ttf: %s\n", SDL_GetError());
    //     exit(1);
    // }
    // TTF_Font* font = TTF_OpenFont("assets\\Naval Battle Assets\\font\\font.ttf", 24);
    // if (!font) {
    //     SDL_Log("Eroare la deschiderea fontului: %s\n", SDL_GetError());
    //     exit(1);
    // }


    player = initPlayer("Player", 0);
    char playerName[50];
    bot = initBot(0);
   
    afisareStart();
    do {
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT) {
            SDL_Log("Quit event received");
            break;
        }
        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            float x = event.button.x;
            float y = event.button.y;
            if (startGame(x, y) == 1) {
                afisareBackground();
                player = initPlayer(playerName, 0); // Reinitializează jucătorul cu numele introdus
                // Introducerea numelui jucătorului

                break;
            }
        }
    } while (1);

    bool running = true;
    while(running)
    {
        //afisarePlaceYourShips(renderer, NULL, 0);
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
                    // SDL_Log("Plasare nava la (%f, %f)", x, y);
                    for(int i = 0; i < 10; i++)
                    {
                        for(int j = 0; j < 10; j++)
                        {
                            if(player->ships[i][j] == 1)
                            {

                                afisareBackground();
                                plasareNaveVizual(i, j);
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
                        if (bot->ships_destroyed == NUMAR_NAVE){
                            playerWin = 1;
                        }
                         // Așteaptă 1 secundă înainte de a continua
                        if (playerWin == 0)
                        {
                            //SDL_Delay(1000);
                            //afisareImagineRandom(player);
                            atacBot(player);
                        }
        
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
                    if (bot->ships_destroyed == NUMAR_NAVE && player->ships_destroyed < NUMAR_NAVE)
                    {
                        playerWin = 1;
                        botWin = 0;
                        SDL_RenderClear(renderer);
                        afisareWIN();
                        player->score += 1;
                    
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
                                    
                                    switch(retry(x, y)) {
                                        case 1: // Dacă utilizatorul apasă pe retry
                                            player = initPlayer("Player", player->score);
                                            bot = initBot(bot->score); // Reinitializează jocul
                                            afisareBackground();
                                            retrying = false; // Ieși din bucla de retry
                                            break;
                                        case 2: // Dacă utilizatorul apasă pe quit
                                            running = false;
                                            retrying = false;
                                            break;
                                        // case 3: // daca jucatorul apasa pe leaderboard
                                        //     SDL_Log("Scorul jucătorului: %d", player->score);
                                        //     afisareScor(renderer, font, player->score, bot->score);
                                        //     break;
                                    }
                                }
                            }
                        }
                    }
                    else if (player->ships_destroyed == NUMAR_NAVE && bot->ships_destroyed < NUMAR_NAVE)
                    {
                        playerWin = 0;
                        botWin = 1;
                        SDL_RenderClear(renderer);
                        afisareLOSE();
                        bot->score += 1;
                    
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
                    
                                    switch(retry(x, y)) {
                                        case 1: // Dacă utilizatorul apasă pe retry
                                            player = initPlayer("Player", player->score);
                                            bot = initBot(bot->score); // Reinitializează jocul
                                            afisareBackground();
                                            retrying = false; // Ieși din bucla de retry
                                            break;
                                        case 2: // Dacă utilizatorul apasă pe quit
                                            running = false;
                                            retrying = false;
                                            break;
                                        // case 3: // daca jucatorul apasa pe leaderboard
                                        //     afisareScor(renderer, font, player->score, bot->score);
                                        //     SDL_RenderPresent(renderer);
                                        //     break;
                                    }

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
    
    // TTF_Quit();
    SDL_Quit();

}