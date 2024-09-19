#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

void criarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

void empilhar(Pilha *pilha, Documento documento) {

    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (novo == NULL)
    {
        printf("Memória insuficiente.\n");
        return;
    }

    Lista *listaAutores = (Lista *)malloc(sizeof(Lista));
    criarLista(listaAutores);

    novo->documento.id = documento.id;
    strcpy(novo->documento.titulo, documento.titulo);

    for (NodoLista *atual = documento.autores->prim; atual != NULL; atual = atual->prox)
    {
        Autor autorNovo;
        autorNovo.id_autor = atual->autor.id_autor;
        strcpy(autorNovo.nome, atual->autor.nome);

        adicionarAutor(listaAutores, autorNovo);
    }

    novo->documento.autores = listaAutores;

    novo->prox = pilha->topo;
    pilha->topo = novo;
}

void desempilhar(Pilha *pilha) {

    if (pilhaEstaVazia(pilha))
    {
        printf("Pilha vazia.\n");
        return;
    }

    printf("\nDocumento removido:\n");
    printf("Id: %d\n", pilha->topo->documento.id);
    printf("Titulo: %s\n", pilha->topo->documento.titulo);

    Nodo *aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(aux);
}

void mostrarTopo(Pilha *pilha) {

     if (pilhaEstaVazia(pilha))
    {
        printf("Pilha vazia.\n");
        return;
    }

    printf("\nTopo da pilha:\n");
    printf("Id: %d\n", pilha->topo->documento.id);
    printf("Nome: %s\n", pilha->topo->documento.titulo);
}

int pilhaEstaVazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

void salvarPilha(Pilha *pilha, const char *filename) {

    FILE *fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        perror("Falha ao abrir arquivo");
        return;
    }

    Nodo *atual = pilha->topo;

    while (atual != NULL)
    {
        fwrite(&atual->documento, sizeof(Nodo), 1, fp);
        atual = atual->prox;
    }

    fclose(fp);
}

void lerPilha(Pilha *pilha, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        perror("Falha ao abrir arquivo");
        return;
    }

    Nodo *novoNodo;
    while (!feof(fp)) {
        novoNodo = (Nodo *)malloc(sizeof(Nodo));
        if (novoNodo == NULL) {
            perror("Erro de alocação de memória");
            fclose(fp);
            return;
        }

        if (fread(&novoNodo->documento, sizeof(novoNodo->documento), 1, fp) == 1) {
            novoNodo->prox = pilha->topo;
            pilha->topo = novoNodo;
        } else {
            free(novoNodo); 
        }
    }
}
