#include "Funcoes.h"


void TelaMovim(TipoLista_movim *m, tipolista *l){

    int opcao = 0;
    
    do{       
        

        tela();

        gotoxy(32, 3);
        printf("SISTEMA BANCARIO");

        gotoxy(29, 9);
        printf("1-Movimentacao de debito e credito");

        gotoxy(29, 11);
        printf("2-Transferencias entre contas bancarias");

        gotoxy(29, 13);
        printf("3-Consultas movimentacoes bancarias");

        gotoxy(29, 15);
        printf("4-Retornar ao menu anterior");


        // Leitura de dados
        opcao = validarNum("Digite o numero da opcao desejada: ", 8, 23);

        // Verificando se a opcao escolhida eh valida
        if (opcao > 5 || opcao <= 0)
        {
            gotoxy(8, 23);
            printf("                                        ");
            gotoxy(8, 23);
            printf("Digite um valor valido (1 a 5)");
            getch();
            gotoxy(8, 23);
            printf("                               ");
        }

        // Trabalhando a opcao escolhida
        switch (opcao)
        {
        case 1:
            movimCreDeb(m, l);
 

            break;

        case 2:

            TransConta(m,l);
            
            break;

        case 3:

            break;

        default:
            break;
        }

    } while (opcao != 5);

    gotoxy(37, 25);

}