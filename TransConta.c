#include "Funcoes.h"

int TransConta(TipoLista_movim *m, tipolista *l) {
    int codigo;
    int codigo2;
    tipoapontador aux; 
    tipoapontador aux2;
    double valorTransferencia;
    char dataTransfe[11]; 

    if (l->primeiro == NULL) {
        gotoxy(8, 23);
        printf("Nenhuma conta encontrada para efetuar a transferencia");
        getch();
        return 0;
    }

    tela_transferencia();

    
    gotoxy(26, 7);
    scanf("%d", &codigo);
    aux = pesquisa(l, codigo);

    
    do {
        if (aux == NULL) {
            gotoxy(8, 23);
            printf("Conta nao encontrada ou inexistente");
            getch();
        } else if (strcmp(aux->conteudo.status, "Desativada") == 0) {
            gotoxy(8, 23);
            printf("Conta desativada");
            getch();
        }
    } while (aux == NULL || strcmp(aux->conteudo.status, "Desativada") == 0);

    
    gotoxy(26, 8);
    printf("%s", aux->conteudo.banco);
    gotoxy(26, 9);
    printf("%s", aux->conteudo.agencia);
    gotoxy(26, 10);
    printf("%s", aux->conteudo.tipo_conta);
    gotoxy(26, 11);
    printf("%.2lf", aux->conteudo.vl_saldo);

    
    gotoxy(66, 7);
    scanf("%d", &codigo2);
    aux2 = pesquisa(l, codigo2);

    
    do {
        if (aux2 == NULL) {
            gotoxy(8, 23);
            printf("Conta nao encontrada ou inexistente");
            getch();
        } else if (strcmp(aux2->conteudo.status, "Desativada") == 0) {
            gotoxy(8, 23);
            printf("Conta desativada");
            getch();
        }
    } while (aux2 == NULL || strcmp(aux2->conteudo.status, "Desativada") == 0);

    
    gotoxy(66, 8);
    printf("%s", aux2->conteudo.banco);
    gotoxy(66, 9);
    printf("%s", aux2->conteudo.agencia);
    gotoxy(66, 10);
    printf("%s", aux2->conteudo.tipo_conta);
    gotoxy(66, 11);
    printf("%.2lf", aux2->conteudo.vl_saldo);

    
    gotoxy(52, 18);
    printf("");
    scanf("%lf", &valorTransferencia);

    
    if (valorTransferencia <= 0 || valorTransferencia > (aux->conteudo.vl_saldo + aux->conteudo.vl_limite)) {
        gotoxy(8, 23);
        printf("Saldo insuficiente para realizar a transferencia");
        getch();
        return 0;
    }

    
    do {
        gotoxy(52, 19);
        printf("");
        scanf("%s", dataTransfe);

        if (!validar_data(dataTransfe)) {
            gotoxy(8, 23);
            printf("Data invalida. Tente novamente.");
            getch();
        }
    } while (!validar_data(dataTransfe));

    
    aux->conteudo.vl_saldo -= valorTransferencia;
    aux2->conteudo.vl_saldo += valorTransferencia;

    
    gotoxy(8, 23);
    printf("Transferencia realizada com sucesso em %s", dataTransfe);
    getch();

    return 1;
}
