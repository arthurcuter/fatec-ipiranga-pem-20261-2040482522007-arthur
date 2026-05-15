/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Biblioteca personalizada         *
* Data - 14/05/2026                                      * 
* Autor: Arthur Vinicius Ribeiro Cuter                   *
*--------------------------------------------------------*/
#include <stdio.h>
#include "interface.h"
#include "recursao.h"

// funcao para exibir as escolhas para o usuario
int exibirMenu() {
    int escolha;
    printf("\n\nQue operacao deseja fazer?\n");
    printf("1. Potenciacao\n");
    printf("2. Converter numero decimal para binario\n");
    printf("3. Somar digitos de um numero\n");
    printf("4. Sair\n");

    printf("Escolha uma das operacoes: ");
    scanf("%d", &escolha);

    return escolha;
}

// funcao para o usuario efetivamente fazer sua escolha
void escolhaUsuario(int escolha) {
    int numero, expoente, resultado;
    switch (escolha) {
            case 1:
                printf("\nDigite a base da potencia: ");
                scanf("%d", &numero);
                printf("\nDigite o expoente da potencia: ");
                scanf("%d", &expoente);
                resultado = potencia(numero, expoente);
                printf("\nA potencia da base %d com o expoente %d eh: %d", numero, expoente, resultado);
                break;
            case 2:
                printf("\nDigite o numero que deseja converter: ");
                scanf("%d", &numero);
                if(numero == 0) {
                    printf("0 em binario eh 0");
                } else {
                    printf("O numero %d em binario eh ", numero);
                    decToBin(numero);
                }
                printf("\n");
                break;
            case 3:
                printf("\nDigite o numero que deseja somar os digitos: ");
                scanf("%d", &numero);
                resultado = somaDigitos(numero);
                printf("\nA soma dos digitos e: %d\n", resultado);
                break;
            case 4:
                printf("Saindo...");
                break;
            default:
                printf("Faça uma escolha valida! (de 1 a 4)");
                break;
    }
}

