#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

 void inverte_frase(char *frase, char *armazena_frase) {
  int tamanho = strlen(frase);

  for(int i = 0; i < tamanho; i++) {
      armazena_frase[i] = frase[tamanho -1 - i]; 
  }
    armazena_frase[tamanho] = '\0';
 }

 int verifica_palindromo(char *frase) {
    char armazena_frase[TAM];
    inverte_frase(frase, armazena_frase);

    if (strcmp(frase, armazena_frase) == 0) {
       printf("True\n");
       return 1;
    } else {
        printf("False\n");
        return 0;
    }
 }

 int main() {

   char frase[TAM];
   char armazena_frase[TAM];

   printf("Digite a palavra que deve ser verificada:\n");
   fgets(frase, TAM, stdin);
   frase[strlen(frase) - 1] = '\0';

   for(int i = 0;frase[i] != '\0'; i++) {
     frase[i] = tolower(frase[i]);
   }

   int j = 0;

    for (int i = 0; frase[i] != '\0'; i++) {
        if (isalnum(frase[i])) {
            armazena_frase[j++] = frase[i];
        }
    }
    
   armazena_frase[j] = '\0';

   int inverso = verifica_palindromo(armazena_frase);
   

    return 0;
 }