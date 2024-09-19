#include <stdio.h>
#include <stdlib.h>


void busca_fibonacci(int *fibonacci, int n) {

    if (n > 0) {
        fibonacci[0] = 0;
    }
    if (n > 1) {
        fibonacci[1] = 1;
    }

     for(int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

int verifica_numero (int *fibonacci, int n, int x) {

    for(int i = 0; i < n; i++) {

         if (fibonacci[i] == x) {
            return i;
        } 
    }
    
    return -1;

}

int main() {

    int n, x;

    printf("Digite os n primeiros números da sequência de Fibonacci:\n");
    scanf("%d", &n);

    int *fibonacci = (int *)malloc(n * sizeof(int *));

    busca_fibonacci(fibonacci, n);

    printf("Digite o número x que deve ser verificado:\n");
    scanf("%d", &x);

    int indice = verifica_numero(fibonacci, n, x);

    printf("Índice: %d\n", indice);

    free(fibonacci);
  
    return 0;
}
