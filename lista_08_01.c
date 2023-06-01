#include <stdio.h>
#include <stdlib.h>
#define M 3

float somatorio(float matriz[M][M]);

int main(){
    float matriz[M][M];
    for (int i = 0; i < M;i++){
        for (int j = 0; j < M;j++){
            printf("valor do elemento[%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
    if (somatorio(matriz) == 0){
        printf("o soma dos elementos das linhas sao todos iguais");
    }
    else{
        printf("a soma dos elementos das linha sao diferentes");
    }
    return 0;
}

float somatorio(float matriz[M][M]){
    float soma, temp;
    for (int i=0;i<M;i++){
        soma += matriz[0][i];
        }
    temp = soma;
    for (int i=0; i<M;i++){
        if(temp != soma){
            return 1;
        }
        temp = 0;
        for(int j=0;j<M;j++){
            temp += matriz[i][j];
        }
    }
    return 0;
}
