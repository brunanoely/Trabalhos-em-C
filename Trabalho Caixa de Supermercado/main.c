#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


int main() {

    struct ListaCliente minhaListaClientes;
    int op;
    Caixa *caixas[CAIXAS];

    criarListaCliente(&minhaListaClientes);

    for(int i = 0; i < 5; i++) {
        ListaCliente lista;
        caixas[i] = (Caixa*)malloc(sizeof(caixas));
        caixas[i]->num_caixa = i + 1;
        caixas[i]->estado = 1;
        criarListaCliente(&lista);
        caixas[i]->lista = lista;
    }

    do
    {
        printf("0- Sair do programa\n");
        printf("1- Cadastrar cliente\n");
        printf("2- Atender cliente\n");
        printf("3- Abrir/fechar caixa\n");
        printf("4- Imprimir lista de clientes em espera\n");
        printf("5- Imprimir o status dos caixas (aberto ou fechado)\n");

        printf("Digite a opção do menu desejada:\n");
        scanf("%d", &op);

        switch (op)
        {
            case 0: 
            {
                printf("Programa finalizado\n");
                break;
            }

            case 1: 
            {
                cadastrarCliente(&minhaListaClientes, caixas);
                break;
            }

            case 2: 
            {
                atenderCliente(&minhaListaClientes, caixas);
                break;
            }

            case 3:
            {
                abrirFecharCaixa(&minhaListaClientes, caixas);
                break;
            }

            case 4:
            {
                imprimirListaClientes(&minhaListaClientes);
                break;
            }

            case 5:
            {
                imprimirStatusCaixas(caixas);
                break;
            }
        }
    } while (op != 0);
    
}

