#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 1000

char to_uppercase(char c) {
    return toupper(c);
}

int main() {
    FILE *arquivo;
    FILE *novo_arquivo;
    char nome_arquivo[30];
    char estudantes[TAM] = {};

    printf("Digite o nome do arquivo que deve ser aberto: \n");
    fgets(nome_arquivo, 30, stdin);

    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';

    arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    printf("Digite os nomes dos estudantes, ao finalizar, digite SAIR em letras maiúsculas: \n");

    while(1) {

        fgets(estudantes, TAM, stdin);

        if(strcmp(estudantes, "SAIR\n")==0)  {
            fclose(arquivo);
            printf("O arquivo foi fechado\n");
            break;
        }
        else {
            fputs(estudantes, arquivo);
        }       
    }

    arquivo = fopen(nome_arquivo, "r"); 
     if (arquivo == NULL) {
        printf("Arquivo não encontrado\n");
        return 1;
    }

    novo_arquivo = fopen("arquivo_maiusculo.txt", "w");
    if (novo_arquivo == NULL) {
        perror("Erro ao criar o arquivo de saída");
        fclose(arquivo);
        return 1;
    }

   while(fgets(estudantes, TAM, arquivo) != NULL) {

    for(int i = 0; estudantes[i] != '\0'; i++) {
        estudantes[i] = to_uppercase(estudantes[i]);
    }
        fputs(estudantes, novo_arquivo);

        printf("%s\n", estudantes);
   }

    fclose(arquivo);
    fclose(novo_arquivo);

    return 0;

}