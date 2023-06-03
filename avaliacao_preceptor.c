#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 100
#define TAM_MAX_MSG 1000

enum ficha {Clinica, Pratica, Diagnostica};

void escolha_ficha();
void preencher_ficha_clinica();
void preencher_ficha_pratica();
void preencher_ficha_diagnostica();

void escolha_ficha() {
    int opcao = 1;
    enum ficha escolha;

    printf("\nESCOLHA A FICHA AVALIATIVA [Clinica] [Pratica] [Diagnostica]\n");
    scanf("%d", &escolha);

    switch (escolha) {
        case Clinica:
            preencher_ficha_clinica();
            break;
        case Pratica:
            preencher_ficha_pratica();
            break;
        case Diagnostica:
            preencher_ficha_diagnostica();
            break;
        default:
            break;
    }

    while (opcao != 0) {
        printf("\nDigite 0 para SAIR:\n");
        scanf("%d", &opcao);
        getchar();
    }
}

void preencher_ficha_clinica() {
    char *nome = (char *) malloc(TAM_MAX_NOME * sizeof(char));
    char *msg = (char *) malloc(TAM_MAX_MSG * sizeof(char));
    FILE *fptr;

    fptr = fopen("clinica.txt", "a+");

    printf("\nDigite o nome do autor:\n");
    fgets(nome, TAM_MAX_NOME, stdin);

    printf("\nEscreva as Questões da ficha: \n");
    fgets(msg, TAM_MAX_MSG, stdin);

    if (strlen(msg) > 1) {
        msg[strlen(msg) - 1] = '\0';

        fseek(fptr, 0, SEEK_END);

        fprintf(fptr, "%s - %s\n", nome, msg);
        printf("\nQuestoes adicionadas com sucesso! \n");
    }

    fclose(fptr);
    free(nome);
    free(msg);
}

void preencher_ficha_pratica() {
    char *nome = (char *) malloc(TAM_MAX_NOME * sizeof(char));
    char *msg = (char *) malloc(TAM_MAX_MSG * sizeof(char));
    FILE *fptr;

    fptr = fopen("pratica.txt", "a+");

    printf("\nDigite o nome do autor:\n");
    fgets(nome, TAM_MAX_NOME, stdin);

    printf("\nEscreva as questoes da ficha:\n");
    fgets(msg, TAM_MAX_MSG, stdin);

    if (strlen(msg) > 1) {
        msg[strlen(msg) - 1] = '\0';

        fseek(fptr, 0, SEEK_END);

        fprintf(fptr, "%s - %s\n", nome, msg);
        printf("\nQuestoes adicionadas com sucesso! \n");
    }

    fclose(fptr);
    free(nome);
    free(msg);
}

void preencher_ficha_diagnostica() {
    char *nome = (char *) malloc(TAM_MAX_NOME * sizeof(char));
    char *msg = (char *) malloc(TAM_MAX_MSG * sizeof(char));
    FILE *fptr;

    fptr = fopen("diagnostica.txt", "a+");

    printf("\nDigite o nome do autor: \n");
    fgets(nome, TAM_MAX_NOME, stdin);

    printf("\nEscreva as questoes da ficha: \n");
    fgets(msg, TAM_MAX_MSG, stdin);

    if (strlen(msg) > 1) {
        msg[strlen(msg) - 1] = '\0';

        fseek(fptr, 0, SEEK_END);

        fprintf(fptr, "%s - %s\n", nome, msg);
        printf("\nMQuestoes adicionadas com sucesso!\n");
    }

    fclose(fptr);
    free(nome);
    free(msg);
}
