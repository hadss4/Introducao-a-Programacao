#include <stdio.h>
#include <stdlib.h>

start(){
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

    char nomeP[20], tipoP[50];
    int numP;

    do{
        opcao = start();

        // Cadastro
        if(opcao == 1){
            printf("Informe:\nNome: ");
            scanf("%s", nomeP);
        }
    }while(opcao < 4)

    return 0;
}