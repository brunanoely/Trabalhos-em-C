#include <stdio.h>
int main()
{
    int N;
    int fatorial = 1;
    int cont;
    

    printf("\nDigite um número para calcular o fatorial:\n");
    scanf("%d", &N);

    cont = N;

    do {
        fatorial *= cont;
        cont--;
    } while (cont > 1);

    printf("O fatorial de %d é %d\n", N, fatorial);

    return 0;
}