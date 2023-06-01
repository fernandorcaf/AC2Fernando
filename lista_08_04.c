#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 100
#define C 128

float media(char **matriz, int qtd_nomes);
float variancia(char **matriz,int qtd_nomes);
int tam_nome(char* nome);

int main()
{
    printf("digite nome de usuario ou \"fim\" para encerrar entrada:\n");
    char **matriz;
    int qtd_nomes, i;

    matriz = (char **) malloc(L*sizeof(char *));
    if(matriz == NULL){printf("valor excede limite de memoria"); exit(1);}
    for (i=0;i<L;i++){
        matriz[i] = (char *) malloc(C*sizeof(char));
        if(matriz[i] == NULL){printf("valor excede limite de memoria"); exit(1);}
    }
    i = 0;
    do{
        scanf("%s", matriz[i]);
    } while (strcmp(matriz[i], "fim")!= '\0' && ++i< L);
    qtd_nomes = i;
    for(i = 0; i<qtd_nomes;i++){
        printf("\n%d", tam_nome(matriz[i]));
    }
    printf("\nA media do tamanho dos nomes eh: %.2f", media(matriz,qtd_nomes));
    printf("\nA variancia do tamanho dos nomes eh: %.2f", variancia(matriz,qtd_nomes));
    for (i=0;i<qtd_nomes;i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}

float media(char **matriz, int qtd_nomes)
{
    float med = 0;

    for(int i = 0; i < qtd_nomes; i++){
        med += tam_nome(matriz[i]);
    }
    med = med/qtd_nomes;
    return med;
}
float variancia(char **matriz,int qtd_nomes)
{
    float med = media(matriz, qtd_nomes);
    float var = 0;
    for(int i = 0; i < qtd_nomes; i++){
        var += (tam_nome(matriz[i])-med)*(tam_nome(matriz[i])-med);
    }
    var = var/qtd_nomes;
    return var;
}
int tam_nome(char* nome)
{
    int tam = 0, i = 0;

    while(nome[i] != '\0'){
        tam +=1;
        i++;
    }
    return tam;
}
