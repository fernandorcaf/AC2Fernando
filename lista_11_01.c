#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    float valor;
    struct elemento *proximo;
} Elemento;

Elemento* filtra(Elemento *lista, float minimo, float maximo) {
    Elemento *anterior = NULL;
    Elemento *atual = lista;
    Elemento *resultado = lista;
    while (atual) {
        Elemento *proximo = atual->proximo;
        if (atual->valor < minimo || atual->valor > maximo) {
            if (anterior)
                anterior->proximo = proximo;
            else
                resultado = proximo;
            free(atual);
        } else {
            anterior = atual;
        }
        atual = proximo;
    }
    return resultado;
}

void imprime(char *titulo, Elemento *lista) {
    Elemento *atual = lista;
    printf("%s\n", titulo);
    while (atual) {
        printf("%.2f\n", atual->valor);
        atual = atual->proximo;
    }
}

int main(void) {
    Elemento *lista = malloc(sizeof *lista);
    Elemento *atual = lista;
    Elemento *anterior = NULL;

    // Cria uma lista teste
    for (int i = 0; i < 10 && atual; i++) {
        atual->valor = (float) (i + 1);
        atual->proximo = NULL;
        if (anterior)
            anterior->proximo = atual;
        anterior = atual;
        atual = malloc(sizeof *lista);
    }

    imprime("Antes de filtrar", lista);
    lista = filtra(lista, 3.0, 7.0);
    imprime("Depois de filtrar", lista);
    return 0;
}
