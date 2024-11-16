#include "Funcoes.h"

void amostra(tipoapontador p)
{
    tela_conta();
    gotoxy(51, 7);
    printf("%d", p->conteudo.codigo);

    gotoxy(51, 9);
    printf("%s", p->conteudo.banco);

    gotoxy(51, 11);
    printf("%s", p->conteudo.agencia);

    gotoxy(51, 13);
    printf("%s", p->conteudo.numero_conta);

    gotoxy(51, 15);
    printf("%s", p->conteudo.tipo_conta);

    gotoxy(51, 17);
    printf("%.2lf", p->conteudo.vl_saldo);

    gotoxy(51, 19);
    printf("%.2lf", p->conteudo.vl_limite);
}
