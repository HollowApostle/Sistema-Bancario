#include "Funcoes.h"

void TransConta(TipoLista_movim *m, tipolista *l)
{
    int codigo;
    int codigo2;
    tipoapontador aux;
    tipoapontador aux2;
    reg_movimentos cont;
    reg_movimentos cont2;
    int tp_movim;
    double saldo;
    double restante;
    int resultado;
    int confirmacao;

    tela_transferencia();

    gotoxy(26, 7);
    scanf("%d", &codigo);

    cont.codigo_conta = codigo;

    aux = pesquisa(l, codigo);
    do
    {
        if (aux == NULL)
        {
            gotoxy(8, 23);
            printf("                                                     ");
            gotoxy(8, 23);
            printf("Conta nao encontrada ou inexistente");
            getch();
            gotoxy(8, 23);
            printf("                                                     ");
        }
        else if (aux->conteudo.status == "Desativada")
        {

            gotoxy(8, 23);
            printf("                                                     ");
            gotoxy(8, 23);
            printf("Conta desativada");
            getch();
            gotoxy(8, 23);
            printf("                                                     ");
        }
    } while (aux == NULL || aux->conteudo.status == "Desativada");

    gotoxy(26, 8);
    printf("%s", aux->conteudo.banco);

    gotoxy(26, 9);
    printf("%s", aux->conteudo.agencia);

    gotoxy(26, 10);
    printf("%s", aux->conteudo.tipo_conta);

    gotoxy(26, 11);
    printf("%.2lf", aux->conteudo.vl_saldo);

    gotoxy(26, 12);
    printf("%.2lf", aux->conteudo.vl_saldo);

    gotoxy(26, 13);
    printf("%.2lf", aux->conteudo.vl_limite);

    gotoxy(26, 14);
    printf("%.2lf", aux->conteudo.vl_limite + aux->conteudo.vl_saldo);





    gotoxy(66, 7);
    scanf("%d", &codigo2);

    cont2.codigo_conta = codigo2;

    aux2 = pesquisa(l, codigo2);
    do
    {
        if (aux2 == NULL)
        {
            gotoxy(8, 23);
            printf("                                                     ");
            gotoxy(8, 23);
            printf("Conta nao encontrada ou inexistente");
            getch();
            gotoxy(8, 23);
            printf("                                                     ");
        }
        else if (aux2->conteudo.status == "Desativada")
        {

            gotoxy(8, 23);
            printf("                                                     ");
            gotoxy(8, 23);
            printf("Conta desativada");
            getch();
            gotoxy(8, 23);
            printf("                                                     ");
        }
    } while (aux2 == NULL || aux2->conteudo.status == "Desativada");
}
