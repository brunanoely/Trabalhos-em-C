#ifndef PILHA_H
#define PILHA_H

#include "lista.h"

#define TAM_TIT 100

    typedef struct Documento {
        int id;
        char titulo[TAM_TIT];
        Lista *autores;
    } Documento;
    
    typedef struct Nodo {
    Documento documento;
    struct Nodo *prox;
    } Nodo;

    typedef struct Pilha {
        struct Nodo *topo;
    } Pilha;

    void criarPilha(Pilha *pilha);
    void empilhar(Pilha *pilha, Documento documento);
    void desempilhar(Pilha *pilha);
    void mostrarTopo(Pilha *pilha);
    int pilhaEstaVazia(Pilha *pilha);
    void salvarPilha(Pilha *pilha, const char *filename);
    void lerPilha(Pilha *pilha, const char *filename);

#endif