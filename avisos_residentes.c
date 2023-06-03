#include "avisos_residentes.h"
#include <stdio.h>
#include <stdlib.h>


#define TAM_MAX_NOME 100
#define TAM_MAX_MSG 1000

void aviso_residente() {
    FILE *fptr;
    fptr = fopen("avisos.txt", "a+");
    int opcao = 1;

    if (fseek(fptr, 0, SEEK_END) == 0) {
        long tamanho = ftell(fptr);
        if (tamanho == 0) {
            printf("Nenhum aviso\n");
        } else {
            rewind(fptr);
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
}
