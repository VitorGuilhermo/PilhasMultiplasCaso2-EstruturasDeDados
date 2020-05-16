#define MAXPILHA 10

struct TpPilhaM2{
    int bases[MAXPILHA], topos[MAXPILHA];
    char pilhas[MAXPILHA];
};

void inicializar(TpPilhaM2 &PM, int quantidade){
    int i, quantElem = MAXPILHA/quantidade;

    for(i=0; i<=quantidade; i++){
        PM.bases[i] = quantElem * i;
        PM.topos[i] = PM.bases[i] - 1;
    }
}

void inserir(TpPilhaM2 &PM, char elem, int nPilha){
    PM.pilhas[++PM.topos[nPilha]] = elem;
}
char retirar(TpPilhaM2 &PM, int nPilha){
    return PM.pilhas[PM.topos[nPilha]--];
}

char elementoTopo(TpPilhaM2 PM, int nPilha){
    return PM.pilhas[PM.topos[nPilha]];
}

int cheia(TpPilhaM2 PM, int nPilha){
    return PM.topos[nPilha] == PM.bases[nPilha+1];
}
int vazia(TpPilhaM2 PM, int nPilha){
    return PM.topos[nPilha] < PM.bases[nPilha];
}

void exibir(TpPilhaM2 PM, int qtdePilhas){
    int i, coluna = 36;
    for(i = 0; i<qtdePilhas; i++){

         if(i == 0)
            coluna = 31;
        else if(i == 1)
            coluna = 46;
        else if(i == 2)
            coluna = 61;

        while(!vazia(PM, i)){
            gotoxy(coluna+=5, 14);
            printf("%c", retirar(PM, i));
        }
    }

}

//desenhos
void desenhaVetor(int linha, int coluna){
    char vetor[][100] = {
                                "     _________________________________________________  ",
                                "    |    |    |    |    |    |    |    |    |    |    |",
                                "    |    |    |    |    |    |    |    |    |    |    |",
                                "    |____|____|____|____|____|____|____|____|____|____|",
                                "      0    1    2    3    4    5    6    7    8    9"
                                };
    textcolor(3);
    for(int i = 0; i<5; i++){
        gotoxy(coluna, linha+i);
        printf("%s\n", vetor[i]);
    }
    textcolor(15);
}
void desenhaDescricao(){
    textcolor(11);
    gotoxy(8, 1);
    printf("==========================================================================================================");
    gotoxy(38, 2);
    printf("SIMULACAO DE UMA PILHA MULTIPLA - N PILHAS               ");
    gotoxy(8, 3);
    printf("==========================================================================================================");
    textcolor(15);
}
void desenhaPlacaInformacoes(int linha, int coluna){
    int i;
    char placa [][150] = {
                        " _____________________________________________________________________________________________________________",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|_____________________________________________________________________________________________________________|"
                        };
    textcolor(3);
    for(i = 0; i<7; i++){
        gotoxy(coluna, linha+i);
        printf("%s\n", placa[i]);
    }
    textcolor(15);
}
