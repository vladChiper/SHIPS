#include "bot.h"

Player_t * initBot(int score)
{
    Player_t * bot;
    bot = initPlayer("Bot", score);
    if (bot == NULL)
    {
        SDL_Log("Failed to initialize bot player: %s", SDL_GetError());
        return NULL;
    }
    // plaseaza 10 nave random pt bot
    for (int i = 0; i < NUMAR_NAVE; i++)
    {
        float x = rand() % 10;
        float y = rand() % 10;
        while (bot->ships[(int)x][(int)y] == 1) // Verifică dacă nava este deja plasată
        {
            x = rand() % 10;
            y = rand() % 10;
        }
        bot->ships[(int)x][(int)y] = 1; // Plasează nava
        SDL_Log("Bot placed ship at (%d, %d)", (int)x, (int)y);
    }
    bot->ships_counter = NUMAR_NAVE; // Setează contorul de nave plasate
    return bot;

}

void atacBot(Player_t * player)
{
    float x = rand() % 10;
    float y = rand() % 10;
    while(player->ships[(int)x][(int)y] == 2 || player->ships[(int)x][(int)y] == -1) // Verifică dacă nava este deja atacată
    {
        x = rand() % 10;
        y = rand() % 10;
    }
    if (player->ships[(int)x][(int)y] == 1) // Verifică dacă nava este lovită
    {
        player->ships[(int)x][(int)y] = 2; // Marchează nava ca fiind lovită
        player->ships_destroyed++; // Incrementăm contorul de nave distruse
        SDL_Log("Bot hit ship at (%d, %d)", (int)x, (int)y);
    }
    else
    {
        player->ships[(int)x][(int)y] = -1; // Marchează atacul ca ratat
        SDL_Log("Bot missed attack at (%d, %d)", (int)x, (int)y);
    }

}

void plasareAtacRatatBot(float x, float y)
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
    const SDL_FRect dstRect = {100.0f + x * TILE_SIZE , 100.0f+ y* TILE_SIZE , TILE_SIZE, TILE_SIZE };

    
    SDL_RenderTexture(renderer, image, &srcRect, &dstRect);
   
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(image); // Eliberăm textura după utilizare

}

void plasareNaveVizualDistrusePlayer(float x, float y)
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
    const SDL_FRect dstRect = {100.0f + x * TILE_SIZE , 100.0f+ y* TILE_SIZE , TILE_SIZE, TILE_SIZE };

    
    SDL_RenderTexture(renderer, nava1, &srcRect, &dstRect);
   
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(nava1); // Eliberăm textura după utilizare

}