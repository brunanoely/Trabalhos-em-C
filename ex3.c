#include <stdio.h>
int main() 
{
     
    int numero, inverso = 0; 

    printf("\nDigite um número:\n");
    scanf("%d", &numero);

    while (numero != 0) {
        inverso = inverso * 10 + numero % 10;
        numero = numero / 10;
    }
    
    printf("%d\n", inverso);
    return 0;

}