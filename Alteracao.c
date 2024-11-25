/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024
        RA:171270-2024
Objetivo: responsavel por alterar os cadastros
*/

#include "Funcoes.h"

int alterar(tipolista *l)
{
    int pos;
    int campo;
    int teste;
    reg_funcionario cont;
    tipoapontador p;
    tipoapontador aux;

    // verifica se tem algum valor
    if (l->primeiro == NULL)
    {
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Nao ha nenhum valor para alterar");
        getch();
        gotoxy(8, 23);
        printf("                                                       ");

        return 0;
    }
    tela();
    tela_conta();
    do
    { // faz a entrada de qual codigo do funcionario sera alterado
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Digite o codigo do funcionario a ser alterado: ");
        scanf("%d", &pos);
        gotoxy(8, 23);
        printf("                                                       ");

        aux = pesquisa(l, pos);

        if (aux == NULL)
        {
            gotoxy(8, 23);
            printf("                                                       ");
            gotoxy(8, 23);
            printf("Posicao invalida");
            getch();
            gotoxy(8, 23);
            printf("                                                       ");
        }

    } while (aux == NULL);

    amostra(aux);
    do
    { // faz a entrada de dado de qual campo sera alterado
        gotoxy(8, 23);
        printf("                                        ");
        gotoxy(8, 23);
        printf("Deseja alterar qual campo ?(0 para sair)");
        scanf("%d", &campo);
        gotoxy(8, 23);
        printf("                                         ");

        if (campo < 0 || campo > 7)
        {
            gotoxy(8, 23);
            printf("                                        ");
            gotoxy(8, 23);
            printf("Campo invalido!");
            getch();
            gotoxy(8, 23);
            printf("                                         ");
        }

    } while (campo < 0 || campo > 7);

    // valida se a entrada eh diferente de 0, caso for ele faz a entrada de dados no campo escolhido
    if (campo != 0)
    {
        cont = aux->conteudo;

        switch (campo)
        {
        case 1:
            getchar();
            gotoxy(51, 9);
            printf("                            ");
            gotoxy(51, 9);
            fflush(stdin);
            fgets(cont.banco, 50, stdin);

            break;

        case 2:
            getchar();
            gotoxy(51, 11);
            printf("                            ");
            gotoxy(51, 11);
            fflush(stdin);
            fgets(cont.agencia, 10, stdin);

            break;
        case 3:
            getchar();
            gotoxy(51, 13);
            printf("                            ");
            gotoxy(51, 13);
            fflush(stdin);
            fgets(cont.numero_conta, 20, stdin);
            break;

        case 4:
            getchar();
            gotoxy(51, 17);
            printf("                            ");
            gotoxy(51, 17);
            fflush(stdin);
            fgets(cont.tipo_conta, 20, stdin);

            break;
        case 5:
            getchar();
            gotoxy(51, 19);
            printf("                            ");
            gotoxy(51, 19);
            scanf("%lf", &cont.vl_saldo);

            break;

        case 6:
            getchar();
            gotoxy(51, 19);
            printf("                            ");
            gotoxy(51, 19);
            scanf("%lf", &cont.vl_limite);

            break;

        case 7:
            getchar();
            gotoxy(51, 19);
            printf("                            ");
            gotoxy(51, 19);
            fflush(stdin);
            fgets(cont.tipo_conta, 10, stdin);

            break;

        default:
            break;
        }

        // realiza a alteracao

        gotoxy(8, 23);
        printf("                                    ");
        gotoxy(8, 23);

        teste = validarNum("Deseja salvar alteracao? (Sim = 1/Nao = 2)", 8,23);

        if (teste == 1)
        {
            p = (tipoapontador)malloc(sizeof(Tipoitem));

            p->conteudo = cont;

            p->prox = l->primeiro->prox;
            l->primeiro = p;

            aux->conteudo = p->conteudo;
        }
    }

    return 0;
}