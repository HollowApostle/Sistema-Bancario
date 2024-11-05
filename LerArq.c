#include "Funcoes.h"

void lerArquivo(tipolista *l)
{
    FILE *arquivo = fopen("folha.dat", "rb"); // Tenta abrir o arquivo para leitura binária
    if (arquivo == NULL)
    {
        // Se o arquivo não existir, cria um novo arquivo vazio
        arquivo = fopen("folha.dat", "wb");
        if (arquivo == NULL)
        {
            gotoxy(8, 23);
            printf("Erro ao criar o arquivo!");
            getch();
            return;
        }
        fclose(arquivo); // Fecha o arquivo criado

        // Reabre o arquivo agora no modo de leitura
        arquivo = fopen("folha.dat", "rb");
        if (arquivo == NULL)
        {
            gotoxy(8, 23);
            printf("Erro ao abrir o arquivo para leitura!");
            getch();
            return;
        }
    }

    reg_funcionario cont;
    while (fread(&cont, sizeof(reg_funcionario), 1, arquivo))
    {
        tipoapontador novo = (tipoapontador)malloc(sizeof(Tipoitem));
        novo->conteudo = cont;
        novo->prox = NULL;

        if (l->primeiro == NULL)
        {
            l->primeiro = novo;
            l->ultimo = novo;
        }
        else
        {
            l->ultimo->prox = novo;
            l->ultimo = novo;
        }
    }

    fclose(arquivo);
}
