#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para inicializar o tabuleiro com zeros
void inicializarTabuleiro(int tabuleiro [TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro[i][j] = AGUA;
        } 
    }


}

// Função para verificar se o navio cabe e não sobrepõe outro navio
int podePosicionar(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + (orientacao == 1 ? i : 0);   // Vertical
        int y = coluna + (orientacao == 0 ? i : 0);  // Horizontal

        if (x >= TAM_TABULEIRO || tabuleiro[x][y] != AGUA) {
            return 0; // Nõa pode posicionar

        }

    }
    return 1; // Pode posicionar

}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int orientacao) {
     for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + (orientacao == 1 ? i : 0);   //Vertical
        int y = coluna + (orientacao == 0 ? i : 0); //Horizontal
        tabuleiro[x][y] = NAVIO;


     }

}

// Função para imprimir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])  {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%d", tabuleiro[i][j]);

    }
    printf("\n");
  }
  
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Coordenadas definidas diretamente no código
    int linhaH = 2, colunaH = 4; // Navio horizontal
    int linhaV = 5, colunaV = 7; // Navio vertical


    // Verifica e posiciona navio vertical
    if (podePosicionar(tabuleiro, linhaV, colunaV, 1)) {
        posicionarNavio(tabuleiro, linhaH, colunaH, 0);
    } else {
        printf("Erro ao posicionar navio horizontal.\n");
    }

    // Verifica e posiciona navio vertical
    if (podePosicionar(tabuleiro, linhaV, colunaV, 1)) {
        posicionarNavio(tabuleiro, linhaV, colunaV, 1);
    } else {
        printf("Erro ao posicionar navio vertical.\n");
    }

    // Exibir o tabuleiro 
    exibirTabuleiro(tabuleiro);

    return 0;

}
