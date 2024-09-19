#include <stdio.h>
#include <string.h>
#include "fila.h"

int main() {

    Fila *f = criar_fila(); // Cria uma fila vazia
    Pessoa pessoa;
    int opcao; // Variáveis para armazenar a opção do menu e o dado a ser inserido ou removido

    do {
        printf("Escolha uma opção:\n");
        printf("1 - Inserir uma pessoa no fim da fila:\n");
        printf("2 - Remover uma pessoa da fila\n");
        printf("3 - Imprimir a fila\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        getchar();

    switch (opcao) {
        case 1: // Inserir na fila
            printf("Digite o nome da pessoa a ser inserida na fila: \n");
            fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
            pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';

            printf("Digite o cpf da pessoa:\n");
            fgets(pessoa.cpf, sizeof(pessoa.cpf), stdin);
            pessoa.cpf[strcspn(pessoa.cpf, "\n")] = '\0';

            enfileirar(f, pessoa);
            break;

        case 2: // Remover da fila
            pessoa = desenfileirar(f);
            if (strlen(pessoa.nome) != -1) {
            printf("Pessoa removida: %s\n", pessoa.nome);
            }
            break;

        case 3: // Imprimir a fila
        mostrar_fila(f);
        break;

        case 0: // Sair
        break;

        default: // Opção inválida
        printf("Opção inválida.\n");
        break;
    }
    } while (opcao != 0);

    liberar_fila(f); // Libera a memória da fila
    
    return 0;
}