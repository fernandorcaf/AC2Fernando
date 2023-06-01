#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bolha(char *v){
    int fim, i;
    int n = strlen(v);
    for (fim = n - 1; fim > 0; fim--)
        for (i=0; i<fim; i++)
            if (v[i]>v[i+1]) {
                int temp = v[i]; /* troca */
                v[i] = v[i+1];
                v[i+1] = temp;
            }
    }

void rapida (int n, char *v){
    if (n > 1) {
    int x = v[0];
    int a = 1;
    int b = n-1;
    do {
        while (a < n && v[a] <= x) a++; 
        while (v[b] > x) b--; 
        if (a < b) {
            int temp = v[a];
            v[a] = v[b];
            v[b] = temp;
            a++; b--;
        }
    } while (a <= b);
    v[0] = v[b];
    v[b] = x;

    rapida(b, v);
    rapida(n-a, &v[a]);
    }
}

static int compara (const void* p1, const void* p2)
{
char *f1 = (char*)p1;
char *f2 = (char*)p2;
return strcmp(f1, f2);
}


int main(){
    char vetor[] = "Fernando Rene Cabral Araujo Filho";
    int tamanho = strlen(vetor);
    bolha(vetor);
    rapida(tamanho, vetor);
    qsort(vetor, tamanho, sizeof(char), compara);
    return 0;
}