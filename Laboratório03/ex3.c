#include <stdio.h>

int soma_dos_produtos(int CPF) {
    int digito = 0;
    int soma = 0;

    if (CPF >= 1000000000) {
        printf("Número de CPF inválido\n");
    } else {
        for (int i = 2; i <= 10; i++) {
            digito = CPF % 10;
            digito *= i;
            soma += digito;
            CPF /= 10;
        }
    }
    printf("Soma dos produtos: %d\n", soma);
    return soma;
}

int primeiro_verificador(int soma) {
    int resto = soma % 11;
    int digito_verificador1;

    if (resto < 2) {
        digito_verificador1 = 0;
    } else {
        digito_verificador1 = 11 - resto;
    }
    return digito_verificador1;
}

int soma_dos_produtos2(int CPF) {
    int resto = 0, soma2 = 0, digito2 = 0, digito_verificador1;
    int digito0 = digito_verificador1;

    for (int i = 3; i <= 11; i++) {
        digito2 = CPF % 10;
        digito2 *= i;
        soma2 += digito2;
        CPF /= 10;
    }

    soma2 += 2 * digito0;

    printf("Soma dos produtos 2: %d\n", soma2);

    return soma2;
}

int segundo_verificador(int soma2) {
    int resto = 0;
    resto = soma2 % 11;
    int digito_verificador2;

    if (resto < 2) {
        digito_verificador2 = 0;
    } else {
        digito_verificador2 = 11 - resto;
    }

    return digito_verificador2;
}


int main() {
    int CPF, digito_verificador1, digito_verificador2;

    printf("Digite o CPF: \n");
    scanf("%d", &CPF);

    int soma = soma_dos_produtos(CPF);
    digito_verificador1 = primeiro_verificador(soma);
    int soma_ajustada = soma_dos_produtos2(CPF);
    digito_verificador2 = segundo_verificador(soma_ajustada);
   
    printf("CPF com dígitos verificadores: %d-%d%d\n", CPF, digito_verificador1, digito_verificador2);
    return 0;
}
