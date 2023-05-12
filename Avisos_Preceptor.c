#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 100
#define TAM_MAX_MSG 1000

int main() {
    char nome[TAM_MAX_NOME], msg[TAM_MAX_MSG];
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
            char linha[TAM_MAX_NOME + TAM_MAX_MSG + 4];
                while (fgets(linha, sizeof(linha), fptr) != NULL) {
                    printf("%s", linha);
                }
        }
    }
    
    while (opcao != 0) {
        printf("Digite 1 para ADICIONAR ou 0 para SAIR:\n");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        if (opcao == 1) {
            printf("Digite o nome do autor:\n");
            fgets(nome, TAM_MAX_NOME, stdin);

            printf("Digite a mensagem:\n");
            fgets(msg, TAM_MAX_MSG, stdin);

            if (strlen(msg) > 1) {
                msg[strlen(msg) - 1] = '\0';

                // Move o ponteiro de arquivo para o final do arquivo
                fseek(fptr, 0, SEEK_END);

                // Escreve a mensagem no final do arquivo
                fprintf(fptr, "%s - %s\n", nome, msg);
                printf("Mensagem adicionada com sucesso!\n");

                // lê todo o conteúdo do arquivo e imprime na tela
                rewind(fptr);
                char linha[TAM_MAX_NOME + TAM_MAX_MSG + 4];
                while (fgets(linha, sizeof(linha), fptr) != NULL) {
                    printf("%s", linha);
                }
            }
        }
        else{
                printf("Comando desconhecido!\n");
        }
    }    

    fclose(fptr);
    return 0;
}
