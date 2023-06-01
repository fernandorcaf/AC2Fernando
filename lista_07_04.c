#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *criacao_vetor(char *vetor);
void impressao(char *vetor);

int main (void) {

    char vetor[26];
    char *vet = vetor;
    vet = criacao_vetor(vetor);
    impressao(vet);

    return 0;
}

char *criacao_vetor(char *vetor) {

    int j = 0, i = 97;
    while (i < 123) {
        vetor[j] = i;
        i++;
        j++;
    }

    return vetor;
}

void impressao(char *vetor) {

    for(int i = 0; i < 26; i++) {
        printf("%c ", vetor[i]);
    }

}