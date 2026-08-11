#include <stdio.h>
#include <stdlib.h>

#define VAZIO 0
#define NAVIO 1
#define VAZIOAT 2
#define NAVIOAT 3

void header(){
    printf("=============================\n");
    printf("\tBatalha Naval\n");
    printf("=============================\n\n");
}

int tamanho(){
    int x;
    header();
    printf("Digite o valor do tabuleiro (entre 8 e 20):\n");
    scanf("%d", &x);

    if (x < 8 || x > 20){
        printf("\nERRO: Digite um valor valido!\n");
        sleep(2);
        system("cls");
        tamanho();
    }else {
        return x;
    }
}

int qtd_navio(int tam){
    int x;
    header();
    printf("Quantos navios (entre 3 e %d)?:\n", tam*2);
    scanf("%d", &x);

    if (x < 4 || x > tam*2){
        printf("\nERRO: Digite um valor valido!\n");
        sleep(2);
        system("cls");
        qtd_navio(tam);
    }else {
        return x;
    }
}

void esconder(int tam, int nav){
    int aux = 1;
    for(int i = 0; i < tam+1; i++){
        for(int d = 0; d < tam+1; d++){
            if (i == 0){
                printf(" %-2d  ", d);
            }else{
                if(d == 0){
                    printf("%-2d",d);
                }else{
                    printf("[  ] ");
                }
            }

            aux++;
        }
        printf("\n");
    }

    int navio[nav];

    printf("\nEscolha onde esconder seus navios:\n");

    for(int i = 0; i < nav; i++){
        printf("* ");
        scanf("%d", &navio[i]);
    }
}

int main(){
    int x[2];
    int x[0] = tamanho(); // arrumar esse erro depois

    int tab1[x][x];
    int tab2[x][x];
    int ponto[2];

    x[1] = qtd_navio(x[0]);
    int nav[2];
    nav[0] = x[1];
    nav[1] = x[1];

    esconder(x[0], x[1]);



    return 0;
}
