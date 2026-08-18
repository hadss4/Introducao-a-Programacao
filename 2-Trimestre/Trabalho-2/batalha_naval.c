/*
Implemente na linguagem C um Jogo de Batalha Naval. No link abaixo é dada uma explicação sobre o jogo e suas regras:

https://pt.wikipedia.org/wiki/Batalha_naval_(jogo)

O jogo deve ter as seguintes funcionalidades:

*Permitir dois jogadores: um humano e um computador. As jogadas do computador podem ser aleatórias, ou seguir alguma
 regra pré-definida.

*Ter dois tabuleiros (um para o jogador, outro para o computador), na forma de matriz. Sugestão: para simplificar a
implementação, você pode criar tabuleiros como matrizes de números inteiros.

*O tamanho do tabuleiro é definido no início do jogo. Antes de começar a partida, o jogador escolhe quantas linhas e
quantas colunas o tabuleiro deve ter.

*A quantidade de navios de cada jogador também é definida no início do jogo. Antes de começar a partida, o jogador
escolhe quantos navios deseja, sendo que os dois jogadores (humano e computador) terão a mesma quantidade de navios.

*Todos os navios ocupam apenas uma casa do tabuleiro. Não existem navios maiores (2 ou 3 casas, por exemplo).

*As jogadas são alternadas: o humano joga, depois o computador, depois novamente o humano, e assim sucessivamente. O
jogo acaba quando um dos jogadores encontrar todos os navios do adversário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VAZIO 0
#define NAVIO 1
#define VAZIOAT 2
#define NAVIOAT 3

void header(){
    system("cls");
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

    if (x < 3 || x > tam*2){
        printf("\nERRO: Digite um valor valido!\n");
        sleep(2);
        system("cls");
        qtd_navio(tam);
    }else {
        return x;
    }
}

int set(int tam, int tab[tam][tam]){
    for(int i = 0; i < tam+1; i++){
        for(int d = 0; d < tam+1; d++){
            tab[i][d] = VAZIO;
        }
    }

    return tab;
}

void tabuleiro(int tam){
    printf("\n");
    for(int i = 0; i < tam+1; i++){
        for(int d = 0; d < tam+1; d++){
            if (i == 0){
                if(d == 0){
                    printf("   ");
                }else{
                    printf(" %-3d  ", d);
                }
            }else{
                if(d == 0){
                    printf("%-3d",i);
                }else{
                    printf("[   ] ");
                }
            }
        }
        printf("\n");
    }
}

int esconder(int tam, int nav){
    tabuleiro(tam);
    int tab[tam][tam];
    int n[2];

    printf("\nEscolha onde esconder seus navios:\n");

    for(int i = 0; i < nav; i++){
        printf("Linha: ");
        scanf("%d", &n[0]);
        printf("Coluna: ");
        scanf("%d", &n[1]);
        printf("\n");

        n[0]--;
        n[1]--;

        tab[n[0]][n[1]] = NAVIO;
    }

    return tab;
}

int esconder2(int tam, int nav){
    int random;

    int tab[tam][tam];
    int n[2];

    for(int i = 0; i < nav; i++){
        srand(time(NULL));
        random = rand() % tam;
        n[0] = random--;

        srand(time(NULL));
        random = rand() % tam;
        n[1] = random--;

        tab[n[0]][n[1]] = NAVIO;
    }

    return tab;
}

int main(){
    int x[2];
    x[0] = tamanho(); // arrumar esse erro depois

    system("cls");

    // INICIALIZAÇÃO dos tabuleiros
    int tab1[x[0]][x[0]];
    for(int i = 0; i < x[0]; i++){
        for(int d = 0; d < x[0]; d++){
            tab1[i][d] = VAZIO;
        }
    }
    int tab2[x[0]][x[0]];
    for(int i = 0; i < x[0]; i++){
        for(int d = 0; d < x[0]; d++){
            tab2[i][d] = VAZIO;
        }
    }

    int p1 = 0;
    int p2 = 0;

    x[1] = qtd_navio(x[0]);
    int nav[2];
    nav[0] = x[1];
    nav[1] = x[1];

    // ESCONDER os navios
    tabuleiro(x[0]);

    int n[2];

    printf("\nEscolha onde esconder seus navios:\n");

    for(int i = 0; i < x[1]; i++){
        printf("Linha: ");
        scanf("%d", &n[0]);
        printf("Coluna: ");
        scanf("%d", &n[1]);
        printf("\n");

        n[0]--;
        n[1]--;

        tab1[n[0]][n[1]] = NAVIO;
    }

    int random;

    for(int i = 0; i < x[1]; i++){
        srand(time(NULL));
        random = rand() % x[0];
        n[0] = random;

        srand(time(NULL));
        random = rand() % x[0];
        n[1] = random;

        tab2[n[0]][n[1]] = NAVIO;
    }

    header();
    printf("Sua vez!");

    // JOGO
    while(p1 < x[1] && p2 < x[1]){
        tabuleiro(x[0]);

        printf("\nLinha: ");
        scanf("%d", &n[0]);
        printf("Coluna: ");
        scanf("%d", &n[1]);
        printf("\n");

        n[0]--;
        n[1]--;

        if(tab2[n[0]][n[1]] == VAZIO){
            tab2[n[0]][n[1]] == VAZIOAT;
            printf("Voce nao acertou um navio! Talvez tenha mais sorte na proxima...\n");
        }else if(tab2[n[0]][n[1]] == NAVIO){
            tab2[n[0]][n[1]] == NAVIOAT;
            p1++;
            printf("Parabens!!! Voce atingiu um navio!\n");
        }

        printf("\nVez do Computador\n");

        srand(time(NULL));
        random = rand() % x[0];
        n[0] = random;

        srand(time(NULL));
        random = rand() % x[0];
        n[1] = random;

        if(tab1[n[0]][n[1]] == VAZIO){
            tab1[n[0]][n[1]] == VAZIOAT;
            printf("Que sorte! O computador errou o navio!\n");
        }else if(tab1[n[0]][n[1]] == NAVIO){
            tab1[n[0]][n[1]] == NAVIOAT;
            p2++;
            printf("Poxa! O Computador acertou um navio...\n");
        }

        printf("\nSua vez!");
    }

    printf("\n----------------------------------------------------------------\n");

    if(p1 >= x[1]){
        printf("PARABENS!!!\n:D");
    }else if(p2 >= x[1]){
        printf("GAMEOVER...\n:(");
    }

    printf("\n");

    return 0;
}
