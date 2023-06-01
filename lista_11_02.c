#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    struct elemento *proximo;
} Elemento;

Elemento* copia(Elemento *lista) {
    Elemento *atual = lista;
    Elemento *resultado = malloc(sizeof *lista);
    Elemento *copia_atual = resultado;
    while (atual && copia_atual) {
        copia_atual->valor = atual->valor;
        copia_atual->proximo = atual->proximo? malloc(sizeof *lista) : NULL;
        copia_atual = copia_atual->proximo;
        atual = atual->proximo;
    }
    return resultado;
}

void imprime(char *titulo, Elemento *lista) {
    Elemento *atual = lista;
    printf("%s\n", titulo);
    while (atual) {
        printf("%p = %d\n", atual, atual->valor);
        atual = atual->proximo;
    }
}

int main(void) {
    Elemento *lista = malloc(sizeof *lista);
    Elemento *atual = lista;
    Elemento *anterior = NULL;

    // Cria uma lista teste
    for (int i = 0; i < 10 && atual; i++) {
        atual->valor = i + 1;
        atual->proximo = NULL;
        if (anterior)
            anterior->proximo = atual;
        anterior = atual;
        atual = malloc(sizeof *lista);
    }

    imprime("Antes de copiar", lista);
    Elemento *copia_lista = copia(lista);
    imprime("Depois de copiar", copia_lista);
    return 0;
}
