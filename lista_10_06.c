#include <stdio.h>
#include <string.h>

char* numerosformata(int num);  

int main() {
    FILE *arquivo;
    int i;
    char formatar_arquivos[12], *num;
    for (i = 1; i < 11; i++) {
        if (i < 10) {
            strcpy(formatar_arquivos, "teste");
            num = numerosformata(i);  
            strcat(formatar_arquivos, num);
            strcat(formatar_arquivos, ".txt");  
        }
        else {
            sprintf(formatar_arquivos, "teste%d.txt", i); 
        }
        arquivo = fopen(formatar_arquivos, "w");
        if (arquivo == NULL) {
            printf("Erro");
        }
        if (i < 10) {
            fprintf(arquivo, "Texto do arquivo %s", num);  
            fprintf(arquivo, "Texto do arquivo %d", i);  
        }
        fclose(arquivo);  
    }

    return 0;
}

char* numerosformata(int num) {
    switch (num) {
    case 1:
        return "01";
    case 2:
        return "02";
    case 3:
        return "03";
    case 4:
        return "04";
    case 5:
        return "05";
    case 6:
        return "06";
    case 7:
        return "07";
    case 8:
        return "08";
    case 9:
        return "09";
    default:
        return "Erro";
    }
}