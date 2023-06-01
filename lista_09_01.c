#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct notas {
float geral; /* prova de conhecimentos gerais */
float especifica; /* prova de conhecimentos
especificos */
} Notas;

typedef struct local {
char ender[81]; /* endereço do local de provas */
int sala; /* numero sala */
} Local;

typedef struct data {
int dia, mes, ano;
} Data;

typedef struct candidato {
int inscr; /* numero de inscricao */
char nome[81]; /* nome do candidato */
Data nasc; /* data de nascimento */
Local *loc; /* local de prova */
Notas nt; /* notas de prova */
} Candidato;

int main(){
    int n, i, valor;

    printf("Digite o numero de candidatos que deseja registar ou consultar: \n");
    scanf("%d", &n);
    Candidato *candidatos;
    candidatos = (Candidato*) malloc(n*sizeof(Candidato));
    if(candidatos == NULL){printf("Memoria insuficiente"); 
    exit(1);}

    printf("Digite (1) para registar\n");
    printf(".......(2) para consultar\n");
    printf(".......(3) para modificar endereco\n");
    printf(".......(4) para sair: ");

    scanf("%d", &valor);

    while (valor != 4){
        switch (valor){
            case 1:
            for (i = 0; i < n; i++){
                printf("\nDigite o numero de inscricao do candidato %d: \n", i + 1);
                scanf("%d", &candidatos[i].inscr);

                printf("\nDigite o nome do candidato: \n");
                fflush(stdin);
                gets(candidatos[i].nome);

                printf("\nDigite a data de nascimento candidato no formato dd/mm/aa: \n");
                scanf("%d/%d/%d", &candidatos[i].nasc.dia, &candidatos[i].nasc.mes, &candidatos[i].nasc.ano);

                candidatos[i].loc = malloc(sizeof(Local));
                printf("\nDigite o endereco e sala de realizacao da prova: \n");
                fflush(stdin);
                gets(candidatos[i].loc->ender);
                scanf("%d", &candidatos->loc->sala);

                printf("\nDigite as notas das respectivas provas geral e especifica: \n");
                scanf("%f %f", &candidatos[i].nt.geral, &candidatos[i].nt.especifica);
            }
            break;
            case 2:
            for (i = 0; i < n; i++){
                printf("\nNumero de inscricao do candidato: %d\n", candidatos[i].inscr);
                printf("Nome do candidato %d: %s\n", candidatos[i].inscr, candidatos[i].nome);
                printf("Data de nascimento do candidato %d: %d/%d/%d\n", candidatos[i].inscr, candidatos[i].nasc.dia, candidatos[i].nasc.mes, candidatos[i].nasc.ano);
                printf("Endereco e sala de prova do candidato %d: %s %d\n", candidatos[i].inscr, candidatos[i].loc->ender, candidatos[i].loc->sala);
                printf("Notas de prova geral e especifica do candiato %d: %.2f e %.2f\n", candidatos[i].inscr, candidatos[i].nt.geral, candidatos[i].nt.especifica);
            }
            break;
            case 3: ;
            int isncrAlterar;
            char novoEnd[81];
            int novaSala;
            printf("\nDigite a inscricao do aluno que deseja alterar endereco e numero de sala:\n");
            scanf("%d", &isncrAlterar);
            for (i = 0; i < n; i++){
                if (candidatos[i].inscr == isncrAlterar){
                    printf("\nDigite novo endereco: \n");
                    fflush(stdin);
                    gets(novoEnd);
                    printf("\nDigite nova sala: \n");
                    scanf("%d", &novaSala);

                    strcpy(candidatos[i].loc->ender, novoEnd);
                    candidatos[i].loc->sala = novaSala;

                    printf("\nO novo endereco eh %s e o numero da nova sala eh %d\n", candidatos[i].loc->ender, candidatos[i].loc->sala);
                }
                break;
            }

        }   
    printf("\nDigite (1) para registar\n");
    printf(".......(2) para consultar\n");
    printf(".......(3) para modificar endereco\n");
    printf(".......(4) para sair: ");

    scanf("%d", &valor);
    }
    return 0;
}