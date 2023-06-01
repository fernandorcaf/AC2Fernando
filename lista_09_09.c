#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[81];
    float media;
} ALUNO;

void ordena (ALUNO turma[], int tam);

int main()
{
    int tam, numnotas;
    float notas = 0, sumnotas;
    printf("Digite o numero de alunos na turma: ");
    scanf(" %d", &tam);
    printf("Digite o numero de provas: ");
    scanf(" %d", &numnotas);
    ALUNO turma[tam];
    for (int i = 0; i < tam; i++){
        printf("Nome do aluno[%d]: ", i+1);
        scanf("%s", &turma[i].nome);
        for (int j = 0; j < numnotas; j++){
            printf("nota do aluno na prova[%d]: ", j+1);
            scanf(" %f", &notas);
            while (notas < 0 || notas > 10){
            printf("Valor incorreto, digite novamente");
            scanf(" %f", &notas);
            }
            sumnotas += notas;
        }
        turma[i].media = sumnotas/numnotas;
        sumnotas = 0;
    }

    ordena(turma, tam);

    for (int i = 0; i < tam; i++){
        printf("\nAluno %s:\n", turma[i].nome);
        printf("media: %.2f\n", turma[i].media);
    }
    return 0;
}

void ordena (ALUNO turma[], int tam) {
    int i, foraOrdem , jaOrdenados = 0;
    ALUNO temp;
    do {
        foraOrdem = 0;
        for (i = 0; i < tam - 1 - jaOrdenados ; i++) {
            if (turma[i]. media > turma[i+1]. media) {
                temp = turma[i];
                turma[i] = turma[i+1];
                turma[i+1] = temp;
                foraOrdem = 1;
            }
        }
    jaOrdenados ++;
    } while (foraOrdem);
}
