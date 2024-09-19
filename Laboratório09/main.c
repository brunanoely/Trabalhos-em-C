#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"

int main() {

    int op;
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));

    criarPilha(pilha);

    do
    {
        printf("0- Sair\n");
        printf("1- Empilhar\n");
        printf("2- Desempilhar\n");
        printf("3- Mostrar topo\n");
        printf("4- Verificar se esta vazia\n");
        printf("5- Salvar pilha\n");
        printf("6- Carregar pilha\n");
        
        printf("Digite a opção do menu desejada:\n");
        scanf("%d", &op);

        switch (op)
        {

        case 0:
        {
            printf("Programa finalizado\n");
            break;
        }

        case 1: {

            Documento *documento = (Documento *)malloc(sizeof(Documento));

            int id;
            char titulo[TAM_TIT];

            printf("Digite a id do documento: ");
            scanf("%d", &id);

            getchar();

            printf("Digite o nome do documento: ");
            fgets(titulo, 100, stdin);
            titulo[strlen(titulo) - 1] = '\0';

            Lista *listaAutores = (Lista *) malloc(sizeof(Lista));
            int autoresNum;
            criarLista(listaAutores);

            printf("Digite o número de autores: ");
            scanf("%d", &autoresNum);

            for(int i = 0; i < autoresNum; i++) {
                int autorId;

                printf("Id do autor: ");
                scanf("%d", &autorId);
                getchar();

                char nomeTemp[100];
                    
                printf("Nome do autor: ");
                fgets(nomeTemp, 100, stdin);
                nomeTemp[strlen(nomeTemp) - 1] = '\0';

                Autor autorNovo;
                autorNovo.id_autor = autorId;
                strcpy(autorNovo.nome, nomeTemp);

                adicionarAutor(listaAutores, autorNovo);
            }

            documento->id = id;
            strcpy(documento->titulo, titulo);
            documento->autores = listaAutores;

            empilhar(pilha, *documento);
            break;
        }

        case 2: {
            desempilhar(pilha);
            break;
        }

        case 3: {
            mostrarTopo(pilha);
            if(pilhaEstaVazia(pilha) == 1) {
                break;
            }
            mostrarLista(pilha->topo->documento.autores);
            break;
        }

        case 4: {
            if (pilhaEstaVazia(pilha)) {
                printf("A lista está vazia\n");
            } else {
                printf("A lista não está vazia\n");
            }
            break;

        }

        case 5: {
            
            getchar();

            char nome_arquivo[100];
            printf("Digite o nome do arquivo: ");
            fgets(nome_arquivo, 100, stdin);
            nome_arquivo[strlen(nome_arquivo) - 1] = '\0';

            salvarPilha(pilha, nome_arquivo);

            break;
        }

        case 6: {

            getchar();

            char nome_arquivo[100];
            printf("Digite o nome do arquivo: ");
            fgets(nome_arquivo, 100, stdin);
            if (nome_arquivo[strlen(nome_arquivo) - 1] == '\n') {
            nome_arquivo[strlen(nome_arquivo) - 1] = '\0';
            }

            lerPilha(pilha, nome_arquivo);

            break;
        }
        default: {
            printf("Erro\n");
            break;
        }

    }
}   while (op != 0);
    
return 0;
}