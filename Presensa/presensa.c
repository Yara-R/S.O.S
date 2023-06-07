#include <stdio.h>
#include <time.h>

int main() {
    FILE *arquivo;
    enum Acao { ENTRADA, SAIDA };
    enum Acao acaoSelecionada;

    printf("Registrar: (0) entrada; (1) saida\n");
    scanf("%d", (int *)&acaoSelecionada);

    arquivo = fopen("frequencia_Maria_Clara_Castro.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    time_t agora = time(NULL);
    struct tm *infoTempo = localtime(&agora);

    char dataHora[20];
    strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", infoTempo);

    switch (acaoSelecionada) {
        case ENTRADA:
            printf("Registrar entrada em %s? (S/N): ", dataHora);
            break;
        case SAIDA:
            printf("Registrar saida em %s? (S/N): ", dataHora);
            break;
        default:
            printf("Acao invalida!\n");
            fclose(arquivo);
            return 1;
    }

    char confirmacao;
    scanf(" %c", &confirmacao);

    if (confirmacao == 'S' || confirmacao == 's') {
        switch (acaoSelecionada) {
            case ENTRADA:
                fprintf(arquivo, "Entrada: %s\n", dataHora);
                fprintf(arquivo, "Latitude = -21° 09' 43.82'' S;\nLongitude = -47° 51' 11.04'' W\n\n");
                printf("Registro de entrada efetuado com sucesso.\n");
                break;
            case SAIDA:
                fprintf(arquivo, "Saida: %s\n", dataHora);
                fprintf(arquivo, "Latitude = -21° 09' 43.82'' S;\nLongitude = -47° 51' 11.04'' W\n\n");
                printf("Registro de saida efetuado com sucesso.\n");
                break;
        }
    } else {
        printf("Acao nao confirmada. Registro cancelado.\n");
    }

    fclose(arquivo);
    return 0;
}
