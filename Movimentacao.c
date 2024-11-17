#include "Funcoes.h"

void movimCreDeb(TipoLista_movim *m, tipolista *l)
{
    int codigo;
    tipoapontador aux;
    reg_movimentos cont;
    int resultado;

    TelaCadMovim(m);

    gotoxy(54, 7);
    scanf("%d", &codigo);

    aux = pesquisa(l, codigo);

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

    gotoxy(8, 23);
    printf("Data da Movimentacao (DD/MM/YYYY)");

    do
    {
        gotoxy(54, 15);
        getchar();
        fflush(stdin);
        fgets(cont.dt_movimento, 11, stdin);

        resultado = validar_data(cont.dt_movimento);

        if (resultado != 1)
        {

            gotoxy(8, 23);
            printf("                                   ");

            gotoxy(8, 23);
            printf("Data da Movimentacao Invalida. Formato: DD/MM/YYYY");
            getch();
            gotoxy(8, 23);
            printf("                                                               ");
        }

    } while (resultado != 1);

    gotoxy(8, 23);
    printf("                                   ");
}