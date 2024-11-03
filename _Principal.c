
#include "Listas.c"

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

        gotoxy(29, 3);
        printf("CADASTRO DE CLIENTES");

        gotoxy(29, 5);
        printf("1-Cadastrar no final da lista ");

        gotoxy(29, 7);
        printf("2-Cadastrar no comeco da lista ");

        gotoxy(29, 9);
        printf("3-Cadastrar em uma posicao da lista ");

        gotoxy(29, 11);
        printf("4-Remover no inicio da lista");

        gotoxy(29, 13);
        printf("5-Remover no final da lista");

        gotoxy(29, 15);
        printf("6-Remover em uma posicao da lista ");

        gotoxy(29, 17);
        printf("7-Alteracao do Cadastro de Funcionario");

        gotoxy(29, 19);
        printf("8-Consultar");

        gotoxy(29, 21);
        printf("9-Sair");

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

        case 4:
            remover(&l, opcao);
            gravarArquivo(&l);

            break;

        case 5:
            remover(&l, opcao);
            gravarArquivo(&l);

            break;

        case 6:
            remover(&l, opcao);
            gravarArquivo(&l);

            break;

        case 7:
            alterar(&l);
            gravarArquivo(&l);

            break;

        case 8:
            listarFun(&l);
            break;

        case 9:
            gravarArquivo(&l);

        default:
            break;
        }

    } while (opcao != 9);

    gotoxy(37, 25);

    return 0;
}