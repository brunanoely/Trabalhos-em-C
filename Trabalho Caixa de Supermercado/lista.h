#ifndef LISTA_H
#define LISTA_H

#define TAM_NOME 100
#define CAIXAS 5

typedef struct Cliente {   

    char nome[TAM_NOME];
    long long cpf;
    int prioridade;
    int itens_carrinho;

} Cliente;

typedef struct NodoCliente {
    Cliente cliente;
    struct NodoCliente *prox;
} NodoCliente;

typedef struct ListaCliente  {
    NodoCliente * prim;
} ListaCliente;

typedef struct Caixa {

    int num_caixa;
    int estado;// 1- aberto, 0-fechado;
    ListaCliente lista;
    
} Caixa;

typedef struct NodoCaixa {
    Caixa caixa;
    struct NodoCaixa *prox;
} NodoCaixa;

typedef struct ListaCaixas {
    Caixa caixas[5];  // 5 caixas
} ListaCaixas;

void criarListaCliente(ListaCliente *pList);
void cadastrarCliente(ListaCliente *pList, Caixa *caixas[5]);
void inserirPrioridade(ListaCliente *pList, Cliente cliente);
void atenderCliente(ListaCliente *pList, Caixa *caixas[5]);
void abrirFecharCaixa (ListaCliente *pList, Caixa *caixas[5]);
void imprimirListaClientes (ListaCliente *pList);
void imprimirStatusCaixas (Caixa *caixas[5]);


#endif