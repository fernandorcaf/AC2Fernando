#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
 int ano;
 char titulo[100];
 char autor[100];
 int nVolume; // Número de exemplares de um dado livro.
 float preco;
}Livro;

typedef struct Biblioteca {
 Livro **V; // Armazena a informação de n livros !!
 int nLivros;// Número de livros existentes na biblioteca.
}Biblioteca;

Livro *fillLivro(){
    Livro *novoLivro;
    novoLivro = (Livro*) malloc (sizeof(Livro));
    printf("\nDigite o ano do livro que deseja registrar: \n");
    scanf("%d", &novoLivro->ano);

    printf("\nDigite o titulo do livro que deseja registrar: \n");
    fflush(stdin);
    gets(novoLivro->titulo);

    printf("\nDigite o autor do livro que deseja registrar: \n");
    fflush(stdin);
    gets(novoLivro->autor);

    printf("\nDigite o numero de exemplares do livro que deseja registrar: \n");
    scanf("%d", &novoLivro->nVolume);

    printf("\nDigite o preco do livro que deseja registrar: \n");
    scanf("%f", &novoLivro->preco);

    return novoLivro;
}

Biblioteca * fillBiblioteca(int numLivros){
    int i;
    Biblioteca *biblio;
    biblio = (Biblioteca*) malloc (sizeof(Biblioteca));
    biblio->nLivros = numLivros;
    biblio->V = (Livro**) malloc (numLivros * (sizeof(Livro*)));
    for (i = 0; i < numLivros; i++){
        biblio->V[i] =(Livro*) malloc (sizeof(Livro));
    }
    for (i = 0; i < numLivros; i++){
        biblio->V[i] = fillLivro();
    }
    return biblio;
}

void valorBiblioteca(Biblioteca * b1, int numLivros){
    int i;
    float montanteGasto = 0;
    for (i = 0; i < numLivros; i++){
        montanteGasto = montanteGasto + ((b1->V[i]->preco))*(b1->V[i]->nVolume);
    }
    printf("\nMontante gasto para se comprar todos os exemplares da biblioteca: %.2f\n", montanteGasto);
}

Livro * maiorBiblioteca(Biblioteca * b1, int numLivros){
    int i, maior = b1->V[0]->nVolume;
    Livro *livroMaior;
    livroMaior = (Livro*) malloc (sizeof(Livro));
    livroMaior = b1->V[0];
    for (i = 1; i < numLivros; i++){
        if (b1->V[i]->nVolume > maior){
            maior = b1->V[i]->nVolume;
            livroMaior = b1->V[i];
        }
    }
    return livroMaior;
}

int main(){
    int n;
    printf("Quantos livros deseja armazenar na biblioteca? \n");
    scanf("%d", &n);
    Biblioteca *biblioteka = fillBiblioteca(n);
    valorBiblioteca(biblioteka, n);
    Livro * maiorNumero;
    maiorNumero = (Livro*) malloc (sizeof(Livro));
    maiorNumero = maiorBiblioteca(biblioteka, n);
    printf("\nLivro de maior numero de exemplares eh o  %s\n", maiorNumero->titulo);
    return 0;
}
