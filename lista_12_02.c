#include <stdio.h>

int soma_impares(int numeros[], int tamanho) {
    if (tamanho < 1)
        return 0;
    int ultimo = numeros[tamanho - 1];
    int termo = ultimo % 2? ultimo : 0;
    if (tamanho == 1)
        return termo;
    return termo + soma_impares(numeros, tamanho - 1);
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof numeros / sizeof numeros[0];
    printf("Soma = %d\n", soma_impares(numeros, tamanho));
}
