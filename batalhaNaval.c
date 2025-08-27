#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j;

    // Tabuleiro
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Vetores de navios
    int navio_h[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_v[TAMANHO_NAVIO] = {3, 3, 3};

    // Colocando navio horizontal
    int linha_h = 2, coluna_h = 1;
    for (j = 0; j < TAMANHO_NAVIO; j++) {
        tabuleiro[linha_h][coluna_h + j] = navio_h[j];
    }

    // Colocando navio vertical
    int linha_v = 5, coluna_v = 7;
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_v[i];
    }

    // Habilidade
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Preenche cone
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= (TAMANHO_HABILIDADE / 2 - i) && j <= (TAMANHO_HABILIDADE / 2 + i) && i <= TAMANHO_HABILIDADE/2) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Preenche cruz
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Preenche octaedro
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE/2) + abs(j - TAMANHO_HABILIDADE/2) <= TAMANHO_HABILIDADE/2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Coordenadas das habilidades 
    int origem_cone_l = 1, origem_cone_c = 5;
    int origem_cruz_l = 7, origem_cruz_c = 2;
    int origem_octa_l = 4, origem_octa_c = 4;

    // Aaplicar habilidade
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha = origem_cone_l + i - TAMANHO_HABILIDADE/2;
            int coluna = origem_cone_c + j - TAMANHO_HABILIDADE/2;
            if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                if (cone[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha = origem_cruz_l + i - TAMANHO_HABILIDADE/2;
            int coluna = origem_cruz_c + j - TAMANHO_HABILIDADE/2;
            if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                if (cruz[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha = origem_octa_l + i - TAMANHO_HABILIDADE/2;
            int coluna = origem_octa_c + j - TAMANHO_HABILIDADE/2;
            if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                if (octaedro[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Mostra Tabuleiro
    printf("\nTabuleiro final:\n");
    printf("0 = agua, 3 = navio, 5 = habilidade\n\n");

    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
