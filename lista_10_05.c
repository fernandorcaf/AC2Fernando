#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

int main(){
    float numero, soma, media;
    int contador = 0;
    FILE* file = fopen("lista_10_05.txt", "r");
    while (fscanf(file, "%f", &numero) != EOF){
        soma = soma + numero;
        contador++;
    } media = soma/contador;
    printf("Media eh %.2f", media);
    return 0;
}