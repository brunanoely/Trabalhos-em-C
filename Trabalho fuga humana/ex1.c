#include <stdio.h>

#define LINHAS 20
#define COLUNAS 20

void imprimirMatriz(char matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int dentroDosLimites(int x, int y) {
    return x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS;
}

// Usando uma função recursiva para achar o caminho e uma matriz auxiliar de visitas
int fuga_humana(char matriz[LINHAS][COLUNAS], int x, int y, int zona_x, int zona_y, int visitas[LINHAS][COLUNAS]) {

    if (!dentroDosLimites(x, y) || matriz[x][y] == 'R' || visitas[x][y]) {
        return 0; // não está nos limites, espaço ocupado ou já visitado
    }

    if (x == zona_x && y == zona_y) {
        matriz[x][y] = '*'; 
        return 1; 
    }

    visitas[x][y] = 1; // Marca o espaço como visitado
    matriz[x][y] = '*'; // Marca o espaço como parte do caminho

    int direcoes[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Cima, Baixo, Esquerda, Direita

    for (int i = 0; i < 4; i++) {
        int novoX = x + direcoes[i][0];
        int novoY = y + direcoes[i][1];

        if (fuga_humana(matriz, novoX, novoY, zona_x, zona_y, visitas)) {
            return 1; // Caminho encontrado
        }
    }

    matriz[x][y] = ' '; // Desmarca o espaço se não encontrar um caminho
    return 0; // Nenhum caminho encontrado
}

int main() {
    char matriz[LINHAS][COLUNAS] = {
    {'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'},
    {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'H', ' ', ' ', ' ', ' ', ' ', ' ', 'R', ' ', ' ', ' ', ' ', 'R', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', 'R', ' ', 'R', ' ', 'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', ' ', ' ', 'R', ' ', 'R', ' ', ' ', ' ', ' ', 'R', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R', ' ', 'R', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', ' ', ' ', ' ', ' ', 'R', ' ', ' ', ' ', ' ', 'R', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', 'R', ' ', 'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Z'},
    {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', 'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', ' ', ' ', ' ', ' ', 'R', ' ', 'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
    {'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'}
};

    int visitas[LINHAS][COLUNAS] = {0}; // Matriz de visitas

    int startX = -1, startY = -1;

    // Encontra a posição do humano ('H')
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (matriz[i][j] == 'H') {
                startX = i;
                startY = j;
                break;
            }
        }
        if (startX != -1) break;
    }

    int zona_x = -1, zona_y = -1;

    // Encontra a posição da zona de evacuação ('Z')
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (matriz[i][j] == 'Z') {
                zona_x = i;
                zona_y = j;
                break;
            }
        }
        if (zona_x != -1) break;
    }

    if (startX != -1 && fuga_humana(matriz, startX, startY, zona_x, zona_y, visitas)) {
        printf("Caminho encontrado\n");
    } else {
        printf("Nenhum caminho encontrado\n");
    }

    imprimirMatriz(matriz);

    return 0;
}
