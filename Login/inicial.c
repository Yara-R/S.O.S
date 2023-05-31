#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int tipo, choice, r1, r2;
    char senha[100], senha2[100], senha3[100], cpf[12], cpf2[12], cpf3[12];
    FILE *residentes, *preceptores;

    printf("Selecione qual seu tipo de usuario:\n");
    printf("1- Residente\n2- Preceptor\n");
    scanf("%d", &tipo);
    
    if (tipo == 1) { // Residente
        printf("Bem vindo a pagina de residente!\n");
        printf("CPF: ");
        scanf("%s", cpf);
        printf("Senha: ");
        scanf("%s", senha);

        residentes = fopen("Residentes.txt", "r");

        while (fscanf(residentes, "%s %s", cpf2, senha2) == 2) {
            r1 = strcmp(cpf, cpf2);
            r2 = strcmp(senha, senha2);
        }
        // printf("%d %d", r1, r2);

        if (r1 == 0 && r2 == 0) {
            printf("\nLogin realizado com sucesso");
        } else {
            printf("\nLogin ou senha incorretos, tente novamente");
        }
        
        fclose(residentes);

    }else if (tipo==2){
      printf("Bem vindo a pagina de preceptores!\n");
        printf("CPF: ");
        scanf("%s", cpf);
        printf("Senha: ");
        scanf("%s", senha);

        preceptores = fopen("Preceptores.txt", "r");

        while (fscanf(residentes, "%s %s", cpf2, senha2) == 2) {
            r1 = strcmp(cpf, cpf2);
            r2 = strcmp(senha, senha2);
        }
        printf("%d %d", r1, r2);

        if (r1 == 0 && r2 == 0) {
            printf("\nLogin realizado com sucesso");
        } else {
            printf("\nLogin ou senha incorretos, tente novamente");
        }
        
        fclose(preceptores);
      
    }else{
        printf("Bem vindo a pagina de preceptores!\n");
        printf("Você deseja cadastrar um aluno ou um residente?\n");
        scanf("%d", choice);

        if(choice==1){
            printf("Digite o CPF do aluno:\n");
            scanf("%s", cpf3);
            printf("Digite a senha do aluno:\n");
            scanf("%s", senha3);
            residentes = fopen("residentes.txt", "a");
            fputs(cpf3, residentes);
            fputs(senha3, residentes);
            

        }else{
            printf("Digite o CPF do preceptor:\n");
            scanf("%s", cpf3);
            printf("Digite a senha do preceptor:\n");
            scanf("%s", senha3);
            preceptores = fopen("preceptores.txt", "a");
            fputs(cpf3, preceptores);
            fputs(senha3, preceptores);
        }
       
    }

    return 0;
}