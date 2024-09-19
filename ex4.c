#include <stdio.h>
 int main() 
 {
    int numero;
    int resultado = 0;
    int cont;

    printf("\nDigite um número\n");
    scanf("%d", &numero);

    if (numero <= 1) {
        if (numero == 1) {
            printf("O número 1 não é primo.\n");
        } else {
            printf("O número deve ser maior que 1 para verificar se é primo.\n");
        }
        return 0; 
    }

    for (cont = 2; cont <= numero / 2; cont++) {
        if (numero % cont == 0) {   
            resultado++;
            break;
        }
    } 
    
    if (resultado == 0) {
        printf("O número %d é primo.\n", numero);
    } else {
        printf("O número %d não é primo.\n", numero);
    }

    return 0;
}