#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ordena(float* v, int n){
    int fim,i;
    for (fim=n-1; fim>0; fim--)
        for (i=0; i<fim; i++)
            if (v[i]>v[i+1]) {
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
}
int main(){
    int i, c = 0;
    float numero;
    float* numeros;
    FILE* file = fopen("numeros.txt", "r");
    if (file == NULL){
        printf("ERRO");
        exit(1);
    }
    FILE* binfile = fopen("numeros.bin", "wb");
    if (binfile == NULL){
        printf("ERRO");
        exit(1);
    }
    while (fscanf(file, "%f", &numero) != EOF){
        c++;
    }
    printf("%d", c);
    numeros = (float*) malloc (c * sizeof(float));
    if (numeros == NULL){
        printf("Falta de memoria");
        exit(1);
    }
    fclose(file);
    file = fopen("numeros.txt", "r");
    while (fscanf(file, "%f", &numeros[i]) != EOF){
        i++;
    }
    ordena(numeros, c);
    for (i = 0; i < c; i++){
        printf("\n%.2f", numeros[i]);
    }
    fwrite(numeros, sizeof(float), c, binfile);
    fclose(binfile);
    binfile = fopen("numeros.bin", "rb");
    float* numeros2;
    numeros2 = (float*) malloc (c * sizeof(float));
    fread(numeros2, sizeof(float), c, binfile);
    for (i = 0; i < c; i++){
        printf("\n%.2f", numeros2[i]);
    }
    fclose(file);
    fclose(binfile);
    free(numeros);
    return 0;
}