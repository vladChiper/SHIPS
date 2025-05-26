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
        //SDL_Log("Bot hit ship at (%d, %d)", (int)x, (int)y);
    }
    else
    {
        player->ships[(int)x][(int)y] = -1; // Marchează atacul ca ratat
        //SDL_Log("Bot missed attack at (%d, %d)", (int)x, (int)y);
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
    const SDL_FRect dstRect = { 2.00f*TILE_SIZE_W + x * TILE_SIZE_W , 2.00f*TILE_SIZE_H + y* TILE_SIZE_H , TILE_SIZE_W, TILE_SIZE_H };

    
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
    const SDL_FRect dstRect = { 2.00f*TILE_SIZE_W + x * TILE_SIZE_W , 2.00f*TILE_SIZE_H + y* TILE_SIZE_H , TILE_SIZE_W, TILE_SIZE_H };

    
    SDL_RenderTexture(renderer, nava1, &srcRect, &dstRect);
   
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(nava1); // Eliberăm textura după utilizare

}
// void afisareImagineRandom(Player_t* player) {

//     // Încarcă imaginea care va fi afișată
//     SDL_Texture* image = IMG_LoadTexture(renderer, "assets\\Naval Battle Assets\\Tokens.png");
//     if (!image) {
//         SDL_Log("Failed to load image: %s", SDL_GetError());
//         SDL_SetRenderTarget(renderer, NULL); // Restaurează renderer-ul original
//         return;
//     }

//     // Afișează imaginea de 5 ori în poziții aleatorii
//     SDL_FRect dstRects[5];
//     int x, y;
//     int coords[5][2]; // Stocăm coordonatele pentru fiecare imagine
//     for (int i = 0; i < 5; i++) {
//         do {
//             x = rand() % 10; // Coordonată aleatorie pe matricea player-ului
//             y = rand() % 10;
//         } while (player->ships[x][y] == 2 || player->ships[x][y] == -1); // Verificăm dacă nava este deja atacată

//         coords[i][0] = x; // Salvăm coordonatele
//         coords[i][1] = y;

//         dstRects[i] = (SDL_FRect){2.00f * TILE_SIZE_W + x * TILE_SIZE_W, 2.00f * TILE_SIZE_H + y * TILE_SIZE_H, TILE_SIZE_W, TILE_SIZE_H};

//         const SDL_FRect srcRect = {0, 0, 32, 32}; // Poziția din sprite sheet
//         SDL_RenderTexture(renderer, image, &srcRect, &dstRects[i]);
//         SDL_RenderPresent(renderer);

//         SDL_Delay(500); // Așteaptă 500ms între afișări
//     }

//     // Alege o singură poziție dintre cele 5
//     int selectedIndex = rand() % 5;
//     int selectedX = coords[selectedIndex][0];
//     int selectedY = coords[selectedIndex][1];

//     // Eliberăm resursele
//     SDL_DestroyTexture(image);

//     // Apelează atacBot cu coordonatele selectate
//     atacBot(player, (float)selectedX, (float)selectedY);
// }