#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

typedef struct Aluno {
 int matricula;
 float *vNotas; // Armazena as 5 notas de um aluno ao longo de um ano.
 char nome[100];
}Aluno;

typedef struct Matéria {
 Aluno *V; // Armazena a informação de n alunos !!
 float media[5]; // Armazena as 5 médias do ano.
 int nAlunos; // Número de alunos matriculados no curso.
}Materia;

Aluno fillAluno(){
    Aluno fichaAluno;
    fichaAluno.vNotas = malloc (5 * sizeof(float));

    printf("\nDigite a matricula do aluno a armazenar: \n");
    scanf("%d", &fichaAluno.matricula);

    printf("\nDigite as 5 notas do aluno a armazenar: \n");
    scanf("\n%f", &fichaAluno.vNotas[0]);
    scanf("\n%f", &fichaAluno.vNotas[1]);
    scanf("\n%f", &fichaAluno.vNotas[2]);
    scanf("\n%f", &fichaAluno.vNotas[3]);
    scanf("\n%f", &fichaAluno.vNotas[4]);


    printf("\nDigite o nome do aluno a armazenar: \n");
    fflush(stdin);
    gets(fichaAluno.nome);

    return fichaAluno;
}

void mediaMateria(Materia *m1){
    int i;
    int tamanho = m1->nAlunos;
    printf("%d", tamanho);
    float soma1 = 0, soma2 = 0, soma3 = 0, soma4 = 0, soma5 = 0;
    for (i = 0; i < tamanho; i++){
        soma1 = soma1 + (m1->V[i].vNotas[0]);
        soma2 = soma2 + (m1->V[i].vNotas[1]);
        soma3 = soma3 + (m1->V[i].vNotas[2]);
        soma4 = soma4 + (m1->V[i].vNotas[3]);
        soma5 = soma5 + (m1->V[i].vNotas[4]);
    }
    m1->media[0] = soma1/tamanho;
    m1->media[1] = soma2/tamanho;
    m1->media[2] = soma3/tamanho;
    m1->media[3] = soma4/tamanho;
    m1->media[4] = soma5/tamanho;
    printf("\n Media prova 1: %.2f\n", m1->media[0]);
    printf("\n Media prova 2: %.2f\n", m1->media[1]);
    printf("\n Media prova 3: %.2f\n", m1->media[2]);
    printf("\n Media prova 4: %.2f\n", m1->media[3]);
    printf("\n Media prova 5: %.2f\n", m1->media[4]);
}

void mostraMateria(Materia *m1){   
    int i;
    for(i = 0; i < m1->nAlunos; i++){
        printf("\nMatricula do aluno %s: %d\n", m1->V[i].nome, m1->V[i].matricula);
        printf("\nTodas as notas do aluno ao longo do ano: %.2f %.2f %.2f %.2f %.2f \n", m1->V[i].vNotas[0], m1->V[i].vNotas[1], m1->V[i].vNotas[2], m1->V[i].vNotas[3], m1->V[i].vNotas[4]);
    }
}

Materia * fillMateria(int numAlunos){
    int i;
    Materia * dados;
    dados = (Materia*) malloc (sizeof(Materia));
    dados->V = (Aluno*) malloc (numAlunos * sizeof(Aluno));
    dados->nAlunos = numAlunos;
    for (i = 0; i < numAlunos; i++){
        dados->V[i] = fillAluno();
    }
    mediaMateria(dados);
    mostraMateria(dados);
}

int main(){
    int n;
    printf("Digite a quantidade de alunos que deseja armazenar os dados: ");
    scanf("%d", &n);
    fillMateria(n);
    return 0;
}