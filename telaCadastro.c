#include "Funcoes.h"

void telaCadastro()
{
    int opcao;

    tipolista l;

    l.primeiro = NULL;
    l.ultimo = NULL;

    lerArquivo(&l);

    do
    {
        // Construção da tela

        tela();

        gotoxy(29, 3);
        printf("CADASTRO DE CLIENTES");

        gotoxy(29, 5);
        printf("1-Cadastrar no final da lista ");

        gotoxy(29, 7);
        printf("2-Cadastrar no comeco da lista ");

        gotoxy(29, 9);
        printf("3-Cadastrar em uma posicao da lista ");
        // Leitura de dados
        gotoxy(43, 23);
        scanf("%d", &opcao);

        // Verificando se a opcao escolhida eh valida
        if (opcao > 9 || opcao <= 0)
        {
            gotoxy(8, 23);
            printf("                                        ");
            gotoxy(8, 23);
            printf("Digite um valor valido (1 a 8)");
            getch();
            gotoxy(8, 23);
            printf("                               ");
        }
        // Trabalhando a opcao escolhida
        switch (opcao)
        {
        case 1:
            cadastro(&l, opcao);
            gravarArquivo(&l);

            break;

        case 2:
            cadastro(&l, opcao);
            gravarArquivo(&l);

            break;

        case 3:
            cadastro(&l, opcao);
            gravarArquivo(&l);

            break;

        default:
            break;
        }

    } while (opcao != 3);

    gotoxy(37, 25);

    return 0;
}
