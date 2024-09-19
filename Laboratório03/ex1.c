#include <stdio.h>
#include <math.h>

int soma_dos_cubos(int a, int b) {
    int soma = 0;

    if (a % 2 == 0) {
        for (int i = a; i <= b; i += 2) {
            soma += pow(i, 3);
            
        }
    } else if (a % 2 != 0) {
        for (int i = a + 1; i <= b; i += 2) {
            soma += pow(i, 3);
        }
    } else if ( a == 0 && b == 0) {
        return 1;
    }

    return soma;
}

void sequencia_de_numeros(int a, int b) {

    printf("Sequência de números de %d até %d:\n", a, b);
    
    if (a % 2 == 0) {
        for (int i = a; i <= b; i += 2) {
            printf("%d ", i);
        }
    } else {
        for (int i = a + 1; i <= b; i += 2) {
            printf("%d ", i);
        }
    }
}

int main() {
    int a, b, result, sequencia;

    printf("Digite dois números para a e b:\n");
    scanf("%d %d", &a, &b);

    sequencia_de_numeros(a, b);
    printf("\n");
    
    result = soma_dos_cubos(a, b);

    printf("Soma dos cubos = %d\n", result);

    return 0;
}
