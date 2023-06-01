#include <stdio.h>

void teste_de_mesa(int decimal, int *vetor_binario, int tamanho, int tamanho_fixo, int *binario) {
    printf("decimal=%d tamanho=%d tamanho_fixo=%d", decimal, tamanho, tamanho_fixo);
    if (vetor_binario) {
        printf(" vetor_binario={");
        for (int i = 0; i < tamanho_fixo; i++) {
            switch (vetor_binario[i]) {
            case 0:
            case 1:
                printf("%d", vetor_binario[i]);
                break;
            default:
                printf("?");
            }
            printf(i < tamanho_fixo - 1? "," : "}");
        }
    }
    if (binario)
        printf(" binario=%d ", *binario);
    else
        printf(" binario=?");
    printf("\n");
}

int conversao_binaria(int n, int *vetor_binario, int tamanho, int tamanho_fixo) {
    teste_de_mesa(n, vetor_binario, tamanho, tamanho_fixo, NULL);

    vetor_binario[tamanho] = (n % 2);
    n /= 2;
    teste_de_mesa(n, vetor_binario, tamanho, tamanho_fixo, NULL);

    if (tamanho > 0) {
        tamanho--;
        return conversao_binaria(n, vetor_binario, tamanho, tamanho_fixo);
    }

    if(tamanho == 0) {
        int indice, binario;
        binario = 0;
        for (indice = 0; indice < tamanho_fixo; indice++) {
            teste_de_mesa(n, vetor_binario, tamanho, tamanho_fixo, &binario);

            if(indice == 0) {
                if(vetor_binario[indice] == 0) {
                    binario = 0;
                    teste_de_mesa(n, vetor_binario, tamanho, tamanho_fixo, &binario);
                } else {
                    binario = 1;
                    teste_de_mesa(n, vetor_binario, tamanho, tamanho_fixo, &binario);
                }
            } else {
                if (vetor_binario[indice] == 0) {
                    binario *= 10;
                    teste_de_mesa(n, vetor_binario, tamanho, tamanho_fixo, &binario);
                } else {
                    binario = (binario * 10) + 1;
                    teste_de_mesa(n, vetor_binario, tamanho, tamanho_fixo, &binario);
                }
            }
        }
        teste_de_mesa(n, vetor_binario, tamanho, tamanho_fixo, &binario);
        return binario;
    }
}

int main(void) {
    int n;
    printf("Insira um valor inteiro decimal para ser convertido em binario: ");
    scanf("%d", &n);

    int indice, tamanho, tamanho_fixo, numero_binario;
    tamanho = 0;
    for (indice = n; indice > 0;) {
        indice /= 2;
        tamanho++;
    }
    tamanho_fixo = tamanho;
    int vetor_binario[tamanho];
    tamanho -= 1;

    numero_binario = conversao_binaria(n, vetor_binario, tamanho, tamanho_fixo);
    printf("O numero digitado em binario eh %d\n", numero_binario);
    return 0;
}
