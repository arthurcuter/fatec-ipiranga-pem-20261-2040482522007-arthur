/*----------------------------------------------------------*
*                      FATEC Ipiranga                       *
* Disciplina: Programaçao Estruturada e Modular             *
*          Prof. Veríssimo                                  *
*-----------------------------------------------------------*
* Objetivo do Programa: Busca em profundidade(Recursividade)*
* Data - 24/04/2026                                         * 
* Autor: Arthur Vinicius                                    *
*----------------------------------------------------------*/
// Adaptacao com ponteiros
#include <stdio.h>
#include <string.h>

#define MAX_PASTAS 50
#define LIMITE_ALERTA 300.0

typedef struct Pasta { // adicionado "Pasta" para conseguirmos referenciar ela dentro de si mesma
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    struct Pasta *subpastas[10]; // utilização de ponteiros (otimização)
    int qtd_sub;
} Pasta;

Pasta drive[MAX_PASTAS];

// agora recebe um ponteiro que indica direto a pasta (otimização)
float processarHierarquia(Pasta *pasta_atual, int nivel_atual, int limite_profundidade) {
    if (pasta_atual == NULL || nivel_atual > limite_profundidade) {
        return 0;
    }

    // Necessario trocar todos os "." por ->, devido ao uso de ponteiro
    pasta_atual->tamanho_total = pasta_atual->tamanho_proprio;

    for (int i = 0; i < pasta_atual -> qtd_sub; i++) {
        Pasta *filho_ptr = pasta_atual -> subpastas[i];
        pasta_atual -> tamanho_total += processarHierarquia(filho_ptr, nivel_atual + 1, limite_profundidade);
    }

    for (int i = 0; i < nivel_atual; i++) printf("  ");
    
    printf("|-- %s [%.2f GB]", pasta_atual -> nome, pasta_atual -> tamanho_total);
    
    if (pasta_atual -> tamanho_total > LIMITE_ALERTA) {
        printf(" [!] ALERTA: GARGALO DETECTADO");
    }
    printf("\n");

    return pasta_atual -> tamanho_total;
}

int main() {

    // Agora se utiliza & para referenciar o endereço de memoria

    strcpy(drive[0].nome, "RAIZ");
    drive[0].tamanho_proprio = 10.0;
    drive[0].qtd_sub = 2;
    drive[0].subpastas[0] = &drive[1];
    drive[0].subpastas[1] = &drive[2];

    strcpy(drive[1].nome, "Projetos_TI");
    drive[1].tamanho_proprio = 50.0;
    drive[1].qtd_sub = 1;
    drive[1].subpastas[0] = &drive[3];

    strcpy(drive[2].nome, "Backups_Antigos");
    drive[2].tamanho_proprio = 350.0; 
    drive[2].qtd_sub = 0;

    strcpy(drive[3].nome, "Videos_Aulas");
    drive[3].tamanho_proprio = 280.0;
    drive[3].qtd_sub = 0;

    int limite;
    printf("Defina o limite de profundidade do mergulho: ");
    scanf("%d", &limite);

    printf("\n--- RELATORIO DE HIERARQUIA INTELIGENTE ---\n");
    processarHierarquia(&drive[0], 0, limite);
    printf("-------------------------------------------\n");

    return 0;
}