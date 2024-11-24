#include "Funcoes.h"


void gravarArquivoMov(TipoLista_movim *l)
{
    FILE *arquivo = fopen("Movimentacoes.dat", "wb"); // Abre o arquivo para escrita binária
    if (arquivo == NULL)
    {
        gotoxy(8, 23);
        printf("Erro ao abrir o arquivo!");
        getch();
        return;
    }

    tipoapontador_movim p = l->primeiro;
    while (p != NULL)
    {
        fwrite(&(p->conteudo), sizeof(reg_movimentos), 1, arquivo);
        p = p->prox;
    }

    fclose(arquivo);
}