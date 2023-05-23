#include <stdio.h>
#include "residente_avaliacao.h"

int escolha_ficha(){
    int opcao = 1;
    enum ficha {Clinica, Pratica, Diagnostica} escolha;

    printf("\nESCOLHA A FICHA AVALIATIVA\n");
    scanf("%d", escolha);
    

    switch (escolha)
    {
    case 0:
        // retorna a função de preencher a ficha avaliativa
        break;
    
    case 1:
        // retorna a função de preencher a ficha avaliativa
        break;

    case 2:
        // retorna a função de preencher a ficha avaliativa
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

int escolha_residente(){
    int opcao = 1;
    enum ficha {Clinica, Pratica, Diagnostica} escolha;

    printf("\nESCOLHA A FICHA AVALIATIVA\n");
    scanf("%d", escolha);
    

    switch (escolha)
    {
    case 0:
        return resultados_clinica;
        break;
    
    case 1:
        return resultados_pratica;
        break;

    case 2:
        return resultados_diagnostica;
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