#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    int dd, mm, aa; /* Dia, mes e ano */
 };
 typedef struct data Data;

 struct compromisso {
    char descricao[81]; /* Descricao do compromisso */
    Data dta; /* Data do compromisso */
 };
 typedef struct compromisso Compromisso;

Compromisso* busca(int n, Compromisso** vet, int d, int m, int a){
        int ini = 0;
        int fim = n-1;
        while (ini <= fim) {
            int meio = (ini + fim) / 2;
            if (a < vet[meio]->dta.aa){
                fim = meio - 1;
            }
            else if ((a == vet[meio]->dta.aa) && (m < vet[meio]->dta.mm)){
                fim = meio - 1;
            }
            else if ((a == vet[meio]->dta.aa) && (m == vet[meio]->dta.mm) && (d < vet[meio]->dta.dd)){
                fim = meio - 1;
            }
            else if (a > vet[meio]->dta.aa){
                ini = meio + 1; 
            }
            else if ((a == vet[meio]->dta.aa) && (m > vet[meio]->dta.mm)){
                ini = meio + 1;
            }
            else if ((a == vet[meio]->dta.aa) && (m == vet[meio]->dta.mm) && (d > vet[meio]->dta.dd)){
                ini = meio + 1;
            }
            else if ((a == vet[meio]->dta.aa) && (m == vet[meio]->dta.mm) && (d == vet[meio]->dta.dd)){
                return vet[meio];
            }
        }
    return NULL;
}

int main(){
    int tamanho, i, dia, mes, ano;
    Compromisso* buscado;
    buscado = (Compromisso*) malloc (sizeof(Compromisso));
    Compromisso** agenda;
    printf("Quantos compromissos tem na agenda? ");
    scanf("%d", &tamanho);
    agenda = (Compromisso**) malloc (tamanho * sizeof(Compromisso*));
    if (agenda == NULL){
        printf("Falta de memoria");
        exit(1);
    }
    for (i = 0; i < tamanho; i++){
        agenda[i] = (Compromisso*) malloc (sizeof(Compromisso));
        if (agenda[i] == NULL){
            printf("Falta de memoria");
            exit(1);
        }
    }
    for (i = 0; i < tamanho; i++){
        printf("\nDigite a descricao do compromisso %d: ", i + 1);
        fflush(stdin);
        gets(agenda[i]->descricao);
        printf("\nDigite a data do compromisso no formato dd/mm/aa: ");
        scanf("%d/%d/%d", &agenda[i]->dta.dd, &agenda[i]->dta.mm, &agenda[i]->dta.aa);
    }
    printf("\nDigite a data que deseja buscar no formato dd/mm/aa: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    buscado = busca(tamanho, agenda, dia, mes, ano);
    if (buscado == NULL){
        printf("Nenhum compromisso foi encontrado");
    } else {
    printf("\nCompromisso buscado %s foi encontrado\n", buscado->descricao);};
    free(agenda);
    return 0;
}