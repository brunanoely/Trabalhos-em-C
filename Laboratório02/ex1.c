#include <stdio.h>
int main()
{
    int N;
    int cont = 1;

    printf("\nDigite um número:\n");
    scanf("%d", &N);

    for (int cont = 1; cont <= 10; cont++) {
        printf("%d x %d = %d\n", N, cont, N * cont);
    }

  return 0;
}