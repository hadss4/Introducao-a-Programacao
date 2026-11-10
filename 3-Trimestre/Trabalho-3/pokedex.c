#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * file;
char nomeP[30], tipoP[50], arq[40];
int numP;
int cadastros = 1;

void init(){
    file = fopen("ListaPokemons.txt","a");
            fprintf(file, "Quagsire\n");
            fclose(file);

            file = fopen("Quagsire.txt", "w");
            fprintf(file, "Quagsire\n0195\nAgua/Terrestre\n");
            fclose(file);
}

int start(){
    int opcao;
    printf("-----------------------\n");
    printf("\tPokedex\n");
    printf("-----------------------\n");
    printf("Qual operacao deseja realizar?\n1 - Cadastrar Pokemon\n2 - Listar Pokemons\n3 - Ver Pokemon\n4 - Sair\n\n");
    scanf("%d", &opcao);
    printf("\n");

    return opcao;
}

void cadastro(){
    printf("Informe:\nNome: ");
            scanf("%s", nomeP);
            printf("Numero: ");
            scanf("%d", &numP);
            printf("Tipagem: ");
            scanf("%s", tipoP);

            file = fopen("ListaPokemons.txt","a");
            fprintf(file, "%s\n", nomeP);
            fclose(file);

            strcpy(arq, nomeP);
            strcat(arq, ".txt");
            file = fopen(arq, "w");
            fprintf(file, "%s\n%04d\n%s\n", nomeP, numP, tipoP);
            fclose(file);

            cadastros++;
}

void listar(){
    printf("---Pokemons cadastrados---\n\n");

    file = fopen("ListaPokemons.txt", "r");

    int cont = 0;
    while(!feof(file)){
        fscanf(file, "%s", nomeP);
        if (cont < cadastros){
            printf("- %s\n", nomeP);

            cont++;
        }else{
            fclose(file);
            break;
        }
    }
}

void dados(){
    printf("Por qual pokemon procura?\n");
    scanf("%s", nomeP);

    strcpy(arq, nomeP);
    strcat(arq, ".txt");

    file = fopen(arq, "r");

        fscanf(file, "%s", nomeP);
        printf("\n\n- %s\n", nomeP);
        fscanf(file, "%d", &numP);
        printf("#%04d\n", numP);
        fscanf(file, "%s", tipoP);
        printf("Tipo: %s\n", tipoP);

    fclose(file);
}

void end(){
    printf("Encerrando programa...\n");
}

int main(){
    init();

    int opcao = 0;

    do{
        opcao = start();

        if(opcao == 1){
            cadastro();

            printf("\n");
        }else if (opcao == 2){
            listar();

            printf("\n");
        }else if (opcao == 3){
            dados();

            printf("\n");
        }else {
            end();
        }
    }while(opcao < 4);

    return 0;
}
