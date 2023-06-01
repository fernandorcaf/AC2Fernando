#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_espacos(char frase[80]);
void criptografia(char frase[80], int tam);

int main()
{
   char frase[80];
   int tam;

   printf("Digite a frase: ");
   scanf(" %[a-z A-Z]", frase);
   remove_espacos(frase);
   tam = strlen(frase);
   criptografia(frase, tam);
    return 0;
}

void remove_espacos(char frase[80]) {
    int count = 0;
    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] != ' '){
            frase[count] = frase[i];
            count++;
        }
    }
    for (count; count < strlen(frase); count++){
        frase[count] = '\0';
    }
}

void criptografia(char frase[80], int tam){
    int i, troca = 1;
    char caractere;
    for (i = 0; i < tam; i++) {
        if (troca > 5) {
            troca = 1;
        }
        caractere = frase[i];
        frase[i] = caractere + troca;
        troca++;
    }
    printf("%s\n", frase);
}
