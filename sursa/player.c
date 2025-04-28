#include "player.h"
#include <string.h>
#include <stdlib.h>

// Funcția pentru inițializarea unui jucător
Player_t* initPlayer(const char* name, int score) {
    Player_t* player = (Player_t*)malloc(sizeof(Player_t));
    if (player == NULL) {
        return NULL; // Eșec la alocarea memoriei
    }

    // Inițializează numele jucătorului
    strncpy(player->name, name, sizeof(player->name) - 1);
    player->name[sizeof(player->name) - 1] = '\0'; // Asigură terminarea cu null

    // Inițializează punctajul și contorul de nave
    player->score = score;
    player->ships_counter = 0;
    player->ships_destroyed = 0; // Inițializăm contorul de nave distruse

    // Inițializează lista de nave (exemplu: 5 nave)
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++) {
            player->ships[i][j] = 0; // 0 indică că nava nu este plasată
        }
    }

    return player;
}

// Funcția pentru plasarea unei nave
int plasareNave(Player_t* player, float x, float y) {
    // Verifică dacă coordonatele sunt valide
    if (x < 2*TILE_SIZE_W || x >= 13*TILE_SIZE_W || y < 2*TILE_SIZE_H || y >= 13*TILE_SIZE_H) {
        return -1; // Coordonate invalide
    }
    x -= 2*TILE_SIZE_W; // Ajustează coordonatele pentru a fi pe marginea pătratului de 50x50
    y -= 2*TILE_SIZE_H; // Ajustează coordonatele pentru a fi pe marginea pătratului de 50x50

    int latime = TILE_SIZE_W;
    int inaltime = TILE_SIZE_H;
    // Ajustează coordonatele pentru a fi pe marginea pătratului de 50x50
    int gridX = ((int)x / latime); // Rotunjire la cel mai apropiat multiplu de 50
    int gridY = ((int)y / inaltime) ;

    player->ships_counter++; // Incrementăm contorul de nave plasate

    // Plasează nava în matricea jucătorului
    player->ships[gridX][gridY] = 1; // Împărțim la 50 pentru a obține indexul din matrice

    return 0; // Plasare reușită
}

int procesareAtac(Player_t * bot, float x, float y)
{
    // Verifică dacă coordonatele sunt valide
    if (x < 13*TILE_SIZE_W || x >= (WIDTH-TILE_SIZE_W) || y < 2*TILE_SIZE_H || y >= (HEIGHT-TILE_SIZE_H) ) {
        return 0; // Coordonate invalide
    }
    //SDL_Log("Coordonate valide pentru atac: (%f, %f)", x, y);
    x -= 13*TILE_SIZE_W; // Ajustează coordonatele pentru a fi pe marginea pătratului de 50x50
    y -= 2*TILE_SIZE_H; // Ajustează coordonatele pentru a fi pe marginea pătratului de 50x50

    //SDL_Log("Coordonate neajustate pentru atac: (%f, %f)", x, y);

    // Ajustează coordonatele pentru a fi pe marginea pătratului de 50x50
    int latime = TILE_SIZE_W; // aici s a facut un debug adevarat
    int inaltime = TILE_SIZE_H;
    int gridX = (int)(x / latime); // Rotunjire la cel mai apropiat multiplu de 50
    int gridY = (int)(y / inaltime);

    //SDL_Log("Coordonate ajustate pentru atac: (%d, %d)", gridX, gridY);

    if(bot->ships[gridX][gridY] == 1) // Dacă nava este lovită
    {
        bot->ships[gridX][gridY] = 2; // Elimină nava din matrice
        bot->ships_destroyed++ ; // Decrementăm contorul de nave plasate
        return 1; // Lovitură reușită
    }
    else{
        bot->ships[gridX][gridY] = -1; // atac ratat
        return 1; // Lovitură ratată
    }

}