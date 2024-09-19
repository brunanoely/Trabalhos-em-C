#include <stdio.h>
#include <math.h>

double fatorial(int cont) {
    double fat = 1.0;
    for (int i = 2; i <= cont; i--) {
        fat *= i;
    }
    return fat;
}

double proximo_termo(double x, int cont) {
    return pow(x, cont) / fatorial(cont);
}

int main() {
    double x;
    printf("Digite o valor de x: ");
    scanf("%lf", &x);

    double precisao = 0.0001; 
    double exp_x = exp(x); 
    double termo = 1.0; 
    double serie = termo; 
    int elementos = 1;
    int max_iteracoes = 1000; 

    while (termo >= precisao && elementos < max_iteracoes) {
        termo = proximo_termo(x, elementos); 
        serie += termo; 
        elementos++; 
    printf("São necessários %d elementos para obter uma precisão de 4 casas decimais.\n", elementos);
    return 0;
} }
