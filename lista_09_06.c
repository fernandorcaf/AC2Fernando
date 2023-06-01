#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct pessoa {
 int codigo;
 char nome[81];
 };
 typedef struct pessoa Pessoa;


 Pessoa *busca(int n, Pessoa** vet, int codigo){
    int ini = 0;
    int fim = n-1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (codigo < vet[meio]->codigo){
            fim = meio - 1;
        }
        else if (codigo > vet[meio]->codigo){
            ini = meio + 1;
        }
        else{
        return vet[meio];
        }
    }
    return NULL;
    }

int main(){
    int i, tamanho, codigoBuscado;
    Pessoa *pessoa;
    printf("Digite a quantidade de pessoas a cadastrar: \n");
    scanf("%d", &tamanho);
    Pessoa **cadastro;
    cadastro = (Pessoa**) malloc (tamanho * (sizeof(Pessoa*)));
    for (i = 0; i < tamanho; i ++){
        cadastro[i] = (Pessoa*) malloc (sizeof(Pessoa));
    }
    for (i = 0; i < tamanho; i++){
        printf("\nDigite o codigo do cadastrado %d:\n", i + 1);
        scanf("%d", &cadastro[i]->codigo);
        printf("\nDigite o nome do cadastrado %d:\n", i + 1);
        fflush(stdin);
        gets(cadastro[i]->nome);
    }
    printf("\nDigite o codigo que deseja buscar: \n");
    scanf("%d", &codigoBuscado);
    if (pessoa = busca(tamanho, cadastro, codigoBuscado))
        printf("Localizada pessoa de codigo %d e nome %s\n", pessoa->codigo, pessoa->nome);
    else
        printf("Nenhuma pessoa localizada\n");
    return 0;
}