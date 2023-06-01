
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float Media (char* NomeDoArquivo, char* mat);

int main() {
    char Nome[256], MatriculaDoAluno[10];
    printf("Insira o nome do arquivo: ");
    scanf(" %255[^\n]", Nome);
    printf("Insira a matricula do aluno: ");
    scanf(" %9[^\n]", MatriculaDoAluno);
    float MediaDoAluno = Media(MatriculaDoAluno, Nome);
    if (MediaDoAluno != -1.0) {
        printf("Media do aluno %s: %g\n", MatriculaDoAluno, MediaDoAluno);
    }
    else {
        printf("Matricula nao encontrada.\n");
    }

    return 0;
}

float Media (char* nomeArquivo,char* mat) {
    FILE *fp;
    fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        printf("ERRO");
        exit(1);
    }
    char matriculaBusca[10];
    float p1, p2, p3;
    while (fscanf(fp, " %9[^\n] %f %f %f", &matriculaBusca, &p1, &p2, &p3) == 4)  {
        if (strcmp(matriculaBusca, mat) == 0) {
            fclose(fp);
            float resultadoMedia = (p1 + p2 + p3) / 3;
            return resultadoMedia;
        }
    }
    fclose(fp);
    return -1.0;

}
