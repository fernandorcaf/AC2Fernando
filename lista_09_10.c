#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 4

struct aluno {
 int mat;
 float media;
 };

void le (struct aluno * v){
    int i;
    for (i = 0; i < MAX; i++){

        printf("\nInsira a matricula do aluno %d: ", i + 1);
        scanf("%d", &v[i].mat);

        printf("\nInsira a media do aluno %d: ", i + 1);
        scanf("%f", &v[i].media);

    }
}

void imprime (struct aluno * v){
    int i;
    for (i = 0; i < MAX; i++){
        printf("\nMatricula do aluno %d: %d", i + 1, v[i].mat);
        printf("\nMedia do aluno %d: %.2f", i + 1, v[i].media);
    }
}

void ordena_medias (struct aluno * v){
    int fim, i;
    for (fim = MAX - 1; fim > 0; fim--)
        for (i = 0; i < fim; i++)
            if (v[i].media > v[i + 1].media) {
                int temp = v[i].media; /* troca */
                int temp2 = v[i].mat;
                v[i].media = v[i + 1].media;
                v[i].mat = v[i + 1].mat;
                v[i+1].media = temp;
                v[i+1].mat = temp2;
            }
}



int main (void) {
    struct aluno turma[MAX];
    le( turma );
    puts (" Imprimindo dados lidos da turma.");
    puts (" Digite qualquer coisa para continuar .");
    getchar ();
    imprime ( turma );
    ordena_medias ( turma );
    puts (" Imprimindo dados ordenados da turma.");
    puts (" Digite qualquer coisa para continuar .");
    getchar ();
    imprime ( turma );
    getchar ();
}