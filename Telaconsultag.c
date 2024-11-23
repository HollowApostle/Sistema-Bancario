#include "Funcoes.h"

void TelaConsultaG(tipolista *l)
{
    int i;
    
    tela();

    imprimir_linha(6);


    gotoxy(20, 3);
    printf("LISTA DE MOVIMENTACOES BANCARIAS");

    gotoxy(2, 6);
    printf("Codigo:");

    gotoxy(1, 7);
    printf("+-----------------------------------------------------------------------------+");

    gotoxy(2, 8);
    printf("Dt.Movim");

    gotoxy(13, 8);
    printf("Favorecido");

    gotoxy(40, 8);
    printf("TpMovim");

    gotoxy(55, 8);
    printf("Vl.Movim");

    gotoxy(70, 8);
    printf("Saldo");

    gotoxy(1, 9);
    printf("+-----------------------------------------------------------------------------+");

    getch();
}