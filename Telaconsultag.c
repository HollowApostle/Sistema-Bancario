#include "Funcoes.h"

void TelaConsultaG()
{
    
    tela();

    imprimir_linha(6);

    gotoxy(24, 3);
    printf("LISTA DE MOVIMENTACOES BANCARIAS");

    gotoxy(2, 5);
    printf("Codigo:");

    gotoxy(2, 7);
    printf("Dt.Movim   Favorecido                    TpMovim       Vl.Movim    Saldo      ");
   
   imprimir_linha(8);

    gotoxy(12, 8);
    printf(" ");

    gotoxy(42, 8);
    printf(" ");

    gotoxy(56, 8);
    printf(" ");


    gotoxy(68, 8);
    printf(" ");


}