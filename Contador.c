/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024
        RA:171270-2024
Objetivo: responsavel por contar a quantidade de contas cadastradas
*/

#include "Funcoes.h"

int contador(tipolista *l)
{

    tipoapontador aux;

    int cont = 0;

    aux = l->primeiro;

    // percorre a lista contando
    while (aux != NULL)
    {
        cont++;

        aux = aux->prox;
    }

    return cont;
}
