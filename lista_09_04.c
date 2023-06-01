#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void atribui(char **nomes, int indice, char *nome){
    nomes[indice] = nome;
}

char * get_sobrenome(char *nome){
    char *sobreNome;
    int tamanho = strlen(nome);
    int tamanhoSobreNome = 0;
    int indiceNome = tamanho;
    while (nome[indiceNome - 1] != ' '){
        tamanhoSobreNome++;
        indiceNome--;
    }
    int n = 0;
    sobreNome = (char*) malloc ((tamanhoSobreNome+1) * sizeof(char));
    for ( ; indiceNome < tamanho; indiceNome++){
        sobreNome[n] = nome[indiceNome];
        n++;
    } sobreNome[n] = '\0';
    return sobreNome;
}

int main() {
 int i;
 char **nomes; 
 char *sobrenome;
 nomes = (char **) malloc(MAX*sizeof(char *));
 for ( i=0 ; i<MAX ; i++) {
 nomes[i] = (char *) malloc(sizeof(char)*MAXNOME); 
 } 
 atribui(nomes,0,"Fulano Silva"); atribui(nomes,1,"Maria do Carmo"); 
 atribui(nomes,2,"Beltrano Belmonte"); atribui(nomes,3,"Pedro dos Santos");
 for (i=0 ; i<MAX ; i++) {
 sobrenome = get_sobrenome(nomes[i]);
 printf("\n%s ", sobrenome); 
 printf(" %d",strlen(sobrenome)>5?i:0); // 2º printf
 }
 printf("\n%c", nomes[0][3]); // 3º printf 
 return 0;
}

/*

   c. será impresso o indice em que se encontra o nome na string caso o valor seja do tamanho da string seja maior que 5, caso contrário imprime 0.

   d. será impresso 'a'.

*/