#include <stdio.h>
#include <string.h>

#define TAM 100
#define MAX 200

int main() {

    char frase[TAM];
    char palavra[] = "TECLADO";
    char nova_palavra[] = " OU MOUSE";
    char armazena_teclado[8];
    char resultado[MAX];

    printf("Digite uma frase, em letras MAIÚSCULAS:\n");
    fgets(frase, TAM, stdin);
    frase[strlen(frase) - 1] = '\0';
    
    int tamanho_frase = strlen(frase);
    int cont = 0;
    int k = 0; 

    for (int i = 0; i < tamanho_frase; i++) {

        for (int j = 0; j < 7; j++) {
            armazena_teclado[j] = '\0';
        }

        cont = 0;
        for (int j = i; j < i + 7 && j < tamanho_frase; j++) {
            armazena_teclado[cont] = frase[j];
            cont++;
        }

        if (cont == 7 && strcmp(armazena_teclado, palavra) == 0) {
           
            for (int j = 0; j < 7; j++) {
                resultado[k++] = armazena_teclado[j];
            }
           
            for (int j = 0; j < strlen(nova_palavra); j++) {
                resultado[k++] = nova_palavra[j];
            }
            i += 6; 
        } else {
            resultado[k++] = frase[i]; 
        }
    }

    resultado[k] = '\0'; 

    printf("%s\n", resultado);

    return 0;
}


