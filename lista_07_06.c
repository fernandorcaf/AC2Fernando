#include <stdio.h>
#include <string.h>

#define MAX 50

int main (void) {
    char texto[MAX +2], temp;
    int tam, i;

    printf("Digite um texto: ");
    gets(texto);
    tam = strlen(texto);

    for (i = 0; i < tam ; i++) {
        temp = texto[i];
        texto[i] = texto[tam - 1 - i];
        texto[strlen(texto) - 1 - i] = temp;
    }

    puts(texto);
    printf("O algoritmo inverte o primeiro caracter com o último, o segundo com o penúltimo,\n");
    printf("e assim por diante, de modo que ao passar pelo meio da string os caracteres são\n");
    printf("invertidos novamente em suas posições iniciais, resultando na string original.\n");
    return 0;
}
