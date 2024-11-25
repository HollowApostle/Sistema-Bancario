
/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024
        RA:171270-2024
Objetivo: responsavel por consultar por ordem alfabetica
*/

#include "Funcoes.h"

double SomaLimite (tipolista *l){

    tipoapontador p;
    double soma;

    p = l->primeiro;

    while (p != NULL)
    {
       soma = p->conteudo.vl_limite + soma;

       p = p->prox;
    }

    soma = soma /2;
    
    return soma;


}


double SomaSaldo (tipolista *l){

    tipoapontador p;
    double soma;

    p = l->primeiro;

    while (p != NULL)
    {
       soma = p->conteudo.vl_saldo + soma;

       p = p->prox;
    }
    
    return soma;


}

void ordenarPorCodigo(tipolista *l)
{
    Tipoitem temp;

    int trocou;
    tipoapontador atual, anterior = NULL;

    do
    {
        trocou = 0;
        atual = l->primeiro;

        while (atual->prox != anterior)
        {
            if (atual->conteudo.codigo > atual->prox->conteudo.codigo)
            {
                // Trocar os conteúdos entre os nós
                temp.conteudo = atual->conteudo;
                atual->conteudo = atual->prox->conteudo;
                atual->prox->conteudo = temp.conteudo;
                trocou = 1;
            }
            atual = atual->prox;
        }
        anterior = atual; // Último elemento já está na posição correta

    } while (trocou);
}

void ordenarPorBanco(tipolista *l)
{

    Tipoitem temp;

    if (l->primeiro == NULL || l->primeiro->prox == NULL)
    {
        // Lista vazia ou com apenas um elemento não precisa ser ordenada
        return;
    }

    int trocou;
    tipoapontador atual, anterior = NULL;

    do
    {
        trocou = 0;
        atual = l->primeiro;

        while (atual->prox != anterior)
        {
            // Comparar os nomes dos bancos
            if (strcmp(atual->conteudo.banco, atual->prox->conteudo.banco) > 0)
            {
                // Trocar os conteúdos entre os nós
                temp.conteudo = atual->conteudo;
                atual->conteudo = atual->prox->conteudo;
                atual->prox->conteudo = temp.conteudo;
                trocou = 1;
            }
            atual = atual->prox;
        }
        anterior = atual; // Último elemento já está na posição correta
    } while (trocou);
}

// Funcao pra mostrar os valores armazenados
int consultarAlfa(tipolista *l, int opc)
{

    tipoapontador aux;
    int conta;
    int status;

    if (l->primeiro == NULL)
    {

        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Nao ha nenhum valor para ler");
        getch();
        gotoxy(8, 23);
        printf("                                                       ");

        return 0;
    }

    TelaConsultaConta();
    if (opc == 3)
    {
        ordenarPorCodigo(l);
    }
    else
    {
        ordenarPorBanco(l);
    }

    aux = l->primeiro;

    while (aux != NULL)
    {

        if (strcmp(aux->conteudo.status, "Ativo") == 0)
        {
            status = 1;
        }
        else
        {
            status = 0;
        }

        gotoxy(2, conta + 7);
        printf("%-2d %-19s %-5s %-8s %-14s R$%9.2lf R$%8.2lf %-2d", aux->conteudo.codigo, aux->conteudo.banco, aux->conteudo.agencia, aux->conteudo.numero_conta, aux->conteudo.tipo_conta, aux->conteudo.vl_saldo, aux->conteudo.vl_limite, status);

        conta++;

        if (conta == 15)
        {
            gotoxy(8, 23);
            printf("Pressione alguma tecla para continuar...");
            getch();
            gotoxy(8, 23);
            printf("                                           ");

            for (int j = 0; j < 15; j++)
            {
                gotoxy(2, j + 9);
                printf("                                                                             ");
            }

            conta = 0;
        }

        aux = aux->prox;

        if (aux == NULL)
        {
            gotoxy(42, conta + 7);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c",205,205,205,205,205,205,205,205,205,205,205,205, 205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
            gotoxy(42, conta + 8);
            printf("Saldo Total: R$%10.2lf R$%8.2lf",SomaSaldo (l), SomaLimite (l));
        }
        
    }

    getch();

    
}