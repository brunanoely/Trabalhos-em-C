#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void criarLista(Lista *pList){
    pList->prim = NULL;
}

void adicionarAutor (Lista *pList, Autor autor) {
    NodoLista *novo;
    novo = (NodoLista *)malloc(sizeof(NodoLista));
    novo->autor.id_autor = autor.id_autor;
    strcpy(novo->autor.nome, autor.nome);
    novo->prox = pList->prim;
    pList->prim = novo;
}

void removerIni(Lista *pList)
{
    NodoLista *pAux = pList->prim;
    pList->prim = pList->prim->prox;
    free(pAux);
}

int estaVazia(Lista *pList)
{
    return (pList->prim == NULL);
}

void mostrarLista(Lista *pList) {
    puts("Autores: ");
    if(estaVazia(pList) == 1) {
        return;
    }
    for (NodoLista *n = pList->prim; n != NULL; n = n->prox) {
        printf("\n%d, %s\n", n->autor.id_autor, n->autor.nome);
    }
}
