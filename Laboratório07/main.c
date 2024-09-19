#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {

struct ListaSimplesEnc minhaLista;
struct Pessoa p;
int op;

criarLista(&minhaLista);

while (1) {
    printf("1 - Inserir pessoas na lista\n");
    printf("2 - Remover primeira pessoa da lista\n");
    printf("3 - Imprimir lista\n");
    printf("4 - Verificar se a lista está vazia\n");
    printf("5 - Atendiemnto prioritário\n");
    printf("6 - Remover pessoa pelo nome\n");
    printf("7 - Sair\n");
    printf("Opcao? ");
    scanf("%d", &op);

switch (op) {

    case 1: // inserir pessoas no inicio
        printf("Nome da pessoa: ");
        scanf("%s", p.nome);
        printf("CPF: ");
        scanf("%s", p.cpf);
        inserirPessoa(&minhaLista, p);
        break;

    case 2: // remover a primeira pessoa da lista
        removerPrimPessoa(&minhaLista);
        break;

    case 3: // imprimir pessoas que estão na lista
        mostrarLista(&minhaLista);
        break;

    case 4: // ver se a lista está vazia
        if (estaVazia(&minhaLista)) {
            printf("Lista vazia\n");
        } else {
            printf("A lista não está vazia\n");
        }   
        break;

    case 5: // atendimento prioritário
        printf("Nome da pessoa com atendimento prioritário: ");
        scanf(" %s", p.nome);
        printf("CPF: ");
        scanf("%s", p.cpf);
        inserirPrioridade(&minhaLista, p);
        break;

    case 6: // remover pessoa pelo nome
        printf("Nome da pessoa a remover: ");
        char nomeRemover[TAM_NOME];
        scanf("%s", nomeRemover);
        removerPeloNome(&minhaLista, nomeRemover);
        break;

    case 7: // abandonar o programa
        exit(0);
        }
    }

    return 0;
}