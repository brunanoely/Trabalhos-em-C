#ifndef LISTA_H
#define LISTA_H

#define MAX_NOME 100

typedef struct Autor {
    char nome[MAX_NOME];
    int id_autor;
    struct Autor *prox;
} Autor;

typedef struct NodoLista {
    Autor autor;
    struct NodoLista * prox;
} NodoLista;

typedef struct Lista {
    NodoLista * prim;
} Lista;


void criarLista(Lista *pList);
int estaVazia(Lista *pList);
void mostrarLista(Lista *pList);
void adicionarAutor(Lista *pList, Autor autor);
void removerIni(Lista *pList);


#endif