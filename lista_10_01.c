#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    char nome[81];
    float valor_hora;
    int horas_mes;
} Funcionario;

void carrega(int n, Funcionario **vet, char *arquivo);

int main (void) {

    char arquivo[20];
    printf("Informe o nome do arquivo: ");
    scanf(" %19s", arquivo);

    int n = 3;
    Funcionario **vet;
    vet = (Funcionario**) malloc (n * sizeof(Funcionario));
    if (vet == NULL) { printf("Falta de memoria"); exit(1); }

    for(int i = 0; i < n; i++) {
        vet[i] = NULL;
    }

    carrega(n, vet, arquivo);

    free(vet);

    return 0;
}

void carrega(int n, Funcionario **vet, char *arquivo) {

    FILE *arquivo_dados;
    arquivo_dados = fopen(arquivo, "r");
    if (arquivo_dados == NULL) { printf("ERRO"); exit(1); }

    for(int i = 0; i < n; i++) {

        vet[i] = (Funcionario*) malloc(sizeof(Funcionario));
        fscanf(arquivo_dados, " %80[^\n]\n %f %d", vet[i]->nome, &vet[i]->valor_hora, &vet[i]->horas_mes);

        printf("\nFUNCIONARIO %d\nNOME: %s\nVALOR DA HORA: R$ %.2f\nHORAS NO MES: %d\n", i+1, vet[i]->nome, vet[i]->valor_hora, vet[i]->horas_mes);
    }

    fclose(arquivo_dados);
}
