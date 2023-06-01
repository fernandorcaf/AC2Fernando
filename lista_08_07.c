#include <stdio.h>
#include <stdlib.h>
#define N 5

int tab_s_rep (int tabela[N][N]);
int dist_per(int tabela[N][N], int tam_per, int per[tam_per]);
int distancia(int city1, int city2, int tabela[N][N]);

int main()
{
    int tabela[N][N] = {{0, 15, 30, 5, 12}, {15, 0, 10, 17, 28}, {30, 10, 0, 3, 11}, {5, 17, 3, 0, 80}, {12, 28, 11, 80, 0}};
    int city1, city2, dist, tam_per, i;
    do{
        printf("Insira duas cidades(1 a 5):\n");
        scanf(" %d", &city1);
        scanf(" %d", &city2);
        if(city1 == 0 && city2 == 0){
            break;
        }
        dist = distancia(city1, city2, tabela);
        printf("A distancia entre a cidade %d e %d eh de %dkm\n", city1, city2, dist);
    } while(city1 != 0 && city2 != 0);

    printf("\nDISTANCIA ENTRE AS CIDADES (1 a 5)\n\n");
    tab_s_rep(tabela);
    printf("\nQuantas cidades serao percorridas? ");
    scanf(" %d", &tam_per);
    int per[tam_per];
    printf("Digite um por um os locais do percurso\n");
    for (i = 0; i < tam_per; i++){
        scanf(" %d", &per[i]);
    }
    dist = dist_per(tabela, tam_per, per);
    printf("a distancia percorrida por esse percurso eh de %d", dist);
    return 0;
}

int tab_s_rep (int tabela[N][N]){
    int i, j, n =0;
    for (i = 0; i < N; i++){
        n = i;
        for (j = n;j < N; j++){
            printf("%d ", tabela[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int distancia(int city1, int city2, int tabela[N][N]){
    int dist = 0, i, j;
    int l = city1 - 1;
    int c = city2 - 1;
    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            if(l == i && c == j){
                dist = tabela[i][j];
            }
        }
    }
    return dist;
}

int dist_per(int tabela[N][N], int tam_per, int per[tam_per]){
    int dist, i;
    for (i = 1; i < tam_per; i++){
        dist += distancia(per[i-1],per[i], tabela);
    }
    return dist;
}
