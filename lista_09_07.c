#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
int matricula;
char nomeDoAluno[81];
};
typedef struct aluno Aluno;
struct prova {
Aluno a;
float q1, q2, q3, q4;
};
typedef struct prova Prova;

int compara(Prova* b1, Prova* b2){
    float soma1 = b1->q1 + b1->q2 + b1->q3 + b1->q4;
    float soma2 = b2->q1 + b2->q2 + b2->q3 + b2->q4;
    printf("%.f  ",soma1);
    if ((soma2 > soma1) || ((soma2 == soma1) && (b2->a.nomeDoAluno[0] < b1->a.nomeDoAluno[0])) ) {
        return 1;
    }
    return 0;
}

void troca(Prova *a1, Prova*b){
    int temp0;
    temp0 = a1->a.matricula;
    a1->a.matricula = b->a.matricula;
    b->a.matricula = temp0;
    float temp;
    temp = a1->q1;
    a1->q1 = b->q1;
    b->q1 = temp;
    temp = a1->q2;
    a1->q2 = b->q2;
    b->q2 = temp;
    temp = a1->q3;
    a1->q3 = b->q3;
    b->q3 = temp;
    temp = a1->q4;
    a1->q4 = b->q4;
    b->q4 = temp;
    for (int i = 0; i < 81; i ++){
        char temp = a1->a.nomeDoAluno[i];
        a1->a.nomeDoAluno[i] = b->a.nomeDoAluno[i];
        b->a.nomeDoAluno[i] = temp;
    }
}


void ordena(int n, Prova** v)
{
int fim,i;
for(fim = n-1; fim>0; fim--){
    for(i=0; i<fim; i++){
        if(compara(v[i],v[i+1])){
            troca(v[i],v[i+1]);
        }
    }
}

}

int main(){
    Prova *vet [3];
    for (int i = 0; i < 3; i++){
        vet[i] = (Prova*)malloc(sizeof(Prova));
        if (vet[i]==NULL){exit(1);}
    }
    strcpy(vet[0]->a.nomeDoAluno,"Maria");
    vet[0]->q1 = 1.5; vet[0]->q2 = 2.0; vet[0]->q3 = 0; vet[0]->q4 = 0;
    strcpy(vet[1]->a.nomeDoAluno,"Sandra");
    vet[1]->q1 = 2.5; vet[1]->q2 = 2.0; vet[1]->q3 = 2.0; vet[1]->q4 = 0;
    strcpy(vet[2]->a.nomeDoAluno,"Ana");
    vet[2]->q1 = 2.5; vet[2]->q2 = 2.5; vet[2]->q3 = 2.5; vet[2]->q4 = 2.5;
    ordena (3,vet);
    for (int i = 0; i < 3; i++){
        printf(" %s ",vet[i]->a.nomeDoAluno);
    }
    return 0;
}
