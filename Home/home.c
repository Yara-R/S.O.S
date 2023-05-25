#include <stdio.h>

void Quadro_de_Avisos() {
    printf("Executando a Função 1\n");
    printf("Pressione qualquer tecla para voltar ao menu principal...\n");
    getchar(); // limpa o buffer do teclado
    getchar(); // espera a entrada do usuário
    
}

void Controle_de_Chamada() {
    printf("Executando a Função 2\n");
    printf("Pressione qualquer tecla para voltar ao menu principal...\n");
    getchar(); // limpa o buffer do teclado
    getchar(); // espera a entrada do usuário
}

void Provas() {
    printf("Executando a Função 3\n");
    printf("Pressione qualquer tecla para voltar ao menu principal...\n");
    getchar(); // limpa o buffer do teclado
    getchar(); // espera a entrada do usuário
}

void Ajustes() {
    printf("Executando a Função 4\n");
    printf("Pressione qualquer tecla para voltar ao menu principal...\n");
    getchar(); // limpa o buffer do teclado
    getchar(); // espera a entrada do usuário
}

int main() {
    int opcao;
    do {
        printf("Digite um número de 1 a 3 para escolher uma opção:\n");
        printf("1 - Quadro de Avisos\n");
        printf("2 - Controle de Chamada\n");
        printf("3 - Provas\n");
        printf("4 - Ajustes\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                Quadro_de_Avisos();
                break;
            case 2:
                Controle_de_Chamada();
                break;
            case 3:
                Provas();
                break;
            case 4:
                Ajustes();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção Inválida\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
