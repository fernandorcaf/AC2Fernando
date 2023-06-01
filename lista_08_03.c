#include <stdio.h>
#include <stdlib.h>
#define M 4

void transpor(float matriz[M][M]);
int simetrica(float matriz1[M][M], float matriz2[M][M]);
int imprime(float matriz[M][M]);

int main()
{
    float matriz1[M][M], matriz2[M][M];
    printf("Insira os elementos da matriz\n");
    for (int i = 0; i<M; i++){
        for(int j = 0;j<M;j++){
            printf("Elemento[%d][%d]: ", i, j);
            scanf("%f", &matriz1[i][j]);
            matriz2[i][j] = matriz1[i][j];
        }
    }
    transpor(matriz1);
    printf("\nMatriz original:\n");
    imprime(matriz1);
    printf("Matriz Transposta:\n");
    imprime(matriz2);
    if (simetrica(matriz1, matriz2) == 0){
        printf("Essa matriz eh simetrica");
    }
    else{
        printf("Essa matriz nao eh simetrica");
    }
    return 0;
}

int simetrica(float matriz1[M][M], float matriz2[M][M])
{
    for (int i = 0; i<M; i++){
        for(int j = 0;j<M;j++){
            if(matriz1[i][j] != matriz2[j][i]){
                return 1;
            }
        }
    }
    return 0;
}

void transpor(float matriz[M][M])
{
    float temp;
    for (int i = 0; i<M; i++){
        for(int j = i;j<M;j++){
            temp = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temp;

        }
    }
}
int imprime(float matriz[M][M]){
    for (int i = 0; i < M;i++){
            printf("\n");
        for (int j = 0; j < M;j++){
            printf("%.2f ", matriz[i][j]);
        }
    }
    printf("\n\n");
    return 0;
}

