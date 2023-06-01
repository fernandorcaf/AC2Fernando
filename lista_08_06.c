#include <stdio.h>
#include <stdlib.h>
#define N 8
int qtd_peca(int matriz[N][N], int peca);
int qtd_total(int matriz[N][N]);

int main() {
    int tabuleiro[8][8] = {{1, 3, 0, 5, 4, 0, 2, 1}, {1, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 6, 0}, {1, 0, 0, 1, 1, 0, 0, 1}, {0, 1, 0, 4, 0, 0, 1, 0}, {0, 0, 3, 1, 0, 0, 1, 1}, {1, 0, 6, 6, 0, 0, 1, 0}, {1, 0, 5, 0, 1, 1, 0, 6}};
    int qtd_peoes = qtd_peca(tabuleiro, 1);
    int qtd_bispos = qtd_peca(tabuleiro, 4);
    int qtd_vazios = qtd_peca(tabuleiro, 0);
    int total = qtd_total(tabuleiro);
    printf("Total de pecas: %d\n", total);
    printf("Soma total de peoes e bispos: %d\n", qtd_peoes + qtd_bispos);
    printf("Posicoes vazias: %d\n", qtd_vazios);
    return 0;
}

int qtd_peca(int matriz[N][N], int peca) {
    int i, j, somatorio = 0;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (matriz[i][j] == peca) {
                somatorio++;
            }
        }
    }
    return somatorio;
}

int qtd_total(int matriz[N][N]) {
    int i, j, somatorio = 0;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (matriz[i][j] != 0) {
                somatorio++;
            }
        }
    }
    return somatorio;
}
