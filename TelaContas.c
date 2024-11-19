#include "Funcoes.h"


void TelaContas(tipolista *l){

    int opcao = 0;
    
    do{       
        

        tela();

        gotoxy(32, 3);
        printf("SISTEMA BANCARIO");

        gotoxy(29, 9);
        printf("1-Cadastrar conta");

        gotoxy(29, 11);
        printf("2-Remover conta");

        gotoxy(29, 13);
        printf("3-Alteracao do Cadastro de conta");

        gotoxy(29, 15);
        printf("4-Consultar contas");

        gotoxy(29, 17);
        printf("5-Retornar ao menu anterior");


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
            telaCadastro(l);
            gravarArquivo(l);

            break;

        case 2:

            TelaRemover(l);
            break;

        case 4:

            consultar(l);

        case 5:

            break;

        default:
            break;
        }

    } while (opcao != 5);

    gotoxy(37, 25);

}