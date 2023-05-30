#include <stdio.h>

int main(){
    int opcao = 1;
    enum ficha {Clinica, Pratica, Diagnostica} escolha;

    printf("\nESCOLHA A FICHA AVALIATIVA\n");
    scanf("%d", escolha);
    

    switch (escolha)
    {
    case 0:
        return resultados_clinica();
        break;
    
    case 1:
        return resultados_pratica();
        break;

    case 2:
        return resultados_diagnostica();
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