#include "Funcoes.h"

void TelaConsultaG()
{
    system("cls");
    
    int i;

    imprimir_ultm_linha(24);

    imprimir_prim_linha(1);

    for (i = 2; i < 24; i++)
    {
        gotoxy(01, i);
        printf("%c", 186); // Borda esquerda

        gotoxy(80, i);
        printf("%c", 186); // Borda direita
    }

    imprimir_linha(22);

    gotoxy(02, 23);
    printf("MSG.:");

    gotoxy(2, 6);
    printf("Cd");

    gotoxy(6, 6);
    printf("Banco");

    gotoxy(18, 6);
    printf("Agencia");

    gotoxy(26, 6);
    printf("Conta");

    gotoxy(34, 6);
    printf("Tipo Conta");

    gotoxy(50, 6);
    printf("Saldo");

    gotoxy(65, 6);
    printf("Limite");

    gotoxy(76, 6);
    printf("St");

    getch();

}