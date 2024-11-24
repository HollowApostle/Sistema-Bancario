#include "Funcoes.h"

void telaCadastro(tipolista *l)
{
    int opcao;

    lerArquivo(l);

    do
    {
        // Construção da tela

        tela();

        gotoxy(31, 3);
        printf("CADASTRO DE CONTAS");

        gotoxy(29, 11);
        printf("1-Cadastrar no final da lista ");

        gotoxy(29, 13);
        printf("2-Cadastrar no comeco da lista ");

        gotoxy(29, 15);
        printf("3-Cadastrar em uma posicao da lista ");

        gotoxy(29, 17);
        printf("4-sair ");
        // Leitura de dados

        opcao = validarNum("Digite o numero da opcao desejada: ", 8, 23);

        // Verificando se a opcao escolhida eh valida
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
        // Trabalhando a opcao escolhida
        switch (opcao)
        {
        case 1:
            cadastro(l, opcao);
            gravarArquivo(l);

            break;

        case 2:
            cadastro(l, opcao);
            gravarArquivo(l);

            break;

        case 3:
            cadastro(l, opcao);
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
