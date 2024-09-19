#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void criarLista(struct ListaSimplesEnc *pList) {
    pList->prim = NULL;
}

void mostrarLista(struct ListaSimplesEnc *pList) {
    struct Nodo *p;

    for (p = pList->prim; p != NULL; p = p->prox) {
    printf("Nome: %s, CPF: %s\n", p->info.nome, p->info.cpf);
    }
    printf("\n");
}

void inserirPessoa(struct ListaSimplesEnc *pList, struct Pessoa p) {
    struct Nodo *novo;
    novo = (struct Nodo*)malloc(sizeof(struct Nodo));
    novo->info = p;
    novo->prox = pList->prim;
    pList->prim = novo;

    int cont = 0;
    struct Nodo *temp = pList->prim;
    while (temp->prox != NULL)
    {
        cont++;
        temp = temp->prox;
    }
    
    printf("Pessoa inserida na lista: %s, CPF: %s\n", p.nome, p.cpf);
    printf("Quantidade de pessoas na frente dela: %d\n", cont);
}

void removerPrimPessoa(struct ListaSimplesEnc *pList)
{
    struct Nodo *pAux = pList->prim;
    pList->prim = pList->prim->prox;

    printf("Pessoa removida da lista: %s, CPF: %s\n", pAux-> info.nome, pAux->info.cpf);
    
    free(pAux);

    int cont2 = 0;
    struct Nodo *temp = pList->prim;
    while (temp->prox != NULL)
    {   
        cont2++;
        temp = temp->prox;
    }
    printf("Pessoas restantes na lista: %d\n", cont2);

    
}

void inserirPrioridade(struct ListaSimplesEnc *pList, struct Pessoa p) {
    struct Nodo *novo = (struct Nodo*)malloc(sizeof(struct Nodo));
    novo->info = p;
    novo->prox = pList->prim;
    pList->prim = novo;

    printf("Atendimento prioritário para %s, CPF: %s\n", p.nome, p.cpf);
}

int estaVazia(struct ListaSimplesEnc *pList) {

    return (pList->prim == NULL);
}

void removerPeloNome(struct ListaSimplesEnc *pList, const char *nome) {

    struct Nodo *pAux = pList->prim;
    pList->prim = pList->prim->prox;

    printf("Pessoa removida: %s, CPF: %s\n", pAux->info.nome, pAux->info.cpf);

    free(pAux);

    int count = 0;
    struct Nodo *temp = pList->prim;
    while (temp != NULL) {
        count++;
        temp = temp->prox;
    }
    printf("Restam %d pessoas na lista.\n", count);
}



