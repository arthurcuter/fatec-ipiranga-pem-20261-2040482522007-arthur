// Arthur Vinícius Ribeiro Cuter
// RA: 2040482522007
#include <stdio.h>
int main() {

    int idProdutos[10], opcao, id, vazio = -1, i, encontrado = -1;
    for (i = 0; i < 10; i++) {
        idProdutos[i] = -1;
    }

    do {
        printf("\n\nEscolha uma das opcoes:\n");
        printf("1. Incluir ID\n");
        printf("2. Consultar ID\n");
        printf("3. Alterar ID\n");
        printf("4. Excluir ID\n");
        printf("5. Listar todos os IDs\n");
        printf("6. Encerrar\n");
        printf("Digite: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            vazio = -1;
            printf("Digite o ID que deseja incluir: ");
            scanf("%d", &id);
            for (i = 0; i < 10; i++) {
                if (idProdutos[i] == -1)
                {
                    vazio = i;
                    break;
                }
            }
            if (vazio == -1) {
                printf("Ja possui produtos demais (10)");
            } else {
                idProdutos[vazio] = id;
                printf("ID ARMAZENADO COM SUCESSO!");
            }
            break;
        case 2:
            encontrado = -1;
            printf("Digite o ID que deseja consultar: ");
            scanf("%d", &id);
            for (i = 0; i < 10; i++) {
                if (id == idProdutos[i])
                {
                    encontrado = i;
                    break;
                }
            }
            if (encontrado == -1) {
                printf("ID nao encontrado");
            }
            else {
                printf("ID %d encontrado na posicao %d", id, encontrado);
            }
            break;
        case 3:
            encontrado = -1;
            printf("Digite o ID que deseja alterar: ");
            scanf("%d", &id);
            for (i = 0; i < 10; i++) {
                if (id == idProdutos[i])
                {
                    encontrado = i;
                    break;
                }
            }
            if (encontrado == -1) {
                printf("ID nao encontrado");
            }
            else {
                int idNovo;
                printf("Digite o novo ID: ");
                scanf("%d", &idNovo);
                idProdutos[encontrado] = idNovo;
                printf("ID %d alterado para %d com sucesso!", id, idNovo);
            }
            break;
        case 4:
            encontrado = -1;
            printf("Digite o ID que deseja excluir: ");
            scanf("%d", &id);
            for (i = 0; i < 10; i++) {
                if (id == idProdutos[i])
                {
                    encontrado = i;
                    break;
                }
            }
            if (encontrado == -1) {
                printf("ID nao encontrado");
            }
            else {
                idProdutos[encontrado] = -1;
                printf("ID %d excluido com sucesso!", id);
            }
            break;
        case 5:
            printf("IDs cadastrados: ");
            for (i = 0; i < 10; i++) {
                if(idProdutos[i] != -1) {
                    printf("%d, ", idProdutos[i]);
                }
            }
            break;
        case 6:
            printf("Programa encerrado");
            break;
        default:
            printf("Digite uma opcao valida");
        }
    } while (opcao != 6);
    return 0;
}