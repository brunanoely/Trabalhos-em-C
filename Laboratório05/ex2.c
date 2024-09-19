#include <stdio.h>
#include <string.h>

#define MAX_LINHAS 20
#define MAX_COMPRIMENTO 100

int main() {
    char nome_arquivo[100];
    char linhas[MAX_LINHAS][MAX_COMPRIMENTO]; 
    int contador = 0;
    char palavra_busca[MAX_COMPRIMENTO];

    printf("Digite o nome do arquivo de texto: ");
    fgets(nome_arquivo, MAX_COMPRIMENTO, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';
    
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return 1;
    }

    printf("Digite até 20 frases e ao finalizar, digite FIM para encerrar a entrada):\n");
    while (contador < MAX_LINHAS) {
        printf("Frase %d: ", contador + 1);
        fgets(linhas[contador], MAX_COMPRIMENTO, stdin);

        size_t comprimento = strlen(linhas[contador]);
        if (comprimento > 0 && linhas[contador][comprimento - 1] == '\n') {
            linhas[contador][comprimento - 1] = '\0';
        }

        if (strcmp(linhas[contador], "FIM") == 0) {
            break;
        }

        fprintf(arquivo, "%s\n", linhas[contador]);
        contador++;
    }

    fclose(arquivo);

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 1;
    }

    contador = 0;
    while (fgets(linhas[contador], MAX_COMPRIMENTO, arquivo) != NULL && contador < MAX_LINHAS) {
        size_t comprimento = strlen(linhas[contador]);
        if (comprimento > 0 && linhas[contador][comprimento - 1] == '\n') {
            linhas[contador][comprimento - 1] = '\0';
        }
        contador++;
    }

    fclose(arquivo);

    printf("\nDigite a palavra para busca: ");
    fgets(palavra_busca, MAX_COMPRIMENTO, stdin);
    palavra_busca[strcspn(palavra_busca, "\n")] = '\0'; 

    printf("\nLinhas que possuem a palavra %s:\n", palavra_busca);
    for (int i = 0; i < contador; i++) {
        if (strstr(linhas[i], palavra_busca) != NULL) { 
            printf("Linha %d: %s\n", i + 1, linhas[i]);
        }
    }

    return 0;
}
