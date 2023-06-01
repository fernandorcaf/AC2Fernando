#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *ArquivoOrigem, *ArquivoDestino;

    ArquivoDestino = fopen("arquivo_sem_comentario.c", "w");
    if (ArquivoDestino == NULL) {
        printf("ERRO!");
        exit(1);
    }

    char NomeDoArquivo[256];
    printf("Insira o nome do arquivo de origem: ");
    scanf(" %255[^\n]", NomeDoArquivo);

    ArquivoOrigem = fopen(NomeDoArquivo, "r");
    if (ArquivoOrigem == NULL) {
        printf("ERRO!");
        exit(1);
    }

    char linha[512];
    while (fgets(linha, 511, ArquivoOrigem) != NULL) {
        if (strstr(linha, "//") == NULL) {
            fprintf(ArquivoDestino, "%s", linha);
        }
    }
    // Fecha os arquivos
    fclose(ArquivoOrigem);
    fclose(ArquivoDestino);
    return 0;
}
