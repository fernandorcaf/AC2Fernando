#include <stdio.h>
#include <stdlib.h>
#define L 3
#define C 4

int leitura(float matriz[L][C]);
int imprime(float matriz[L][C]);

int main(){
    float matriz1[L][C], matriz2[L][C], matriz3[L][C];

    printf("Matriz 1\n");
    leitura(matriz1);
    imprime(matriz1);
    printf("\nMatriz 2\n");
    leitura(matriz2);
    imprime(matriz2);
    printf("A soma dessas duas matrizes é:\n");
    for (int i = 0; i < L;i++){
        for (int j = 0; j < C;j++){
            matriz3[i][j] = (matriz1[i][j]+matriz2[i][j]);
        }
    }
    imprime(matriz3);
    return 0;
}

int leitura(float matriz[L][C]){
     for (int i = 0; i < L;i++){
        for (int j = 0; j < C;j++){
            printf("valor do elemento[%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
    printf("\n");
    return 0;
}

int imprime(float matriz[L][C]){
    for (int i = 0; i < L;i++){
            printf("\n");
        for (int j = 0; j < C;j++){
            printf("%.2f ", matriz[i][j]);
        }
    }
    printf("\n");
    return 0;
}



