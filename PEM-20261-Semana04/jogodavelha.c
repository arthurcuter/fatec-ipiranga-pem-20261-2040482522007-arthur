// Arthur Vinícius Ribeiro Cuter
// RA: 2040482522007
// Jogo da velha em C!

// bibliotecas que serão usadas: 
#include <stdio.h>
#include <stdbool.h>

// função principal
int main () {

    // Declaração de variáveis 
    char jogadorAtual, vazio = ' ';
    char  tabuleiro[3][3] = {
        {vazio, vazio, vazio},
        {vazio, vazio, vazio},
        {vazio, vazio, vazio}
    };
    bool vencedor = false;
    int i, jogadaLinha, jogadaColuna, rodada = 1;

    // Texto inicial, indicando do que se trata o programa
    printf("Jogo da velha!\n");

    // Laço principal do jogo
    // Continua o jogo enquanto não houver vencedor e a rodada for menor que 10 (tabuleiro ainda não cheio)
    while(!vencedor && rodada < 10) {
        
        // Define o jogador atual com base no numero da rodada
        // Se a rodada for par, X joga. Se for impar, O joga.
        if(rodada % 2 == 0) {
            jogadorAtual = 'X';
        } else {
            jogadorAtual = 'O';
        }

        // Mensagem para mostrar o tabuleiro atual
        printf(" Tabuleiro:\n");

        // Laço para mostrar como o tabuleiro está 
        for(i=0; i < 3; i++) {
            if (i != 2) {
                printf(" %c | %c | %c \n --+---+--\n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
            } else {
                printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
            }
        }

        // Mensagem indicando o numero da rodada e o jogador atual
        printf("Rodada %d!\nVez do jogador %c!\n", rodada, jogadorAtual);

        //Solicita ao usuario as coordenadas de sua jogada e usa scanf para ler
        printf("Diga as coordenadas de sua jogada: ");
        scanf("%d%d", &jogadaLinha, &jogadaColuna);

        // Reduz cada coordenada para se adaptar a matriz, que começa 0
        jogadaColuna -= 1;
        jogadaLinha -= 1;
    
        // Laço para verificar se a coordenada está dentro dos limites da matriz (3x3) ou 
        // se o jogador não digitou uma coordenada já ocupada
        while(jogadaLinha > 2 || jogadaLinha < 0 || jogadaColuna > 2 || jogadaColuna < 0 || tabuleiro[jogadaLinha][jogadaColuna] != vazio) {
            
            // Verifica se a coordenada está dentro dos limites
            if(jogadaLinha > 2 || jogadaLinha < 0 || jogadaColuna > 2 || jogadaColuna < 0) {

                // Apresenta uma mensagem e pede novamente as coordenadas
                printf("\nCoordenada alem dos limites (maior que 3 ou menor que 1)!");
                printf("\nDiga as coordenadas de sua jogada: ");
                scanf("%d%d", &jogadaLinha, &jogadaColuna);
                jogadaColuna -= 1;
                jogadaLinha -= 1;

            // Verifica se a coordenada já não está ocupada
            } else if(tabuleiro[jogadaLinha][jogadaColuna] != vazio) {

                // Apresenta uma mensagem e pede novamente as coordenadas
                printf("\nPosicao no tabuleiro ja ocupada!");
                printf("\nDiga as coordenadas de sua jogada: ");
                scanf("%d%d", &jogadaLinha, &jogadaColuna);
                jogadaColuna -= 1;
                jogadaLinha -= 1;
            }
        }

        // Após confirmar que é uma jogada válida, define o espaço da coordenada 
        // selecionada como o caractere do jogador atual
        tabuleiro[jogadaLinha][jogadaColuna] = jogadorAtual;

        // Verifica se há algum vencedor
        for(i = 0; i < 3; i++) {

            // Confere se há algum vencedor por fazer uma linha reta completa
            if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != vazio) {
                vencedor = true;
            }
            if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != vazio) {
                vencedor = true;
            }

        }

        // Confere se há algum vencedor por fazer alguma diagonal completa
        if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != vazio) {
            vencedor = true;
        }
        if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != vazio) {
            vencedor = true;
        }

        // Se não houver vencedor, então avança uma rodada
        rodada++;         
    }

    // Exibe a mensagem caso tenha um vencedor e o parabeniza 
    if(vencedor) {
        printf("\n%c foi o vencedor, parabens!!\n", jogadorAtual);

    // Exibe a mensagem de empate caso o tabuleiro tenha enchido
    } else {
        printf("Empate! Tabuleiro cheio!\n");
    } 

    // Exibe como o tabuleiro ficou ao final
    printf("Tabuleiro final: \n");
    for(i=0; i < 3; i++) {
        if (i != 2) {
            printf(" %c | %c | %c \n --+---+--\n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        } else {
            printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        }
    }
    
    return 0;
}