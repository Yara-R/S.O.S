#include <stdio.h>

int escolha_ficha(){
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
}