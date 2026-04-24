/*----------------------------------------------------------*
*                      FATEC Ipiranga                       *
* Disciplina: Programaçao Estruturada e Modular             *
*          Prof. Veríssimo                                  *
*-----------------------------------------------------------*
* Objetivo do Programa: Busca em profundidade(Recursividade)*
* Data - 24/04/2026                                         * 
* Autor: Arthur Vinicius                                    *
*----------------------------------------------------------*/
// Adaptação trocando recursividade por iteratividade 
#include <stdio.h>
#include <string.h>

#define MAX_PASTAS 50
#define LIMITE_ALERTA 300.0

typedef struct {
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int subpastas_indices[10];
    int qtd_sub;
} Pasta;

// cria-se uma nova struct para guardar o indice da pasta e o nivel
typedef struct {
    int index;
    int nivel;
} ItemPilha;

Pasta drive[MAX_PASTAS];

void processarHierarquiaIterativa(int inicio_idx, int limite_profundidade) {
    if (inicio_idx == -1) {
        return;
    }
    // pilha agora manual
    ItemPilha pilha[MAX_PASTAS];
    int topo = -1;

    // empilha o nó raiz
    pilha[++topo] = (ItemPilha){inicio_idx, 0};

    // utiliza um laço while que, enquanto o topo for maior ou igual a 0, executa os comandos
    while (topo >= 0) {
        // no inicio, desempilhamos o nó que estamos
        ItemPilha atual = pilha[topo--];

        // utiliza o struct novo criado como indice 
        int idx = atual.index;
        int nivel = atual.nivel;

        // se o nivel for maior que o limite, ele pula o restante da repetição atual
        if (nivel > limite_profundidade) {
            continue;
        }


        drive[idx].tamanho_total = drive[idx].tamanho_proprio; 

        for (int i = 0; i < nivel; i++) {
            printf("  ");
        }

        printf("|-- %s [%.2f GB]", drive[idx].nome, drive[idx].tamanho_proprio);
        
        if (drive[idx].tamanho_proprio > LIMITE_ALERTA) {
            printf(" [!] ALERTA: GARGALO DETECTADO");
        }
        printf("\n");

        // agora empilha as subpastas
        for (int i = drive[idx].qtd_sub - 1; i >= 0; i--) {
            if (topo < MAX_PASTAS - 1) {
                pilha[++topo] = (ItemPilha){drive[idx].subpastas_indices[i], nivel + 1};
            }
        }
    }
}

int main() {
    strcpy(drive[0].nome, "RAIZ");
    drive[0].tamanho_proprio = 10.0;
    drive[0].qtd_sub = 2;
    drive[0].subpastas_indices[0] = 1; 
    drive[0].subpastas_indices[1] = 2; 

    strcpy(drive[1].nome, "Projetos_TI");
    drive[1].tamanho_proprio = 50.0;
    drive[1].qtd_sub = 1;
    drive[1].subpastas_indices[0] = 3; 

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
    processarHierarquiaIterativa(0, limite);
    printf("-------------------------------------------\n");

    return 0;
}