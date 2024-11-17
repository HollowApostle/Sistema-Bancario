#include "Funcoes.h"

void gotoxy(int x, int y) {

    COORD coord;  

   
    coord.X = (short)x;
    coord.Y = (short)y;


    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tela_tranferencia()
{
    gotoxy(15,03);
    printf("TRANSFERENCIA DE VALORES ENTRE CONTAS BANCARIAS");
}

void imprimir_ate_meio(int linha){
    int i;



    gotoxy(40,04);
    printf("%c", 186);


}