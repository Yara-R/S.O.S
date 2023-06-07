#include <stdio.h>

void resultados_clinica();
void resultados_pratica();
void resultados_diagnostica();

int main() {
    int opcao = 1;
    enum ficha {Clinica, Pratica, Diagnostica}; 
    enum ficha escolha;

    printf("\nESCOLHA A FICHA AVALIATIVA\n");
    scanf("%d", (int *)&escolha);

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
            printf("Opção inválida.\n");
            break;
    }

    while (opcao != 0) {
        printf("\nDigite 0 para SAIR:\n");
        scanf("%d", &opcao);
        getchar();
    }

    return 0;
}

void resultados_clinica() {
    FILE *fptr;
    int opcao = 1;
    char caractere;

    fptr = fopen("avaliação.txt", "r");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
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

void resultados_pratica() {
    FILE *fptr;
    int opcao = 1;
    char caractere;

    fptr = fopen("avaliacao.txt", "r");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
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

void resultados_diagnostica() {
    FILE *fptr;
    int opcao = 1;
    char caractere;

    fptr = fopen("avaliacao.txt", "r");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
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
