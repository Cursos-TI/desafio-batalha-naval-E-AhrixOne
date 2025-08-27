#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j;

    // Tabuleiro
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Vetores navios
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Posições iniciais - linha e coluna
    
    int linha_h = 2;   
    int coluna_h = 1;  

    int linha_v = 5;   
    int coluna_v = 7; 

    // Navio horizontal
    for (j = 0; j < TAMANHO_NAVIO; j++) {
        tabuleiro[linha_h][coluna_h + j] = navio_horizontal[j];
    }

    // Navio vertical
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // Mostra coordenadas dos navios
    printf("Coordenadas do navio horizontal:\n");
    for (j = 0; j < TAMANHO_NAVIO; j++) {
        printf("  (linha=%d, coluna=%d)\n", linha_h, coluna_h + j);
    }

    printf("Coordenadas do navio vertical:\n");
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        printf("  (linha=%d, coluna=%d)\n", linha_v + i, coluna_v);
    }

    // Mostrar o tabuleiro
    printf("\nTabuleiro:\n");
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
