#include "player.h"
#include <string.h>
#include <stdlib.h>

// Funcția pentru inițializarea unui jucător
Player_t* initPlayer(const char* name) {
    Player_t* player = (Player_t*)malloc(sizeof(Player_t));
    if (player == NULL) {
        return NULL; // Eșec la alocarea memoriei
    }

    // Inițializează numele jucătorului
    strncpy(player->name, name, sizeof(player->name) - 1);
    player->name[sizeof(player->name) - 1] = '\0'; // Asigură terminarea cu null

    // Inițializează punctajul și contorul de nave
    player->score = 0;
    player->ships_counter = 0;

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
    if (x < 100.0f || x >= 650.0f || y < 100.0f || y >= 650.0f) {
        return -1; // Coordonate invalide
    }
    x -= 100.0f; // Ajustează coordonatele pentru a fi pe marginea pătratului de 50x50
    y -= 100.0f; // Ajustează coordonatele pentru a fi pe marginea pătratului de 50x50

    // Ajustează coordonatele pentru a fi pe marginea pătratului de 50x50
    int gridX = ((int)x / 50) * 50; // Rotunjire la cel mai apropiat multiplu de 50
    int gridY = ((int)y / 50) * 50;

    player->ships_counter++; // Incrementăm contorul de nave plasate

    // Plasează nava în matricea jucătorului
    player->ships[gridX / 50][gridY / 50] = 1; // Împărțim la 50 pentru a obține indexul din matrice

    return 0; // Plasare reușită
}