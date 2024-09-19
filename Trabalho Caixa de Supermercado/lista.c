#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void criarListaCliente(ListaCliente *pList)
{
    pList->prim = NULL;
}

void cadastrarCliente(ListaCliente *pList, Caixa *caixas[5])
{   
    int caixa_escolhido;
    NodoCliente *novo;
    novo = (NodoCliente *)malloc(sizeof(NodoCliente));

    if (novo == NULL)
    {
        printf("Erro ao alocar memória\n");
        return;
    }

    getchar();
    printf("Digite o nome do cliente:\n");
    fgets(novo->cliente.nome, TAM_NOME, stdin);
    novo->cliente.nome[strlen(novo->cliente.nome) - 1] = '\0';

    printf("Digite o CPF do cliente:\n");
    scanf("%lld", &novo->cliente.cpf);
    getchar();

    printf("Digite o nível de prioridade do cliente (1- alta, 2- média, 3- baixa)\n");
    scanf("%d", &novo->cliente.prioridade);
    getchar();

    printf("Digite o número de itens no carrinho do cliente: \n");
    scanf("%d", &novo->cliente.itens_carrinho);
    getchar();

    printf("Escolha o caixa em que o cliente vai entrar:\n");
    scanf("%d", &caixa_escolhido);
    getchar();

    Caixa *caixa_atual;

    if (caixa_escolhido > 5 || caixa_escolhido < 1) {
        printf("Esse caixa não existe\n");
        return;
    }

    for (int i = 0; i < CAIXAS; i++) {
        if (caixas[i]->num_caixa == caixa_escolhido) {
            caixa_atual = caixas[i];
        }
    }

    getchar();

    inserirPrioridade(pList, novo->cliente);
}

void inserirPrioridade(ListaCliente *pList, Cliente cliente) {
    NodoCliente *novo = (NodoCliente *)malloc(sizeof(NodoCliente));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }

    novo->cliente = cliente;
    novo->prox = NULL;

    if (pList->prim == NULL) {
        pList->prim = novo;
        return;
    }

    NodoCliente *atual = pList->prim;
    int cont1 = 0, cont2 = 0, cont3 = 0;

    while (atual != NULL) {
        if (atual->cliente.prioridade == 1)
            cont1++;
        if (atual->cliente.prioridade == 2)
            cont2++;
        if (atual->cliente.prioridade == 3)
            cont3++;
        atual = atual->prox;
    }

    atual = pList->prim;
    NodoCliente *anterior = NULL;
    int cont_atual = 0;

    if (cliente.prioridade == 1) {
       
        while (cont_atual < cont1 && atual != NULL) {
            anterior = atual;
            atual = atual->prox;
            cont_atual++;
        }
    } else if (cliente.prioridade == 2) {
        
        while (cont_atual < cont1 + cont2 && atual != NULL) {
            anterior = atual;
            atual = atual->prox;
            cont_atual++;
        }
    } else if (cliente.prioridade == 3) {
        
        while (cont_atual < cont1 + cont2 + cont3 && atual != NULL) {
            anterior = atual;
            atual = atual->prox;
            cont_atual++;
        }
    } else {
        printf("Prioridade inválida");
        free(novo); 
        return;
    }

    if (anterior == NULL) { 
        novo->prox = pList->prim;
        pList->prim = novo;
    } else {
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }
}

void atenderCliente(ListaCliente *pList, Caixa *caixas[5]) {
    
    NodoCliente *atual = pList->prim;
    NodoCliente *clientePrioritario = NULL;

    if (atual != NULL) {
        clientePrioritario = atual;
        while (atual != NULL) {
            if (atual->cliente.prioridade < clientePrioritario->cliente.prioridade) {
                clientePrioritario = atual;
            }
            atual = atual->prox;
        }
    }

    if (clientePrioritario == NULL) {
        printf("Não há clientes na fila para atender\n");
        return;
    }

    int caixa_atender;
    Caixa *caixa_atual = NULL;

    printf("Digite o caixa que deseja atender o cliente:\n");
    scanf("%d", &caixa_atender);

    if (caixa_atender < 1 || caixa_atender > 5) {
        printf("Esse caixa não existe\n");
        return;
    }

    for (int i = 0; i < CAIXAS; i++) {
        if (caixas[i]->num_caixa == caixa_atender) {
            caixa_atual = caixas[i];
        }
    }

    if (caixa_atual == NULL) {
        printf("Caixa inválido.\n");
        return;
    }

    if (caixa_atual->estado == 0) {
        printf("O caixa %d está fechado ou ocupado.\n", caixa_atual->num_caixa);
        return;
    }

    char nomeCliente[50];
    strcpy(nomeCliente, clientePrioritario->cliente.nome);

    NodoCliente *anterior = NULL;
    atual = pList->prim;

    while (atual != NULL && atual->cliente.cpf != clientePrioritario->cliente.cpf) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Cliente não encontrado na fila.\n");
        return;
    }

    if (anterior == NULL) {
        pList->prim = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);

    printf("O cliente %s foi atendido e removido da fila do caixa %d\n", nomeCliente, caixa_atender);

    getchar();
}


void abrirFecharCaixa(ListaCliente *pList, Caixa *caixas[5]) {
    printf("Digite 'A' se deseja abrir um caixa e 'F' se deseja fechar\n"); 
    char abrir_fechar;
    scanf(" %c", &abrir_fechar);
    printf("Digite o número do caixa que deseja abrir/fechar\n");
    int num_abrir_fechar;
    scanf("%d", &num_abrir_fechar);

    getchar();

    Caixa *caixa_atual = NULL;
    for (int i = 0; i < CAIXAS; i++) {
        if (caixas[i]->num_caixa == num_abrir_fechar) {
            caixa_atual = caixas[i];
            break;
        }
    }

    if (caixa_atual == NULL) {
        printf("O caixa %d não existe\n", num_abrir_fechar);
        return;
    }

    if (abrir_fechar == 'A') {
        if (caixa_atual->estado == 1) {
            printf("O caixa %d já está aberto\n", caixa_atual->num_caixa);
            return;
        }
        caixa_atual->estado = 1;
        printf("O caixa %d foi aberto\n", caixa_atual->num_caixa);
    } else if (abrir_fechar == 'F') {
        if (caixa_atual->estado == 0) {
            printf("O caixa %d já está fechado\n", caixa_atual->num_caixa);
            return;
        }

        caixa_atual->estado = 0;
        printf("O caixa %d foi fechado.\n", caixa_atual->num_caixa);

        NodoCliente *atual = caixa_atual->lista.prim;
        NodoCliente *anterior = NULL;

        Caixa *caixa_realocar = NULL;
        for (int i = 0; i < CAIXAS; i++) {
            if (caixas[i]->estado == 1 && caixas[i]->num_caixa != num_abrir_fechar) {
                caixa_realocar = caixas[i];
                break;
            }
        }

        if (caixa_realocar == NULL) {
            printf("Não há caixas abertos disponíveis para realocar os clientes.\n");
            return;
        }

        while (atual != NULL) {
            NodoCliente *temp = atual;
            atual = atual->prox;

            temp->prox = caixa_realocar->lista.prim;
            caixa_realocar->lista.prim = temp;
        }

        caixa_atual->lista.prim = NULL;

        printf("Todos os clientes foram realocados para o caixa %d.\n", caixa_realocar->num_caixa);
    } else {
        printf("Opção inválida.\n");
    }

    getchar();
}

void imprimirListaClientes(ListaCliente *pList) {
    NodoCliente *p = pList->prim;
    while (p != NULL) {
        printf("%s, %lld, %d\n", p->cliente.nome, p->cliente.cpf, p->cliente.itens_carrinho);
        p = p->prox;
    }
}

void imprimirStatusCaixas(Caixa *caixas[5]) {
    for (int i = 0; i < CAIXAS; i++) {
        printf("Caixa %d\nEstado: %s\n", caixas[i]->num_caixa, caixas[i]->estado == 0 ? "Fechado" : "Aberto");
    }
}
