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
#include "recursao.h"

// função para converter numero de decimal para binario
void decToBin(int n) {
    // caso base
    if(n == 0) {
        return;
    } 

    // divide o numero por 2, antes da pilha de exibição para ser na ordem inversa
    decToBin(n / 2);

    // exibe o resto do numero
    printf("%d", n%2);
}


int potencia(int base, int exp) {
    // todo numero com expoente 0 é igual 1 
    if (exp == 0) {
        return 1;
    }
    // caso base
    if (exp == 1) {
        return base;
    }

    // recursividade para efetuar a potencia
    return base * potencia(base, exp-1);
}

int somaDigitos(int n) {

    // para casos onde o numero inteiro é negativo
    if (n < 0) {
        // converte para negativo
        n = -n;
    }
    // caso base
    if (n == 0) {
        return 0;
    }

    // separa os digitos utilizando o resto do numero dividido por 10 e faz recursividade
    // para somar o numero todo
    return n % 10 + somaDigitos(n/10);
}