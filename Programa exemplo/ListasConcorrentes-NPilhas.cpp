#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<ctype.h>
#include<windows.h>
#include "TADNPilhas.h"

char menu(){
    system("cls");
    textcolor(15);
    printf("\n\n\n\n\n\n\n\t\t\t\t==============================================\n");
    printf("\t\t\t\t    SIMULACAO LISTAS CONCORRENTES - N PILHAS           \n");
    printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t   [ ENTER ]  -  Iniciar\n");
    printf("\t\t\t\t   [ Qualquer tecla ]  - Sair\n");
    printf("\t\t\t\t==============================================\n");

    return toupper(getch());
}

int main(){
    TpPilhaM2 pm;

    int ut, x, pos;
    char letra, op;

    op = menu();
    while(op == 13){

        //desenhos
        system("cls");
        desenhaDescricao();
        desenhaVetor(12, 30);
        desenhaPlacaInformacoes(23, 5);

        //inicializacoes
        inicializar(pm, 3);  // nesse caso vão ser criadas "3 pilhas" [mude ao seu gosto]
        ut = 1;
        letra = 65;
        x = pos = 0;

        while(!cheia(pm, 0) && !cheia(pm, 1) && !cheia(pm, 2) && !kbhit()){

            gotoxy(12, 25);
            printf("UT = %d", ut);
            exibir(pm, 3);

            if(ut % 3 == 0){
                if(pos == 3)
                    pos = 0;
                if(!cheia(pm, pos))
                    inserir(pm, letra++, pos);
                pos++;
            }

            if(ut % 7 == 0){
                if(x == 3)
                    x = 0;
                retirar(pm, x++);
            }

            ut++;
            Sleep(1000);
        }

        getch();
        op = menu();
    }
}








