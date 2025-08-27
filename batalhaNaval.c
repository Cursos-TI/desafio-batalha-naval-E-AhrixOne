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
    int navio_h[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_v[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_d1[TAMANHO_NAVIO] = {3, 3, 3}; // diagonal ↘
    int navio_d2[TAMANHO_NAVIO] = {3, 3, 3}; // diagonal ↗

    // Posições iniciais - linha e coluna
    int linha_h = 2;   
    int coluna_h = 1;  

    int linha_v = 5;   
    int coluna_v = 7;  

    int linha_d1 = 0;  
    int coluna_d1 = 0; 

    int linha_d2 = 9;  
    int coluna_d2 = 0; 

    // Coloca navio horizontal
    for (j = 0; j < TAMANHO_NAVIO; j++) {
        tabuleiro[linha_h][coluna_h + j] = navio_h[j];
    }

    // Coloca navio vertical
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_v[i];
    }

    // Coloca navio diagonal 
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_d1 + i][coluna_d1 + i] = navio_d1[i];
    }

    // Coloca navio diagonal 
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_d2 - i][coluna_d2 + i] = navio_d2[i];
    }

    // Coordenadas dos navios
    printf("Coordenadas do navio horizontal:\n");
    for (j = 0; j < TAMANHO_NAVIO; j++) {
        printf("  (linha=%d, coluna=%d)\n", linha_h, coluna_h + j);
    }

    printf("Coordenadas do navio vertical:\n");
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        printf("  (linha=%d, coluna=%d)\n", linha_v + i, coluna_v);
    }

    printf("Coordenadas do navio diagonal ↘:\n");
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        printf("  (linha=%d, coluna=%d)\n", linha_d1 + i, coluna_d1 + i);
    }

    printf("Coordenadas do navio diagonal ↗:\n");
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        printf("  (linha=%d, coluna=%d)\n", linha_d2 - i, coluna_d2 + i);
    }

    // Mostrar tabuleiro
    printf("\nTabuleiro (0=agua, 3=navio):\n");
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
