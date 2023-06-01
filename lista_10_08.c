#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ALUNO {
    char nome[81];
    float nota1;
    float nota2;
} ALUNO;

typedef struct _LISTA_ALUNO {
    ALUNO *aluno;
    struct _LISTA_ALUNO *proximo;
} LISTA_ALUNO;

ALUNO *novo_aluno(char *nome, float nota1, float nota2) {
    ALUNO *resultado = malloc(sizeof *resultado);
    if (nome)
        snprintf(resultado->nome, 81, nome);
    resultado->nota1 = nota1;
    resultado->nota2 = nota2;
    return resultado;
}

void adiciona(LISTA_ALUNO **alunos, ALUNO *aluno) {
    if (!aluno)
        return;
    LISTA_ALUNO *atual = *alunos;
    LISTA_ALUNO *item = malloc(sizeof *item);
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

void exclui(LISTA_ALUNO **alunos, char *nome) {
    LISTA_ALUNO *anterior = NULL;
    LISTA_ALUNO *atual = *alunos;
    while (atual) {
        LISTA_ALUNO *proximo  = atual->proximo;
        if (strcmp(atual->aluno->nome, nome) == 0) {
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

void altera(LISTA_ALUNO *alunos, ALUNO *aluno) {
    LISTA_ALUNO *atual = alunos;
    if (!atual || !aluno)
        return;
    while (atual) {
        if (strcmp(atual->aluno->nome, aluno->nome) == 0) {
            free(atual->aluno);
            atual->aluno = aluno;
        }
        atual = atual->proximo;
    }
}

ALUNO *consulta(LISTA_ALUNO *alunos, char *nome) {
    LISTA_ALUNO *atual = alunos;
    if (!atual || !nome)
        return NULL;
    while (atual) {
        if (strcmp(atual->aluno->nome, nome) == 0)
            return atual->aluno;
        atual = atual->proximo;
    }
}

void imprime(char *titulo, LISTA_ALUNO *alunos) {
    LISTA_ALUNO *atual = alunos;
    printf("\n%s\n", titulo);
    if (!atual) {
        printf("(lista vazia)\n");
        return;
    }
    while (atual) {
        if (atual->aluno)
            printf("%s (%.2f, %.2f)\n", atual->aluno->nome, atual->aluno->nota1, atual->aluno->nota2);
        else
            printf("(item vazio)\n");
        atual = atual->proximo;
    }
}

void imprime_acima(LISTA_ALUNO *alunos, float filtro) {
    LISTA_ALUNO *atual = alunos;
    printf("\nAlunos com media maior que %.2f\n", filtro);
    if (!atual) {
        printf("(lista vazia)\n");
        return;
    }
    while (atual) {
        if (atual->aluno) {
            float media = (atual->aluno->nota1 + atual->aluno->nota2) / 2;
            if (media > filtro)
                printf("%s (%.2f, %.2f, media %.2f)\n", atual->aluno->nome, atual->aluno->nota1, atual->aluno->nota2, media);
        } else {
            printf("(item vazio)\n");
        }
        atual = atual->proximo;
    }
}

LISTA_ALUNO *lista_teste() {
    LISTA_ALUNO *resultado = NULL;
    for (int i = 0; i < 10; i++) {
        ALUNO *aluno = novo_aluno(NULL, i + 1, i + 1);
        snprintf(aluno->nome, 81, "Aluno %c", 'A' + i);
        adiciona(&resultado, aluno);
    }
    return resultado;
}

LISTA_ALUNO *preenche_lista() {
    LISTA_ALUNO* resultado = NULL;
    char nome[81];
    float nota1;
    float nota2;
    int tamanho;
    printf("Digite a quantidade de alunos na turma: ");
    scanf("%d", &tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("\nDigite o nome do aluno %d: ", i + 1);
        fflush(stdin);
        gets(nome);
        printf("\nDigite as duas notas do aluno %d separadas por um espaco: ", i + 1);
        scanf("%f %f", &nota1, &nota2);
        ALUNO *aluno = novo_aluno(nome, nota1, nota2);
        adiciona(&resultado, aluno);
    }
    return resultado;
}

void grava_alunos(LISTA_ALUNO *alunos, char *caminho) {
    LISTA_ALUNO *atual = alunos;
    FILE *arquivo = fopen(caminho, "wb+");
    if (!arquivo)
        return;
    while (atual) {
        if (atual->aluno)
            fwrite(atual->aluno, sizeof(ALUNO), 1, arquivo);
        atual = atual->proximo;
    }
    fclose(arquivo);
}

int menu() {
    int resultado;
    printf("\nDigite (1) para incluir um aluno\n");
    printf(".......(2) para alterar um aluno\n");
    printf(".......(3) para excluir um aluno\n");
    printf(".......(4) para consultar um aluno\n");
    printf(".......(5) para consultar todos\n");
    printf(".......(6) para consultar media acima de 6\n");
    printf(".......(7) para gravar e terminar o programa\n");
    scanf("%d", &resultado);
    return resultado;
}

int main() {
    LISTA_ALUNO* turma = NULL;
    char nome[81];
    float nota1;
    float nota2;
    int selecao;

    //turma = lista_teste();
    turma = preenche_lista();
    imprime("Lista inicial", turma);
    selecao = menu();

    while (selecao != 7) {
        switch (selecao) {
            case 1:
            printf("\nDigite o nome do aluno que deseja incluir: ");
            fflush(stdin);
            gets(nome);
            printf("\nDigite as duas notas do novo aluno: ");
            scanf("%f %f", &nota1, &nota2);
            ALUNO *novoAluno = novo_aluno(nome, nota1, nota2);
            adiciona(&turma, novoAluno);
            break;

            case 2:
            ALUNO alunoAlterado;
            printf("\nDigite o nome do aluno que deseja alterar: ");
            fflush(stdin);
            gets(alunoAlterado.nome);
            printf("\nDigite as novas notas do aluno: ");
            scanf("%f %f", &alunoAlterado.nota1, &alunoAlterado.nota2);
            altera(turma, &alunoAlterado);
            break;

            case 3:
            printf("\nDigite o nome do aluno que deseja excluir: ");
            fflush(stdin);
            gets(nome);
            exclui(&turma, nome);
            break;

            case 4:
            printf("\nDigite o nome do aluno que deseja consultar: ");
            fflush(stdin);
            gets(nome);
            ALUNO *infoAluno = consulta(turma, nome);
            if (infoAluno)
                printf("%s tem notas %.2f e %.2f\n", infoAluno->nome, infoAluno->nota1, infoAluno->nota2);
            else
                printf("Nome nao encontrado\n");
            break;

            case 5:
            imprime("Todos os alunos", turma);
            break;

            case 6:
            imprime_acima(turma, 6);
            break;
        }
        selecao = menu();
    }
    grava_alunos(turma, "lista_10_08.bin");
    free(turma);
    return 0;
}
