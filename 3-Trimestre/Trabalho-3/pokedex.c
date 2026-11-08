#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void start(){
    int opcao;
    printf("-----------------------\n");
    printf("\tPokedex\n");
    printf("-----------------------\n");
    printf("Qual operacao deseja realizar?\n1 - Cadastrar Pokemon\n2 - Listar Pokemons\n3 - Ver Pokemon\n4 - Sair\n");
    scanf("%d", &opcao);
    printf("\n");

    return opcao;
}

int main(){
    FILE * file;
    int opcao = 0;

    char nomeP[30], tipoP[50];
    int numP;

    do{
        opcao = start();

        // Cadastro
        if(opcao == 1){
            printf("Informe:\nNome: ");
            scanf("%s", nomeP);
            printf("Numero: ");
            scanf("%d", &numP);
            printf("Tipagem: ");
            scanf("%s", tipoP);

            file = fopen("ListaPokemons.txt","a");
            fprintf(file, "%s\n", nomeP);
            fclose(file);

            char arq[30] = strdup(nomeP);
            strcat(arq, ".txt");
            file = fopen(arq, "w");
            fprintf("\n%s\n%04d\n%s\n", nomeP, numP, tipoP);
            fclose(file);
        }
    }while(opcao < 4);

    return 0;
}