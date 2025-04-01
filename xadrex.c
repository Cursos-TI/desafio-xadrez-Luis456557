#include <stdio.h>

#define SIZE 8

// Função para imprimir o tabuleiro
void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[SIZE][SIZE];
    int x = 0, y = 0; // Posição inicial da peça
    char move;

    // Inicializa o tabuleiro com espaços vazios
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }

    board[x][y] = 'P'; // Peça representada pela letra 'P'

    do {
        system("cls"); // Limpa o terminal (use "clear" no Linux/macOS)
        printBoard(board);
        printf("Use W (cima), S (baixo), A (esquerda), D (direita) para mover. Q para sair.\n");
        printf("Digite seu movimento: ");
        scanf(" %c", &move);

        // Apaga a peça da posição atual
        board[x][y] = '.';

        // Processa o movimento
        switch (move) {
            case 'W': case 'w': if (x > 0) x--; break;
            case 'S': case 's': if (x < SIZE - 1) x++; break;
            case 'A': case 'a': if (y > 0) y--; break;
            case 'D': case 'd': if (y < SIZE - 1) y++; break;
        }

        // Atualiza a posição da peça
        board[x][y] = 'P';

    } while (move != 'Q' && move != 'q');

    printf("Programa encerrado.\n");
    return 0;
}
