#include <stdio.h>

    int digito_verificador1 (long long int CNPJ) {

        long long int soma = 0, base = CNPJ, peso = 2, dezena = 0;

        while (base > 0) {
            int digito = base % 10;
            soma += digito * peso;
            base /= 10; 
            peso++; 
        if (peso > 9) 
            peso = 2;
    }
        if (soma % 11 == 0 || soma % 11 == 1) {
            dezena = 0;
        } else {
            dezena = (11 - (soma % 11));
        }
        
        return dezena;
    }

    int digito_verificador2 (long long int CNPJ) {

        long long int base2 = CNPJ * 10;
        int soma2 = 0, peso = 2, unidade = 0;
        int primeiro_digito = digito_verificador1(CNPJ);
        
        base2 += primeiro_digito;

        while (base2 > 0) {
            int digito = base2 % 10;
            soma2 += digito * peso;
            base2 /= 10; 
            peso++; 
        if (peso > 9) 
            peso = 2;
        }
        
        if (soma2 % 11 == 0) {
            unidade = 0;
        } else {
            unidade = (11 - (soma2 % 11));
        }
        return unidade;
    }


    int main () {

        long long int CNPJ;

        printf("Digite o CNPJ (12 dígitos): \n");
        scanf("%lld", &CNPJ);

        int verificador1 = digito_verificador1(CNPJ);
        int verificador2 = digito_verificador2(CNPJ);

        printf("CNPJ com os dígitos verificadores: %012lld-%02d%02d\n", CNPJ,verificador1, verificador2);
    }
