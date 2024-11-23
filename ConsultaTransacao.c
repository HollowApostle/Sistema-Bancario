#include "funcoes.h"

void consultar_mov(tipolista *l)
{
    tipoapontador aux;
    reg_movimentos cont;
    int test;

    do
    {
        do
        {
            tela();
            tela_consultar_mov();

            gotoxy(14, 3);
            printf("Consulta de movimentacao");

            gotoxy(7, 24);
            printf("Digite 0 para sair");

            gotoxy(9, 6);
            scanf("%d", &cont.codigo_conta);

            aux = pesquisa(l, cont.codigo_conta);

            if (aux == NULL && cont.codigo_conta != 0)
            {
                gotoxy(7, 24);
                printf("Cadastro nao existe");
                getch();
            }
        } while (aux == NULL && cont.codigo_conta != 0);

        if (cont.codigo_conta != 0)
        {
            cont = aux->conteudo;

            gotoxy(13, 6);
            printf("%s", aux->conteudo.banco);

            gotoxy(30, 6);
            printf("Agencia:");
            gotoxy(38, 6);
            printf("%s", aux->conteudo.agencia);

            gotoxy(47, 6);
            printf("Cta:");
            gotoxy(51, 6);
            printf("%s", aux->conteudo.numero_conta);

            gotoxy(60, 6);
            printf("Conta:");
            gotoxy(67, 6);

            if (strlen(aux->conteudo.tipo_conta) > 0)
            {
                if (aux->conteudo.tipo_conta[0] == '1')
                    printf("Corrente");
                else if (aux->conteudo.tipo_conta[0] == '2')
                    printf("Poupanca");
                else if (aux->conteudo.tipo_conta[0] == '3')
                    printf("Cartao credito");
                else
                    printf("Tipo desconhecido");
            }

            do
            {
                gotoxy(7, 24);
                printf("Deseja consultar outro Cadastro? (1-SIM/2-NAO): ");
                scanf("%d", &test);
            } while (test != 1 && test != 2);
        }

    } while (test == 1);
}