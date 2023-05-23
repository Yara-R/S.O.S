#include <stdio.h>

int resultados_clinica(){
    FILE *fptr;
    int opcao = 1;
    char caractere;

    fptr = fopen(".txt", "r");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler e imprimir cada caractere do arquivo até o final
    while ((caractere = fgetc(fptr)) != EOF) {
        printf("%c", caractere);
    }

    fclose(fptr);

    while (opcao != 0) {
        printf("\nDigite 0 para SAIR:\n");
        scanf("%d", &opcao);
        getchar();
    }
}

int resultados_pratica(){
    FILE *fptr;
    int opcao = 1;
    char caractere;

    fptr = fopen(".txt", "r");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler e imprimir cada caractere do arquivo até o final
    while ((caractere = fgetc(fptr)) != EOF) {
        printf("%c", caractere);
    }

    fclose(fptr);

    while (opcao != 0) {
        printf("\nDigite 0 para SAIR:\n");
        scanf("%d", &opcao);
        getchar();
    }
}

int resultados_diagnostica(){
    FILE *fptr;
    int opcao = 1;
    char caractere;

    fptr = fopen(".txt", "r");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler e imprimir cada caractere do arquivo até o final
    while ((caractere = fgetc(fptr)) != EOF) {
        printf("%c", caractere);
    }

    fclose(fptr);

    while (opcao != 0) {
        printf("\nDigite 0 para SAIR:\n");
        scanf("%d", &opcao);
        getchar();
    }
}