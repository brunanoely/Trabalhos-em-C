#ifndef LISTA_H
#define LISTA_H

#define TAM_NOME 100

    struct Pessoa
    {
        char nome[TAM_NOME];
        char cpf[12];
    };
    
    struct Nodo {
        struct Pessoa info;
        struct Nodo *prox;
    };

    struct ListaSimplesEnc {
        struct Nodo *prim;
    };

    void criarLista(struct ListaSimplesEnc *pList);
    void mostrarLista(struct ListaSimplesEnc *pList);
    void inserirPessoa(struct ListaSimplesEnc *pList, struct Pessoa p);
    void removerPrimPessoa(struct ListaSimplesEnc *pList);
    int estaVazia(struct ListaSimplesEnc *pList);
    void inserirPrioridade(struct ListaSimplesEnc *pList, struct Pessoa p);
    void removerPeloNome(struct ListaSimplesEnc *pList, const char *nome);


    #endif