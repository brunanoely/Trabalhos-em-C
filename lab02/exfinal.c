#include <stdio.h> 
int main() 
{
    int op;
    printf("\nDigite o exercício que você deseja executar\n");
    scanf("%d", &op);

    switch (op)
    {
     case 1:
        {   int N;
            int cont = 1;

            printf("\nDigite um número:\n");
            scanf("%d", &N);

            for (int cont = 1; cont <= 10; cont++) {
            printf("%d x %d = %d\n", N, cont, N * cont);
            }

            break;
        }

     case 2:
        {   int N;
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

            break;
        }

     case 3:
        {  int numero, inverso = 0; 

            printf("\nDigite um número:\n");
            scanf("%d", &numero);

            while (numero != 0) {
                    inverso = inverso * 10 + numero % 10;
                    numero = numero / 10;
                }
        
            printf("%d\n", inverso);
            break;
        }

     case 4:
        {  int numero;
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
            break;
        }
    return 0;
    } }