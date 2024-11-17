#include "Funcoes.h"

void TelaCadMovim(TipoLista_movim *l, tipolista *k)
{
    int codigo;
    tipoapontador aux;

    tela();

    imprimir_linha(14);

    if (l->ultimo != NULL)
    {
        gotoxy(29, 6);
        printf("Sequencia movimentacao.: %d", l->ultimo->conteudo.sequencial + 1);
    }
    else
    {
        gotoxy(29, 6);
        printf("Sequencia movimentacao.: %d", 0);
    }
    gotoxy(29, 7);
    printf("Codigo da conta........:  ");

    gotoxy(29, 8);
    printf("Agencia................: ");

    gotoxy(29, 9);
    printf("Numero da conta........: ");

    gotoxy(29, 10);
    printf("Tipo da conta..........: ");

    gotoxy(29, 11);
    printf("Saldo..................: ");

    gotoxy(29, 12);
    printf("Limite.................: ");

    gotoxy(29, 13);
    printf("Total Saldo + Limite...: ");

    gotoxy(54, 7);
    scanf("%d", &codigo);

    aux = pesquisa(k, codigo);

    gotoxy(54, 8);
    printf("%s", aux->conteudo.agencia);

    gotoxy(54, 9);
    printf("%s", aux->conteudo.numero_conta);

    gotoxy(54, 10);
    printf("%s", aux->conteudo.tipo_conta);

    gotoxy(54, 11);
    printf("%lf", aux->conteudo.vl_saldo);

    gotoxy(54, 12);
    printf("%lf", aux->conteudo.vl_limite);

    gotoxy(54, 13);
    printf("%lf", aux->conteudo.vl_limite + aux->conteudo.vl_saldo);

    getch();
}