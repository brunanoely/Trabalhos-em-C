#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define limite 128

    void imprime_frequencia (char stringS[TAM]) {

       printf("%s\n", stringS);
        int quantidade = 0;
        
            for (int i=0; i < limite; i++) {

                 for(int y=0; y<strlen(stringS); y++) {
                            if(stringS[y] == i) {
                                quantidade = quantidade + 1;
                            }
                         }

                      if (quantidade > 0){
                        printf("%c = %d\n", i, quantidade);
                       }
                      quantidade = 0;
            } 
    } 

    int main() {

    int vet[limite] = {0};
    char palavra [TAM];
    printf("\nDigite uma palavra, em letras minúsculas: ");
      fgets(palavra, TAM, stdin);
      palavra[strlen(palavra)- 1] = '\0';

    imprime_frequencia(palavra);

    
    return 0;
 }