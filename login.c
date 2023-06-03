#include <stdio.h>
#include <string.h>
#include "login.h"
#include "avisos_residentes.h"
#include "avisos_preceptores.h"
#include "avaliacao_residente.h"
#include "avaliacao_preceptor.h"
#include "presenca.h"

void login_residente();
void login_preceptor();
int check_credentials(char *filename, char *cpf, char *password);

void login_app()
{
    int tipo;

    printf("Selecione qual seu tipo de usuario:\n");
    printf("[1] para Residente\n[2] para Preceptor\n");
    scanf("%d", &tipo);

    switch (tipo)
    {
        case 1:
            login_residente();
            int escolha;
            printf("Escolha uma opcao: \n [1] para quadro de avisos, [2] para avaliacoes e [3] para frequencia: ");
            scanf("%d", &escolha);
            switch (escolha) {
                case 1:
                    aviso_residente();
                    break;
                case 2:
                    navega_avaliacao();
                    break;
                case 3:
                    registrar_frequencia();
                    break;
                default:
                    printf("Opcao Invalida\n");
            }

            break;
        case 2:
            login_preceptor();
            int escolha_2;
            printf("Escolha uma opcao: \n [1] para quadro de avisos, [2] para avaliacoes e [3] para frequencia: ");
            scanf("%d", &escolha_2);
            switch (escolha_2) {
                case 1:
                    manage_avisosP("avisos.txt");
                    break;
                case 2:
                    escolha_ficha();
                    break;
                case 3:
                    registrar_frequencia();
                    break;

                default:
                    printf("Opcao Invalida\n");
            }


            break;
        default:
            printf("Opção Inválida\n");
            break;
    }
}

void login_residente() {
    char cpf[12];
    char senha[9];

    printf("\nDigite o cpf do residente: ");
    scanf("%s", cpf);

    printf("Digite a senha: ");
    scanf("%s", senha);

    if (check_credentials("residente.txt", cpf, senha)) {
        printf("Login residente bem-sucedido!\n");
    } else {
        printf("CPF ou senha invalidos!\n");
        return login_residente();
    }
}

void login_preceptor() {
    char cpf[12];
    char senha[9];

    printf("\nDigite o cpf do preceptor: ");
    scanf("%s", cpf);
    printf("Digite a senha: ");
    scanf("%s", senha);

    if (check_credentials("preceptor.txt", cpf, senha)) {
        printf("Login preceptor bem-sucedido!\n");
    } else {
        printf("CPF ou senha invalidos!\n");
        return login_preceptor();
    }
}

int check_credentials(char *filename, char *cpf, char *password) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 0;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char cpf_in_file[12];
        char password_in_file[9];

        sscanf(line, "%s %s", cpf_in_file, password_in_file);

        if (strcmp(cpf, cpf_in_file) == 0 && strcmp(password, password_in_file) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}
