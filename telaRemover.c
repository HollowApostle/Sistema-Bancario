#include "Funcoes.h"

void TelaRemover(tipolista *l)
{

    int opcao;

    lerArquivo(l);

    do
    {

        tela();

        gotoxy(29, 3);
        printf("REMOVER CONTAS");

        gotoxy(29, 8);
        printf("1 - Remover do final da lista ");

        gotoxy(29, 10);
        printf("2 - Remover do inicio da lista ");

        gotoxy(29, 12);
        printf("3 - Remover de alguma posicao da lista ");

        gotoxy(29, 14);
        printf("4 - Sair ");

        gotoxy(43, 23);
        scanf("%d", &opcao);

        if (opcao > 4 || opcao <= 0)
        {
            gotoxy(8, 23);
            printf("                                        ");
            gotoxy(8, 23);
            printf("Digite um valor valido (1 a 4)");
            getch();
            gotoxy(8, 23);
            printf("                               ");
        }

        switch (opcao)
        {
        case 1:
            remover(l, opcao);
            gravarArquivo(l);

            break;

        case 2:
            remover(l, opcao);
            gravarArquivo(l);

            break;

        case 3:
            remover(l, opcao);
            gravarArquivo(l);

            break;

        case 4:
            gravarArquivo(l);

            break;

        default:
            break;
        }

    } while (opcao != 4);

    gotoxy(37, 25);
}