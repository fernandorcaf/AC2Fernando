#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

float busca (char* arquivo, char* matricula){
    char matric[10];
    float cr;
    int retorno;
    FILE* file = fopen(arquivo, "r");
    if (file == NULL){
        printf("ERRO");
        exit(0);
    }
    while (fscanf(file, "%s %f", matric, &cr) != EOF){
        retorno = strcmp(matric, matricula);
        if (retorno == 0){
            break;
        }
        else{ cr = -1.0;};
    }
    fclose(file);
    return cr;
}

int main(){
    float cr;
    char* mat;
    mat = (char*) malloc (10 * sizeof(char));
    char nomeArquivo[15];
    printf("Digite a matricula do aluno que deseja consultar: ");
    scanf("%s", mat);
    printf("\nDigite o nome do arquivo onde estao as informacoes: ");
    scanf("%s", nomeArquivo);
    cr = busca(nomeArquivo, mat);
    printf("%.1f", cr);
    return 0;
}