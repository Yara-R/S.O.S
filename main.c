#include <stdio.h>
#include "login.h"
#include "avisos_residentes.h"


int main()
{
    printf("************ Bem Vindo ************\n");
    printf("************ Voce esta no CareTrack ************\n");
    while(1) {
        int for_case;
        login_app();
        printf("\npara sair do programa digite [0], para continuar [9]\n");
        scanf("%d", &for_case);
        switch (for_case) {
            case 0:
                return 0;
            default:
                continue;
        }
    }

    //aviso_residente();


    return 0;

}
