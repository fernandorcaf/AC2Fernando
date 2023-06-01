#include <stdio.h>
#include <string.h>

void inspeciona(char *misterio, int index) {
    printf("misterio[%d]='%c'\n", index, misterio[index]);
}

int main (void) {
    char *frase = "Otimo teste";
    char *p, misterio[80];
    int i = 0;
    int j = 0;
    p = frase + strlen(frase) - 1;

    while (*p != ' ') {
        misterio[i] = *p;
        inspeciona(misterio, i);
        i ++;
        p --;
    }

    misterio[i] = ' ';
    inspeciona(misterio, i);
    i++;

    while (frase[j] != ' ') {
        misterio[i] = frase[j];
        inspeciona(misterio, i);
        j ++;
        i ++;
    }

    misterio[i] = '\0';
    inspeciona(misterio, i);
    puts(misterio);
    return 0;
}
