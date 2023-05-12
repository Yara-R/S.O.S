#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 100
#define TAM_MAX_MSG 1000

int main() {
    FILE *fptr;
    int opcao = 1;

    fptr = fopen("avisos.txt", "a+");

    // Verifica se o arquivo está vazio
    if (fseek(fptr, 0, SEEK_END) == 0) {
        long tamanho = ftell(fptr);
        if (tamanho == 0) {
            printf("Nenhum aviso\n");
        }
        else {
            rewind(fptr);
            // Lê o nome do autor e a mensagem do arquivo
            printf("\nAvisos:\n");
            char* linha = (char*) malloc((TAM_MAX_NOME + TAM_MAX_MSG + 4) * sizeof(char));
            while (fgets(linha, TAM_MAX_NOME + TAM_MAX_MSG + 4, fptr) != NULL) {
                printf("\n%s", linha);
            }
            free(linha);
        }
    }
    
    while (opcao != 0) {
        printf("\nDigite 0 para SAIR:\n");
        scanf("%d", &opcao);
        getchar();
    }

    fclose(fptr);
    return 0;
}
