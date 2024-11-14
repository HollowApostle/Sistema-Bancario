#include "Funcoes.h"

void amostra(tipoapontador p)
{
    tela_conta();
    gotoxy(50, 7);
    printf("%d", p->conteudo.codigo);

    gotoxy(50, 9);
    printf("%s", p->conteudo.banco);

    gotoxy(50, 11);
    printf("%s", p->conteudo.agencia);

    gotoxy(50, 13);
    printf("%s", p->conteudo.numero_conta);

    gotoxy(50, 15);
    printf("%s", p->conteudo.tipo_conta);

    gotoxy(50, 17);
    printf("%.2lf", p->conteudo.vl_saldo);

    gotoxy(50, 19);
    printf("%.2lf", p->conteudo.vl_limite);
}
