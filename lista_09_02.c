#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
int dia;
int mes;
char nomeMes[12];
} Data;

int main(){
Data aniversarios[3] = { {5,1,"JANEIRO"},
{4,2,"FEVEREIRO"},{10,3,"MAIO"} };
int a;
Data *p_dt;
p_dt=&aniversarios[2];
printf("Nome do mês %d é: %s.", p_dt->mes, p_dt->nomeMes);
strcpy(p_dt->nomeMes, "MARÇO");
printf("\nNúmero de letras : %d=", strlen(p_dt->nomeMes));
/*Data p_dt2 = (Data *) malloc(sizeof(Data));   Linha anterior   */
Data *p_dt2 = (Data *) malloc(sizeof(Data)); /* Linha corrigida  */
p_dt2 = &aniversarios[0];
}

/*

a. na linha 16 atribuia-se valor tipo ponteiro data a um valor de tipo data e pode-se corrigir ao atribuir o mesmo valor a uma variavel de tipo ponteiro data.

b. o valor exibido  eh 6.

*/