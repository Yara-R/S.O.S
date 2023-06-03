#include "avisos_preceptores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 100
#define TAM_MAX_MSG 1000

void aviso_preceptor(FILE *fptr);
void escrita_preceptor(FILE *fptr);

void manage_avisosP(char *filename) {
    FILE *fptr;
    int opcao = 1;

    fptr = fopen(filename, "a+");

    aviso_preceptor(fptr);

    while (opcao != 0) {
        printf("\nDigite 1 para ADICIONAR ou 0 para SAIR:\n");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            escrita_preceptor(fptr);
        } else if (opcao != 0 && opcao != 1) {
            printf("\nComando desconhecido!\n");
        }
    }

    fclose(fptr);
}

void aviso_preceptor(FILE *fptr) {
    if (fseek(fptr, 0, SEEK_END) == 0) {
        long tamanho = ftell(fptr);
        if (tamanho == 0) {
            printf("Nenhum aviso\n");
        } else {
            rewind(fptr);
            printf("\nAvisos:\n");
            char *linha = (char *) malloc((TAM_MAX_NOME + TAM_MAX_MSG + 4) * sizeof(char));
            while (fgets(linha, TAM_MAX_NOME + TAM_MAX_MSG + 4, fptr) != NULL) {
                printf("\n%s", linha);
            }
            free(linha);
        }
    }
}

void escrita_preceptor(FILE *fptr) {

    char *nome = (char *) malloc(TAM_MAX_NOME * sizeof(char));
    char *msg = (char *) malloc(TAM_MAX_MSG * sizeof(char));

    printf("\nDigite o nome do autor:\n");
    fgets(nome, TAM_MAX_NOME, stdin);

    printf("\nDigite a mensagem:\n");
    fgets(msg, TAM_MAX_MSG, stdin);

    if (strlen(msg) > 1) {
        msg[strlen(msg) - 1] = '\0';

        fseek(fptr, 0, SEEK_END);

        fprintf(fptr, "%s - %s\n", nome, msg);
        printf("\nMensagem adicionada com sucesso!\n");

        aviso_preceptor(fptr);
    }

    free(nome);
    free(msg);
}
