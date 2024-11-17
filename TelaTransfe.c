#include "Funcoes.h"

void tela_transferencia() {
    int i;

    for (i = 4; i < 16; i++) { 
    gotoxy(40, i);
    printf("%c", 186); 
    }

    gotoxy(15, 3);
    printf("Conta Origem");

    gotoxy(55, 3);
    printf("Conta Destino");

    
    gotoxy(10, 6);
    printf("Conta de origem: ");
    gotoxy(10, 7);
    printf("Banco..........: ");
    gotoxy(10, 8);
    printf("Agencia........: ");
    gotoxy(10, 9);
    printf("Numero da conta: ");
    gotoxy(10, 10);
    printf("Tipo da conta..: ");
    gotoxy(10, 11);
    printf("Saldo..........: ");
    gotoxy(10, 12);
    printf("Limite.........: ");
    gotoxy(10, 13);
    printf("Saldo + Limite.: ");
    gotoxy(10, 14);
    printf("Novo Saldo.....: ");
    
    gotoxy(50, 6);
    printf("Conta de origem: ");
    gotoxy(50, 7);
    printf("Banco..........: ");
    gotoxy(50, 8);
    printf("Agencia........: ");
    gotoxy(50, 9);
    printf("Numero da conta: ");
    gotoxy(50, 10);
    printf("Tipo da conta..: ");
    gotoxy(50, 11);
    printf("Saldo.........: ");
    gotoxy(50, 12);
    printf("Limite.........: ");
    gotoxy(50, 13);
    printf("Saldo + Limite.: ");
    gotoxy(50, 14);
    printf("Novo Saldo.....: ");

    gotoxy(02, 16);
     for (i = 1; i <= 80; i++) {
        printf("%c", 205);
    }

    gotoxy(02, 18);
    printf("             Valor a ser transferido.: ");
    gotoxy(02, 19);
    printf("             Data da transferencia...: ");
    
}
