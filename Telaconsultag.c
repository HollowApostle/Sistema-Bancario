#include "Funcoes.h"

void TelaConsultaG()
{
    tela();

    imprimir_linha(6);

    gotoxy(2, 5);
    printf("Cd");

    gotoxy(6, 5);
    printf("Banco");

    gotoxy(18, 5);
    printf("Agencia");

    gotoxy(26, 5);
    printf("Conta");

    gotoxy(34, 5);
    printf("Tipo Conta");

    gotoxy(50, 5);
    printf("Saldo");

    gotoxy(65, 5);
    printf("Limite");

    gotoxy(76, 5);
    printf("St");

    

    getch();
}