#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 100
#define TAM_MAX_MSG 1000

int residente() {
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


int preceptor() {
    char *nome = (char *) malloc(TAM_MAX_NOME * sizeof(char));
    char *msg = (char *) malloc(TAM_MAX_MSG * sizeof(char));
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
            char *linha = (char *) malloc((TAM_MAX_NOME + TAM_MAX_MSG + 4) * sizeof(char));
            while (fgets(linha, TAM_MAX_NOME + TAM_MAX_MSG + 4, fptr) != NULL) {
                printf("\n%s", linha);
            }
            free(linha);
        }
    }
    
    while (opcao != 0) {
        printf("\nDigite 1 para ADICIONAR ou 0 para SAIR:\n");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        if (opcao == 1) {
            printf("\nDigite o nome do autor:\n");
            fgets(nome, TAM_MAX_NOME, stdin);

            printf("\nDigite a mensagem:\n");
            fgets(msg, TAM_MAX_MSG, stdin);

            if (strlen(msg) > 1) {
                msg[strlen(msg) - 1] = '\0';

                // Move o ponteiro de arquivo para o final do arquivo
                fseek(fptr, 0, SEEK_END);

                // Escreve a mensagem no final do arquivo
                fprintf(fptr, "%s - %s\n", nome, msg);
                printf("\nMensagem adicionada com sucesso!\n");

                // lê todo o conteúdo do arquivo e imprime na tela
                rewind(fptr);
                printf("\nAvisos:\n");
                char *linha = (char *) malloc((TAM_MAX_NOME + TAM_MAX_MSG + 4) * sizeof(char));
                while (fgets(linha, TAM_MAX_NOME + TAM_MAX_MSG + 4, fptr) != NULL) {
                    printf("\n%s", linha);
                }
                free(linha);
            }
        }
        else if(opcao != 0 && opcao != 1){
                printf("\nComando desconhecido!\n");
        }
    }    

    fclose(fptr);
    free(nome);
    free(msg);
    return 0;
}
