
#include "Funcoes.h"

int main()
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

        gotoxy(32, 3);
        printf("SISTEMA BANCARIO");

        gotoxy(29, 9);
        printf("1-Cadastrar conta");

        gotoxy(29, 11);
        printf("2-Remover conta");

        gotoxy(29, 13);
        printf("3-Alteracao do Cadastro de conta");

        gotoxy(29, 15);
        printf("4-Consultar");

        gotoxy(29, 17);
        printf("5-Sair");

        gotoxy(8, 23);
        printf("Digite o numero da opcao desejada: ");

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
            telaCadastro(&l);
            gravarArquivo(&l);

            break;

        case 2:

            TelaRemover(&l);
            break;

        case 4:

           consultar(&l);

        default:
            break;
        }

    } while (opcao != 9);

    gotoxy(37, 25);

    return 0;
}