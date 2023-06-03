#include <stdio.h>

enum ficha {Clinica, Pratica, Diagnostica};

void navega_avaliacao();
void resultados_clinica();
void resultados_pratica();
void resultados_diagnostica();

void navega_avaliacao() {
    int escolha;
    printf("\nESCOLHA A FICHA AVALIATIVA: [0] -> [Clinica] [1] -> [Pratica] [2] -> [Diagnostica]\n");
    scanf("%d", &escolha);

    switch (escolha) {
        case Clinica:
            resultados_clinica();
            break;
        case Pratica:
            resultados_pratica();
            break;
        case Diagnostica:
            resultados_diagnostica();
            break;
        default:
            break;
    }
}

void resultados_clinica() {
    FILE *fptr;
    char caractere;

    fptr = fopen("clinica.txt", "r");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while ((caractere = fgetc(fptr)) != EOF) {
        printf("%c", caractere);
    }

    fclose(fptr);
}

void resultados_pratica() {
    FILE *fptr;
    char caractere;

    fptr = fopen("pratica.txt", "r");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while ((caractere = fgetc(fptr)) != EOF) {
        printf("%c", caractere);
    }

    fclose(fptr);
}

void resultados_diagnostica() {
    FILE *fptr;
    char caractere;

    fptr = fopen("diagnostica.txt", "r");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while ((caractere = fgetc(fptr)) != EOF) {
        printf("%c", caractere);
    }

    fclose(fptr);
}
