#include <stdio.h>
#include <string.h>

int main() {
    char nome[50];
    char local[50];
    char periodo[50];
    float notaGeral;
    float notaAspecto1, notaAspecto2, notaAspecto3;
    char observacoes[100];
    FILE *file;

    printf("Digite o nome da pessoa: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite o local: ");
    fgets(local, sizeof(local), stdin);

    printf("Digite o período: ");
    fgets(periodo, sizeof(periodo), stdin);

    printf("Avaliação do Aspecto 1 (0-10): ");
    scanf("%f", &notaAspecto1);

    printf("Avaliação do Aspecto 2 (0-10): ");
    scanf("%f", &notaAspecto2);

    printf("Avaliação do Aspecto 3 (0-10): ");
    scanf("%f", &notaAspecto3);

    printf("Observações: ");
    getchar(); 
    fgets(observacoes, sizeof(observacoes), stdin);

    notaGeral = (notaAspecto1 + notaAspecto2 + notaAspecto3) / 3.0;

    file = fopen("avaliação.txt", "a");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    } else {
        fputs("Nome: ", file);
        fputs(nome, file);
        fputs("Local: ", file);
        fputs(local, file);
        fputs("Período: ", file);
        fputs(periodo, file);

        fprintf(file, "Nota Geral: %.2f\n", notaGeral);
        fprintf(file, "Nota Aspecto 1: %.2f\n", notaAspecto1);
        fprintf(file, "Nota Aspecto 2: %.2f\n", notaAspecto2);
        fprintf(file, "Nota Aspecto 3: %.2f\n", notaAspecto3);

        fputs("Observações: ", file);
        fputs(observacoes, file);
        fputs("\n", file);

        fclose(file); 
    }

    printf("\n");
    printf("Nome: %s", nome);
    printf("Local: %s", local);
    printf("Período: %s", periodo);
    printf("Nota Geral: %.2f\n", notaGeral);
    printf("Nota Aspecto 1: %.2f\n", notaAspecto1);
    printf("Nota Aspecto 2: %.2f\n", notaAspecto2);
    printf("Nota Aspecto 3: %.2f\n", notaAspecto3);
    printf("Observações: %s", observacoes);

    return 0;
}
