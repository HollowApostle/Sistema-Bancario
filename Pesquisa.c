#include "Funcoes.h"

tipoapontador pesquisa(tipolista *l, int cod)
{

    tipoapontador aux;

    // Inicia a pesquisa a partir do primeiro elemento da lista

    aux = l->primeiro;

    // Percorre a lista até encontrar o código ou chegar ao fim (NULL)

    while (aux != NULL)
    {
        if (aux->conteudo.codigo == cod)
        {
            return aux;
        }

        aux = aux->prox;
    }

    return NULL;
}