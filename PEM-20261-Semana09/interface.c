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

// funcao para exibir as escolhas para o usuario
void exibirMenu() {
    printf("Que operacao deseja fazer?\n");
    printf("1. Potenciacao\n");
    printf("2. Converter numero decimal para binario\n");
    printf("3. Somar digitos de um numero\n");
    printf("4. Sair\n");
}

// funcao para o usuario efetivamente fazer sua escolha
int escolhaUsuario() {
    int escolha;

    printf("Escolha uma das operacoes: ");
    scanf("%d", &escolha);

    return escolha;
}

// funcao usada para ler algum numero
int lerNumero() {
    int numero;
    printf("\nDigite um numero: ");
    scanf("%d", &numero);
    return numero;
}

// funcao que sera usada na potencia para ler o expoente
int lerExpoente() {
    int expoente;
    printf("\nDigite um expoente: ");
    scanf("%d", &expoente);
    return expoente;
}

// funcao para exibir resultado da potencia
void exibirResultadoPotencia(int numero, int expoente, int resultado) {
    printf("\nO resultado de %d elevado a %d e: %d\n", numero, expoente, resultado);
}

// funcao para exibir resultado da soma dos digitos
void exibirResultadoSoma(int resultado) {
    printf("\nA soma dos digitos e: %d\n", resultado);
}

// funcao para exibir o numero em binario
void exibirMensagemBinario() {
    printf("Esse numero em binario e: ");
}

// funcao para exibir mensagem de saida
void exibirMensagemSaida() {
    printf("Saindo...\n");
}

// funcao para exibir mensagem de erro (opcao invalida)
void exibirMensagemErro() {
    printf("Digite um numero valido!\n");
}

// funcao para exibir um zero
void exibirZero() {
    printf("0");
}

//funcao para pular linha;
void pularLinha() {
    printf("\n");
}