// FATEC IPIRANGA
// Professor: Verissimo
// Nome: Arthur Vinicius Ribeiro Cuter
// RA: 2040482522007
// Curso: Analise e Desenvolvimento de Sistemas
// Programação Estruturada e Modular
// Xeque Mate Pastor em C!

// Bibliotecas que serão usadas:
#include <stdio.h>
#include <string.h>

// Diretivas:
#define LINHAS 8 // Define "Linhas" como 8
#define COLUNAS 8 // Define "Colunas"como 8

// Função para inicializar o tabuleiro
// Ela recebe o valor da matriz que criaremos na função principal
void inicializarTabuleiro(char tabuleiro[LINHAS][COLUNAS][4]) {
    
    // Preenche a matriz com os valores na posição padrão do tabuleiro
    char configInicial[LINHAS][COLUNAS][4] = {
        {"tP1", "cP2", "bP3", "dP4", "rP5", "bP6", "cP7", "tP8"},
        {"PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8"},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"PB1", "PB2", "PB3", "PB4", "PB5", "PB6", "PB7", "PB8"},
        {"TB1", "CB2", "BB3", "DB4", "RB5", "BB6", "CB7", "TB8"}
    };

    // Copia as posições para a configuração inicial do tabuleiro
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            strcpy(tabuleiro[i][j], configInicial[i][j]);
        }
    }
}

// Função que sera usada para exibir o tabuleiro na função principal
// Ela recebe a matriz que criaremos na função principal e a frase que sera exibida
void exibirTabuleiro(char tabuleiro[LINHAS][COLUNAS][4], const char* titulo) {

    // Mostra a frase na tela
    printf("\n%s\n", titulo);

    // Laço para exibir o tabuleiro
    for (int i = 0; i < LINHAS; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < COLUNAS; j++) {
            printf("%-3s ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função que sera usada para mover as peças no tabuleiro
// Ela recebe a matriz do tabuleiro, a linha e coluna de origem (que peça iremos mover) e a 
// linha e coluna de destino (para onde iremos mover)
void moverPeca(char tabuleiro[LINHAS][COLUNAS][4], int linhaOrigem, int colOrigem, int linhaDestino, int colDestino) {
    strcpy(tabuleiro[linhaDestino][colDestino], tabuleiro[linhaOrigem][colOrigem]);
    strcpy(tabuleiro[linhaOrigem][colOrigem], "...");
}

// Função principal 
int main() {
    // Criamos a variavel da matriz do tabuleiro
    char tabuleiro[LINHAS][COLUNAS][4];

    // Iniciamos o tabuleiro na matriz criada utilizando a função
    inicializarTabuleiro(tabuleiro);

    // Titulo
    printf("========================================================\n");
    printf("                Xeque Mate Pastor em C\n");
    printf("========================================================\n");

    // Primeira jogada
    printf("\n========================================================\n");
    printf("                       Jogada #1\n");
    printf("========================================================\n");
    
    // Sinaliza o que as peças brancas e pretas farão
    // e executa a jogada com a função de mover peças
    moverPeca(tabuleiro, 6, 4, 4, 4); 
    exibirTabuleiro(tabuleiro, "---------Brancas jogam e4---------");
    
    moverPeca(tabuleiro, 1, 4, 3, 4); 
    exibirTabuleiro(tabuleiro, "---------Pretas  jogam e5---------");

    // Segunda jogada
    printf("\n========================================================\n");
    printf("                       Jogada #2\n");
    printf("========================================================\n");
    
    // Sinaliza o que as peças brancas e pretas farão
    // e executa a jogada com a função de mover peças
    moverPeca(tabuleiro, 7, 5, 4, 2); 
    exibirTabuleiro(tabuleiro, "---------Brancas jogam Bc4--------");
    
    moverPeca(tabuleiro, 0, 1, 2, 2); 
    exibirTabuleiro(tabuleiro, "---------Pretas  jogam Cc6--------");

    // Terceira jogada
    printf("\n========================================================\n");
    printf("                       Jogada #3\n");
    printf("========================================================\n");
    
    // Sinaliza o que as peças brancas e pretas farão
    // e executa a jogada com a função de mover peças
    moverPeca(tabuleiro, 7, 3, 3, 7); 
    exibirTabuleiro(tabuleiro, "---------Brancas jogam Dh5--------");
    
    moverPeca(tabuleiro, 0, 6, 2, 5); 
    exibirTabuleiro(tabuleiro, "---------Pretas  jogam Cf6--------");

    // Quarta jogada e enfim xeque mate
    printf("\n========================================================\n");
    printf("                 Jogada #4 (Xeque Mate)\n");
    printf("========================================================\n");
    
    // Sinaliza o que as peças brancas e pretas farão
    // e executa a jogada com a função de mover peças, aplicando o xeque mate
    moverPeca(tabuleiro, 3, 7, 1, 5); 
    exibirTabuleiro(tabuleiro, "---Brancas capturam Peao PP6 em f7 e Xeque MATE (Dxf7#)---");

    printf("\n========================================================\n");
    printf("Fim de jogo!");

    return 0;
}