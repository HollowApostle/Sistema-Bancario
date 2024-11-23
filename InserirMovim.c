#include "Funcoes.h"

void inserirMovim(TipoLista_movim *l, reg_movimentos cont)
{
    tipoapontador_movim p;
    tipoapontador_movim f;
    tipoapontador_movim F;

   
    cont.dt_movimento[strcspn(cont.dt_movimento, "\n")] = '\0';
    cont.ds_favorecido[strcspn(cont.ds_favorecido, "\n")] = '\0';


    // cria o no p
    p = (tipoapontador_movim)malloc(sizeof(Tipoitem_movim));

   p -> conteudo = cont;
   p ->prox = NULL;
   p ->ant = NULL;

    // adiciona no final

    if (l->primeiro == NULL)
    {
        l->primeiro = p;
        l->ultimo = p;
    }
    else
    {
        l -> ultimo -> prox = p;
        p->ant = l ->ultimo;
        l -> ultimo = p;
    }
}