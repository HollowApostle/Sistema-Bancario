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
