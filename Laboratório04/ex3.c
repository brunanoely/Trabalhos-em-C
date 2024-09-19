#include <stdio.h>
#include <string.h>

#define TAM 100
#define TAM2 200

int main() {

    char frase[TAM];
    char palavra_escola[] = "ESCOLA";
    char palavra_universidade[] = "UNIVERSIDADE";
    char palavra_aluno[] = "ALUNO";
    char palavra_estudante[] = "ESTUDANTE";
    char frase_final[TAM2];


    printf("Digite uma frase, em letras MAIÚSCULAS:\n");
    fgets(frase, TAM, stdin);
    frase[strlen(frase) - 1] = '\0';
    
    int tamanho_frase = strlen(frase);
    int tamanho_frase_final = strlen(frase_final);

   for (int i = 0; i < tamanho_frase; i++) {
        
        if (strncmp(&frase[i], palavra_escola, 6) == 0 && (frase[i + 6] == ' ' || frase[i + 6] == '\0')) {
           
            strcpy(&frase_final[tamanho_frase_final], palavra_universidade);
            tamanho_frase_final += strlen(palavra_universidade);
            i += 5; 
        } 
       
        else if (strncmp(&frase[i], palavra_aluno, 5) == 0 && (frase[i + 5] == ' ' || frase[i + 5] == '\0')) {
            
            strcpy(&frase_final[tamanho_frase_final], palavra_estudante);
            tamanho_frase_final += strlen(palavra_estudante);
            i += 4; 
        } 
        else {
           
            frase_final[tamanho_frase_final++] = frase[i];
        }
    }

    frase_final[tamanho_frase_final] = '\0'; // Finaliza a nova frase

    printf("%s\n", frase_final);

    return 0;
}