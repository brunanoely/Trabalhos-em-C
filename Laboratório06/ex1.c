#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz;
    int **matriz_trans;
    int num_linhas, num_colunas;
    FILE *arq;
    FILE *arq_2;

    printf("Digite o número de linhas da matriz: \n");
    scanf("%d", &num_linhas);
    printf("Digite o número de colunas da matriz: \n");
    scanf("%d", &num_colunas);

    matriz = (int **)malloc(sizeof(int *) * num_linhas);
    if (matriz == NULL) {
        printf("Memória insuficiente.\n");
        exit(1);
    }
    for (int i = 0; i < num_linhas; i++) {
        matriz[i] = (int *)malloc(sizeof(int) * num_colunas);
        if (matriz[i] == NULL) {
            printf("Memória insuficiente.\n");
            exit(1);
        }
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < num_linhas; i++) {
        for (int j = 0; j < num_colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Alocação para a matriz transposta
    matriz_trans = (int **)malloc(sizeof(int *) * num_colunas);
    if (matriz_trans == NULL) {
        printf("Memória insuficiente.\n");
        exit(1);
    }
    for (int i = 0; i < num_colunas; i++) {
        matriz_trans[i] = (int *)malloc(sizeof(int) * num_linhas);
        if (matriz_trans[i] == NULL) {
            printf("Memória insuficiente.\n");
            exit(1);
        }
    }

    for (int i = 0; i < num_linhas; i++) {
        for (int j = 0; j < num_colunas; j++) {
            matriz_trans[j][i] = matriz[i][j];
        }
    }

    arq = fopen("matriz.txt", "w");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo matriz.txt para escrita.\n");
        return 1;
    }

    fprintf(arq, "%d %d\n", num_linhas, num_colunas);
    for (int i = 0; i < num_linhas; i++) {
        for (int j = 0; j < num_colunas; j++) {
            fprintf(arq, "%d ", matriz[i][j]);
        }
        fprintf(arq, "\n");
    }
    fclose(arq);

    arq_2 = fopen("transposta.txt", "w");
    if (arq_2 == NULL) {
        printf("Erro ao abrir o arquivo transposta.txt para escrita.\n");
        return 1;
    }

    fprintf(arq_2, "%d %d\n", num_colunas, num_linhas);
    for (int i = 0; i < num_colunas; i++) {
        for (int j = 0; j < num_linhas; j++) {
            fprintf(arq_2, "%d ", matriz_trans[i][j]);
        }
        fprintf(arq_2, "\n");
    }
    fclose(arq_2);

    for (int i = 0; i < num_linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    for (int i = 0; i < num_colunas; i++) {
        free(matriz_trans[i]);
    }
    free(matriz_trans);

    return 0;
}
