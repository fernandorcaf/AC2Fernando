#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *estado[27] = {"AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA",
"PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"};

typedef struct assalariados {
    char nome[51];
    char sexo;
    int idade;
    float salario;
    char estado[3];
} Assalariados;

Assalariados *cadastra(char *nome, char sexo, int idade, float salario, char *estado);
void relatorio(Assalariados **ptr, int numAssalariados);
void imprime(Assalariados **ptr, int numAssalariados);

int main (void) {

    Assalariados **pessoas;
    int numAssalariados = 3;
    pessoas = (Assalariados **) malloc (numAssalariados *sizeof(Assalariados *));
    if(pessoas == NULL) { printf("Falta de memoria"); exit(1); }

    pessoas[0] = cadastra("Fulano de tal", 'M',45,1500.00, "RJ");
    pessoas[1] = cadastra("Ciclano", 'M',50,2500.00, "RS");
    pessoas[2] = cadastra("Beltrano", 'M',42,500.00, "RS");
    imprime(pessoas, numAssalariados);
    relatorio(pessoas, numAssalariados);

    free(pessoas);

    return 0;
}

Assalariados *cadastra(char *nome, char sexo, int idade, float salario, char *estado) {
    Assalariados *funcionario;
    funcionario = (Assalariados*) malloc(sizeof(Assalariados));
    if (funcionario == NULL) { printf("Falta de memoria"); exit(1); }
        strcpy(funcionario->nome, nome);
        funcionario->sexo = sexo;
        funcionario->idade = idade;
        funcionario->salario = salario;
        strcpy(funcionario->estado, estado);

    return funcionario;
}

void imprime(Assalariados **ptr, int numAssalariados) {
    for(int i = 0; i < numAssalariados; i++) {
        printf("\nFUNCIONARIO %d\n",i+1);
        printf("NOME: %s\n", ptr[i]->nome);
        printf("SEXO: %c\n", ptr[i]->sexo);
        printf("IDADE: %d\n", ptr[i]->idade);
        printf("SALARIO: %.2f\n", ptr[i]->salario);
        printf("ESTADO: %s\n", ptr[i]->estado);
    }
}

void relatorio(Assalariados ** ptr, int numAssalariados) {
    int homens = 0;

    for(int i = 0; i < numAssalariados; i++) {
        if ((ptr[i]->idade > 40) && (ptr[i]->salario > 1000.00)) {
            homens++;
            printf("Estado %s com %d homens maiores de 40 anos e salario maior que R$ 1000,00\n", ptr[i]->estado, homens);
        }
    homens = 0;
    }
}




