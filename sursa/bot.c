#include "bot.h"

Player_t * initBot()
{
    Player_t * bot;
    bot = initPlayer("Bot");
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

}