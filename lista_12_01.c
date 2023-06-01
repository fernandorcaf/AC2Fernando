#include <stdio.h>

int mdc_recursiva(int a, int b) {
    printf("%d e %d\n", a, b);
    if (a % b == 0)
        return b;
    return mdc_recursiva(b, a % b);
}

int main() {
    int a = 32;
    int b = 18;
    printf("Resultado = %d\n", mdc_recursiva(a, b));
}
