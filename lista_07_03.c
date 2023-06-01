#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *criacao_lista(int n);
void impressao(int n, int *vetor);

int main (void) {

    int n;
    int *vet;
    do {
        printf("n: ");
        scanf("%d", &n);
    } while (n < 0);

    vet = criacao_lista(n);
    impressao(n, vet);

    return 0;
}

int *criacao_lista(int n) {

    int *vetor;
    int i = 1, j = 0;
    vetor = (int *) malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Falta de memoria");
        exit(1);
    }

    for (int j = 0; j < n; j++) {
        vetor[j] =  (i * 5);
        i++;
    }

    return vetor;

    free(vetor);
}

void impressao(int n, int *vetor) {

    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

}
