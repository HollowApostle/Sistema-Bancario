#include "Funcoes.h"

int TransConta(TipoLista_movim *m, tipolista *l)
{
    int codigo;
    int codigo2;
    int teste;
    tipoapontador aux;
    tipoapontador aux2;
    reg_movimentos cont;
    reg_movimentos cont2;

    if (l->primeiro == NULL)
    {
        gotoxy(8, 23);
        printf("Nenhuma conta encontrada para efetuar a transferencia");
        getch();
        return 0;
    }

    tela_transferencia();

    gotoxy(8, 23);
    printf("Digite \"0\" para sair");

    gotoxy(26, 7);
    scanf("%d", &codigo);

    if (codigo == 0)
    {

        gotoxy(8, 23);
        printf("Deseja realmente sair (Sim = 1/Nao = 2): ");
        scanf("%d", &teste);
        gotoxy(8, 23);
        printf("                                            ");
        gotoxy(8, 23);

        if (teste == 1)
        {
            return 0;
        }
    }

    aux = pesquisa(l, codigo);

    do
    {
        if (aux == NULL)
        {
            gotoxy(8, 23);
            printf("Conta nao encontrada ou inexistente");
            getch();
        }
        else if (strcmp(aux->conteudo.status, "Inativa") == 0)
        {
            gotoxy(8, 23);
            printf("Conta inativa");
            getch();
        }
    } while (aux == NULL || strcmp(aux->conteudo.status, "Inativa") == 0);

    gotoxy(26, 8);
    printf("%s", aux->conteudo.banco);
    gotoxy(26, 9);
    printf("%s", aux->conteudo.agencia);
    gotoxy(26, 10);
    printf("%s", aux->conteudo.tipo_conta);
    gotoxy(26, 11);
    printf("%.2lf", aux->conteudo.vl_saldo);
    gotoxy(26, 12);
    printf("%.2lf", aux->conteudo.vl_limite);
    gotoxy(26, 13);
    printf("%.2lf", aux->conteudo.vl_saldo + aux->conteudo.vl_limite);

    gotoxy(66, 7);
    scanf("%d", &codigo2);
    aux2 = pesquisa(l, codigo2);

    do
    {
        if (aux2 == NULL)
        {
            gotoxy(8, 23);
            printf("Conta nao encontrada ou inexistente");
            getch();
        }
        else if (strcmp(aux2->conteudo.status, "Inativa") == 0)
        {
            gotoxy(8, 23);
            printf("Conta inativa");
            getch();
        }
    } while (aux2 == NULL || strcmp(aux2->conteudo.status, "Inativa") == 0);

    gotoxy(66, 8);
    printf("%s", aux2->conteudo.banco);
    gotoxy(66, 9);
    printf("%s", aux2->conteudo.agencia);
    gotoxy(66, 10);
    printf("%s", aux2->conteudo.tipo_conta);
    gotoxy(66, 11);
    printf("%.2lf", aux2->conteudo.vl_saldo);
    gotoxy(66, 12);
    printf("%.2lf", aux2->conteudo.vl_limite);
    gotoxy(66, 13);
    printf("%.2lf", aux2->conteudo.vl_saldo + aux2->conteudo.vl_limite);

    gotoxy(52, 18);
    printf("");
    scanf("%f", &cont.vl_movimento);

    if (cont.vl_movimento <= 0 || cont.vl_movimento > (aux->conteudo.vl_saldo + aux->conteudo.vl_limite))
    {
        gotoxy(8, 23);
        printf("Saldo insuficiente para realizar a transferencia");
        getch();
        return 0;
    }

    do
    {
        gotoxy(52, 19);
        printf("                  ");
        gotoxy(52, 19);
        getchar();
        fflush(stdin);
        fgets(cont.dt_movimento, 11, stdin);

        if (!validarECompararComLista(cont.dt_movimento, m))
        {
            gotoxy(8, 23);
            printf("Data invalida. Tente novamente.");
            getch();
        }
    } while (!validarECompararComLista(cont.dt_movimento, m));

    aux->conteudo.vl_saldo -= cont.vl_movimento;
    aux2->conteudo.vl_saldo += cont.vl_movimento;

    gotoxy(26, 14);
    printf("%.2lf", aux->conteudo.vl_saldo);

    gotoxy(66, 14);
    printf("%.2lf", aux2->conteudo.vl_saldo);

    gotoxy(8, 23);
    printf("Transferencia realizada com sucesso em %s", cont.dt_movimento);
    getch();

    cont.codigo_conta = codigo;
    strcpy(cont.ds_favorecido, "Transferencia Entre Contas");

    if (m->ultimo == NULL)
    {
        cont.sequencial = 1;
    }
    else
    {
        cont.sequencial = m->ultimo->conteudo.sequencial + 1;
    }

    strcpy(cont.tp_movimento, "Debito");

    cont.vl_saldo = aux->conteudo.vl_saldo;

    inserirMovim(m, cont);

    cont2.codigo_conta = codigo2;
    strcpy(cont2.ds_favorecido, "Transferencia Entre Contas");

    if (m->ultimo == NULL)
    {
        cont2.sequencial = 1;
    }
    else
    {
        cont2.sequencial = m->ultimo->conteudo.sequencial + 1;
    }

    strcpy(cont2.tp_movimento, "Credito");

    cont2.vl_saldo = aux2->conteudo.vl_saldo;

    strcpy(cont2.dt_movimento, cont.dt_movimento);

    cont2.vl_movimento = cont.vl_movimento;

    inserirMovim(m, cont2);

    return 1;
}
