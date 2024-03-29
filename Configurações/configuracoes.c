#include <stdio.h>

int main() {
    enum EscolhaConfig {ACESSIBILIDADE, AJUDA, COORDENACAO, LOGOUT};
    enum EscolhaConfig config;

    printf("CONFIGURAÇÕES:\n(0) ACESSIBILIDADE\n(1) AJUDA\n(2) COORDENAÇÃO\n(3) LOGOUT\n");
    scanf("%d", (int *)&config);

    switch (config) {
        case ACESSIBILIDADE:
            printf("\nAJUSTE DE FONTE\nAJUSTE DE CONTRASTE\nATIVAR INNTERPRETE\nCONFIGURARAR FERRAMENTA AUXILIADORA EXTERNA\nVOLTAR\n");
            break;

        case AJUDA: {
            FILE *faqFile = fopen("faq.txt", "r");
            if (faqFile == NULL) {
                printf("Erro ao abrir AJUDA\n");
                return 1;
            }

            char c;
            while ((c = fgetc(faqFile)) != EOF) {
                printf("%c", c);
            }

            fclose(faqFile);
            break;
        }

        case COORDENACAO: {
            char autor[100];
            char mensagem[100];
            printf("Digite o autor: ");
            scanf(" %[^\n]", autor);
            printf("Digite a mensagem: ");
            scanf(" %[^\n]", mensagem);

            FILE *mensagemFile = fopen("mensagem.txt", "a");
            if (mensagemFile == NULL) {
                printf("Erro ao enviar mensagem\n");
                return 1;
            }

            fprintf(mensagemFile, "Autor: %s\nMensagem: %s\n\n", autor, mensagem);

            fclose(mensagemFile);
            break;
        }

        case LOGOUT:
            /* código para logout */
            break;

        default:
            printf("Opção inválida\n");
            break;
    }

    return 0;
}
