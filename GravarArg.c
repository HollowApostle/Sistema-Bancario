#include "Funcoes.h"


void gravarArquivo(tipolista *l)
{
    FILE *arquivo = fopen("Contas.dat", "wb"); // Abre o arquivo para escrita binária
    if (arquivo == NULL)
    {
        gotoxy(8, 23);
        printf("Erro ao abrir o arquivo!");
        getch();
        return;
    }

    tipoapontador p = l->primeiro;
    while (p != NULL)
    {
        fwrite(&(p->conteudo), sizeof(reg_funcionario), 1, arquivo);
        p = p->prox;
    }

    fclose(arquivo);
}