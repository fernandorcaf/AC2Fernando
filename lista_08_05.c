#include <stdio.h>
#include <stdlib.h>

void imprime(int n, int matriz[n][n]);
void leitura(int n, int matriz[n][n]);
void soma(int n, int matriz1[n][n], int matriz2[n][n]);
void soma_diag(int n, int matriz1[n][n], int matriz2[n][n]);
void mult_matriz(int n, int matriz1[n][n], int matriz2[n][n]);

int main()
{
    int n;
    printf("Quantas linhas e colunas terao as matrizes? ");
    scanf("%d",&n);
    int matriz1[n][n], matriz2[n][n];
    leitura(n, matriz1);
    leitura(n, matriz2);
    soma(n, matriz1, matriz2);
    soma_diag(n, matriz1, matriz2);
    mult_matriz(n, matriz1, matriz2);

    return 0;
}

void leitura(int n,int matriz[n][n])
{
     for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            printf("valor do elemento[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");
}

void imprime(int n, int matriz[n][n]){
    for (int i = 0; i < n;i++){
            printf("\n");
        for (int j = 0; j < n;j++){
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\n");
}
void soma(int n, int matriz1[n][n], int matriz2[n][n])
{
    int matriz3[n][n];
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            matriz3[i][j] = (matriz1[i][j]+matriz2[i][j]);
        }
    }
    printf("SOMA DAS MATRIZES:\n");
    imprime(n, matriz3);
}
void soma_diag(int n, int matriz1[n][n], int matriz2[n][n])
{
    int vet_diag[n];
    int t = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(i==j){
                vet_diag[t] = matriz1[i][j] + matriz2[i][j];
                t++;
            }
        }
    }
    printf("\nELEMENTOS DA DIAGONAL SOMADOS: ");
    for(int i = 0; i < n; i++){
        printf("%d, ", vet_diag[i]);
    }
    printf("\n");
}

void mult_matriz(int n, int matriz1[n][n], int matriz2[n][n])
{
    int matriz3[n][n];
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
                matriz3[i][j] = 0;
            for (int t = 0; t < n; t++){
                matriz3[i][j]+=matriz1[i][t]*matriz2[t][j];
            }
        }
    }
    printf("\nPRODUTO DAS MATRIZES:\n");
    imprime(n, matriz3);
}
