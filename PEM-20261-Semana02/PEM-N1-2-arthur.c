// Arthur Vinícius Ribeiro Cuter
// RA: 2040482522007
#include <stdio.h>
#include <string.h>

int main () {

    char frase[100];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    int tamanhoFrase = strlen(frase);
    int i;
    int contadorPalavras = 1;

    for(i = 0; i < tamanhoFrase; i++) {
        if(frase[i] == ' ') {
            if(frase[i + 1] != ' ') {
                contadorPalavras = contadorPalavras + 1;
            }
        }
    }

    printf("Sua frase tem %d palavaras", contadorPalavras);
    
    return 0;
}