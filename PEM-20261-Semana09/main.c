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
    int numero;
    int expoente;
    int resultado;

    do {
        exibirMenu();
        escolha = escolhaUsuario();
        switch (escolha) {
            case 1:
                numero = lerNumero();
                expoente = lerExpoente();
                resultado = potencia(numero, expoente);
                exibirResultadoPotencia(numero, expoente, resultado);
                break;
            case 2:
                numero = lerNumero();
                exibirMensagemBinario();
                if(numero == 0) {
                    exibirZero();
                } else {
                    decToBin(numero);
                }
                pularLinha();
                break;
            case 3:
                numero = lerNumero();
                resultado = somaDigitos(numero);
                exibirResultadoSoma(resultado);
                break;
            case 4:
                exibirMensagemSaida();
                break;
            default:
                exibirMensagemErro();
                break;
        }
    } while (escolha != 4);

    return 0;
}