/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Biblioteca personalizada         *
* Data - 14/05/2026                                      * 
* Autor: Arthur Vinicius Ribeiro Cuter                   *
*--------------------------------------------------------*/
#include "interface.h"
#include "recursao.h"

int main () {
    int escolha;

    do {
        escolha = exibirMenu();
        escolhaUsuario(escolha);
    } while (escolha != 4);

    return 0;
}