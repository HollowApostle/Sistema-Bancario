#include "Funcoes.h"

int remover(tipolista *l, int opc)
{
    tipoapontador p;
    tipoapontador aux;
    int teste;
    int cont;
    int pos;
    int qtd;

    // verifica se ha valor pra remover
    if (l->primeiro == NULL)
    {
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Nao ha nenhum valor para remover");
        getch();
        gotoxy(8, 23);
        printf("                                                       ");

        return 0;
    }

    // remover no inicio
    if (opc == 2)
    {

        amostra(l->primeiro);

        // verifica se realmente ira excluir
        gotoxy(8, 23);
        printf("                                        ");
        gotoxy(8, 23);
        printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
        scanf("%d", &teste);
        gotoxy(8, 23);
        printf("                               ");

        // verifica se o dado escolhido e o primeiro, pois o tratamento sera diferente
        if (teste == 1)
        {

            if (l->primeiro->prox == NULL)
            {

                free(l->primeiro);
                l->primeiro = NULL;
                l->ultimo = NULL;
            }
            else
            {
                p = l->primeiro;
                l->primeiro = p->prox;
                free(p);
            }
        }
        else
        {

            return 0;
        }
    }
    else if (opc == 1) // exclui no final
    {

        if (l->primeiro->prox == NULL)
        {

            free(l->primeiro);
            l->primeiro = NULL;
            l->ultimo = NULL;
        }
        else
        {
            aux = l->primeiro;
            p = aux->prox;

            while (p->prox != NULL)
            {
                p = p->prox;
                aux = aux->prox;
            }
        }

        amostra(p);

        gotoxy(8, 23);
        printf("                                        ");
        gotoxy(8, 23);
        printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
        scanf("%d", &teste);
        gotoxy(8, 23);
        printf("                               ");

        if (teste == 1)
        {

            aux->prox = NULL;
            l->ultimo = aux;

            free(p);
        }
        else
        {
            return 0;
        }
    }
    else if (opc == 3) // exclui na posicao desejada
    {
        do
        {
            gotoxy(8, 23);
            printf("                                                       ");
            gotoxy(8, 23);
            printf("Digite a posicao a ser apagada: ");
            scanf("%d", &pos);
            gotoxy(8, 23);
            printf("                                                       ");

            qtd = contador(l);

            if (pos > qtd || pos < 1)
            {
                gotoxy(8, 23);
                printf("                                                       ");
                gotoxy(8, 23);
                printf("Posicao invalida");
                getch();
                gotoxy(8, 23);
                printf("                                                       ");
            }

        } while (pos > qtd || pos < 1);

        if (pos == 1)
        {
            amostra(l->primeiro);

            gotoxy(8, 23);
            printf("                                        ");
            gotoxy(8, 23);
            printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
            scanf("%d", &teste);
            gotoxy(8, 23);
            printf("                               ");

            if (teste == 1)
            {
                aux = l->primeiro;
                p = aux;
            }
            else
            {
                aux = l->primeiro;
                p = aux->prox;

                cont = 1;
            }

            while (cont < pos - 1)
            {
                cont = cont + 1;
                p = p->prox;
                aux = aux->prox;
            }

            if (p != NULL)
            {
                amostra(p);

                gotoxy(8, 23);
                printf("                                        ");
                gotoxy(8, 23);
                printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
                scanf("%d", &teste);
                gotoxy(8, 23);
                printf("                               ");

                if (teste == 1)
                {
                    if (pos == 1)
                    {
                        l->primeiro = p->prox;

                        free(p);
                    }
                    else
                    {
                        aux->prox = p->prox;

                        free(p);
                    }
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    return 0;
}