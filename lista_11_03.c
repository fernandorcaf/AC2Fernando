#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[256];
} Aluno;

typedef struct lista_aluno {
    Aluno *aluno;
    struct lista_aluno *proximo;
} ListaAluno;

Aluno *novo_aluno(int matricula, char *nome) {
    Aluno *resultado = malloc(sizeof *resultado);
    resultado->matricula = matricula;
    if (nome)
        snprintf(resultado->nome, 256, nome);
    return resultado;
}

void adiciona(ListaAluno **alunos, Aluno *aluno) {
    if (!aluno)
        return;
    ListaAluno *atual = *alunos;
    ListaAluno *item = malloc(sizeof *item);
    item->aluno = aluno;
    item->proximo = NULL;
    if (!atual) {
        *alunos = item;
        return;
    }
    while (atual->proximo)
        atual = atual->proximo;
    atual->proximo = item;
}

void exclui(ListaAluno **alunos, int matricula) {
    ListaAluno *anterior = NULL;
    ListaAluno *atual = *alunos;
    while (atual) {
        ListaAluno *proximo  = atual->proximo;
        if (atual->aluno->matricula == matricula) {
            if (anterior)
                anterior->proximo = proximo;
            else {
                *alunos = proximo;
            }
            free(atual->aluno);
            free(atual);
        } else {
            anterior = atual;
        }
        atual = proximo;
    }
}

void altera(ListaAluno *alunos, Aluno *aluno) {
    ListaAluno *atual = alunos;
    if (!atual || !aluno)
        return;
    while (atual) {
        if (atual->aluno->matricula == aluno->matricula) {
            free(atual->aluno);
            atual->aluno = aluno;
        }
        atual = atual->proximo;
    }
}

ListaAluno *carrega_alunos(char *caminho) {
    ListaAluno *resultado = NULL;
    FILE *arquivo = fopen(caminho, "r");
    if (!arquivo)
        return NULL;
    Aluno *aluno = novo_aluno(-1, NULL);
    while (fscanf(arquivo, "%d %256[^\n]", &aluno->matricula, aluno->nome) == 2) {
        adiciona(&resultado, aluno);
        aluno = novo_aluno(-1, NULL);
    }
    fclose(arquivo);
    return resultado;
}

void imprime(char *titulo, ListaAluno *alunos) {
    ListaAluno *atual = alunos;
    printf("\n%s\n", titulo);
    if (!atual) {
        printf("(lista vazia)\n");
        return;
    }
    while (atual) {
        if (atual->aluno)
            printf("%s (%03d)\n", atual->aluno->nome, atual->aluno->matricula);
        else
            printf("(item vazio)\n");
        atual = atual->proximo;
    }
}

ListaAluno *lista_teste() {
    ListaAluno *resultado = NULL;
    for (int i = 0; i < 10; i++) {
        Aluno *aluno = novo_aluno(i + 1, NULL);
        snprintf(aluno->nome, 256, "Aluno %c", 'A' + i);
        adiciona(&resultado, aluno);
    }
    return resultado;
}

int main(int argc, char **argv) {

    // Lista inicial
    ListaAluno *alunos = carrega_alunos(argv[1]);
    if (!alunos) {
        printf("Nenhum aluno no arquivo \"%s\"\n", argv[1]);
        printf("Criando lista teste\n");
        alunos = lista_teste();
    }
    imprime("Lista inicial", alunos);

    // Adiciona um aluno
    Aluno *novo = novo_aluno(123, "Aluno Z");
    adiciona(&alunos, novo);
    imprime("Depois de adicionar", alunos);

    // Exclui alunos
    for (int i = 1; i <= 10; i += 2)
        exclui(&alunos, i);
    imprime("Depois de excluir", alunos);

    // Altera um aluno
    Aluno alterado = { .matricula = 10, .nome = "Aluno X" };
    altera(alunos, &alterado);
    imprime("Depois de alterar", alunos);
    return 0;
}
