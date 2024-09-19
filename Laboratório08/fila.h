#ifndef FILA_H
#define FILA_H

// Define o tipo de dados que será armazenado na fila
typedef struct { 
    char nome[50];
    char cpf[12];
} Pessoa;

// Define o nó da fila
typedef struct No {
    Pessoa pessoa; // O dado do nó
    struct No *prox; // O ponteiro para o próximo nó
} No;

// Define a fila
typedef struct fila {
    No *inicio; // O ponteiro para o início da fila
    No *fim; // O ponteiro para o fim da fila
} Fila;

// Cria uma fila vazia e retorna seu endereço
Fila* criar_fila();

// Insere um dado no fim da fila
void enfileirar(Fila *f, Pessoa Pessoa);

// Remove um dado do início da fila e retorna seu valor
Pessoa desenfileirar(Fila *f);

// Imprime os dados da fila na ordem do início ao fim
void mostrar_fila(Fila *f);

// Verifica se a fila está vazia e retorna 1 se sim, 0 se não
int fila_vazia(Fila *f);

// Libera a memória de uma fila e seus nós
void liberar_fila(Fila *f);

#endif