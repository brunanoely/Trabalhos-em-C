#include <stdio.h>
#include <stdlib.h>

int main() {

    int num_linhas1, num_colunas1, num_linhas2, num_colunas2, numeros1 = 0, numeros2 = 0;

    printf("\nDigite o número de linhas e colunas da primeira matriz:\n");
    scanf("%d %d", &num_linhas1, &num_colunas1);

    printf("\nDigite o número de linhas e colunas da segunda matriz:\n");
    scanf("%d %d", &num_linhas2, &num_colunas2);

    int **matriz1 = (int **)malloc(num_linhas1 * sizeof(int *));
    int **matriz2 = (int **)malloc(num_linhas2 * sizeof(int *));
    int **matriz_resultante = (int **)malloc(num_linhas1 * sizeof(int *));

    for (int i = 0; i < num_linhas1; i++) {
        matriz1[i] = (int *)malloc(num_colunas1 * sizeof(int));
    }

    for (int i = 0; i < num_linhas2; i++) {
        matriz2[i] = (int *)malloc(num_colunas2 * sizeof(int));
        matriz_resultante[i] = (int *)malloc(num_colunas2 * sizeof(int));
    }


    if (num_colunas1 == num_linhas2) {

        numeros1 = num_linhas1 * num_colunas1;
        numeros2 = num_linhas2 * num_colunas2;
        
        printf("\nDigite %d números inteiros para preencher a matriz %dx%d:", numeros1, num_linhas1, num_colunas1);
        
        for(int i = 0; i < num_linhas1; i++) {
            for(int j = 0; j < num_colunas1; j++) {
                printf("\nElemento [%d][%d]: ", i + 1, j + 1);
                scanf("%d", &matriz1[i][j]);
            }
        }

        printf("\nDigite %d números inteiros para preencher a matriz %dx%d:", numeros2, num_linhas2, num_colunas2);

        for(int i = 0; i < num_linhas2; i++) {
            for (int j = 0; j < num_colunas2; j++) {
                printf("\nElemento [%d][%d]: ", i + 1, j + 1);
                scanf("%d", &matriz2[i][j]);
            }
        }

        for(int i = 0; i < num_linhas1; i++) {
            for(int y = 0; y < num_colunas2; y++) { 
                matriz_resultante[i][y] = 0;
            } 
        }
    
        for(int i = 0; i < num_linhas1; i++) {
            for(int y = 0; y < num_colunas2; y++) {
                for (int x = 0; x < num_linhas1; x++) {
                    matriz_resultante[i][y] += matriz1[i][x] * matriz2[x][y];
                }
            } 
        }

        for(int y=0; y < num_linhas1; y++) {
            for (int i = 0; i < num_colunas2; i++) {
                printf("[%d] ", matriz_resultante[y][i]);
            }
            printf("\n");
   } }
        else {printf("erro, as matrizes só podem ser multilplicadas se o número de colunas da primeira for igual ao número de linhas da segunda\n");
        }
    
    free(matriz1);
    free(matriz2);
    free(matriz_resultante);

    return 0;
}