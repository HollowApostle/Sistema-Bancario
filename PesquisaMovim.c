#include "Funcoes.h"

tipoapontador_movim pesquisaMovim(TipoLista_movim *l, int cod)
{

    tipoapontador_movim aux;

    // Inicia a pesquisa a partir do primeiro elemento da lista

    aux = l->primeiro;

    // Percorre a lista até encontrar o código ou chegar ao fim (NULL)

    while (aux != NULL)
    {
        if (aux->conteudo.codigo_conta == cod)
        {
            return aux;
        }

        aux = aux->prox;
    }

    return NULL;
}