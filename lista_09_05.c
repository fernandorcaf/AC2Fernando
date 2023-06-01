#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct endereco {
    char rua[100]; /* Nome da rua */
    int numero; /* Numero do imovel */
} Endereco;

typedef struct notas {
    float p1, p2, p3; /* Notas nas provas */
} Notas;

typedef struct aluno {
    int mat; /* Matricula do aluno */
    char nome[81]; /* Nome do aluno */
    Notas nota; /* Notas nas provas */
    Endereco *end; /* Endereco do aluno */
} Aluno;

Aluno ** alocaAlunos(int n){
    Aluno **alunos = malloc(n * sizeof (Aluno*));
    for (int i = 0; i < n; i++) {
        alunos[i] = malloc(sizeof (Aluno));
        alunos[i]->end = malloc(sizeof (Endereco));
    }
    return alunos;
}

void atribui(Aluno ** a, int indice, int matricula, char *nome, float
    nota1, float nota2, float nota3, char *nomeRua, int numero){
        a[indice]->mat = matricula;
        strcpy(a[indice]->nome, nome);
        a[indice]->nota.p1 = nota1;
        a[indice]->nota.p2 = nota2;
        a[indice]->nota.p3 = nota3;
        strcpy(a[indice]->end->rua, nomeRua);
        a[indice]->end->numero = numero;
}

void imprimeAlunos(Aluno **alunos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d %s %s %.2f %.2f %.2f\n",
            alunos[i]->mat,
            alunos[i]->nome,
            alunos[i]->end->rua,
            alunos[i]->nota.p1,
            alunos[i]->nota.p2,
            alunos[i]->nota.p3);
    }
}

int main(){
    Aluno **alunos;
    alunos = alocaAlunos(3);
    atribui(alunos, 0, 10, "Um", 1.1, 1.2, 1.3, "Getulio Vargas", 100);
    atribui(alunos, 1, 20, "Dois", 8.1, 8.2, 8.3, "Amaral Peixoto", 200);
    atribui(alunos, 2 ,30, "Tres", 9.1, 9.2, 9.3, "Ouro Verde", 300);
    imprimeAlunos(alunos, 3);
    free(alunos);
    return 0;
}
