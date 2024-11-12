#include "Funcoes.h"

// Função para remover um funcionário da lista
int remover(tipolista *l, int opc)
{
    tipoapontador p;   // Apontador para o item a ser removido
    tipoapontador aux; // Apontador auxiliar para a lista
    int teste;         // Variável para confirmar remoção
    int cont;          // Contador para percorrer a lista
    int pos;           // Posição do funcionário a ser removido
    int qtd;           // Total de funcionários na lista

    // Verifica se a lista está vazia
    if (l->primeiro == NULL)
    {
        gotoxy(8, 23);
        printf("Nao ha nenhum valor para remover");
        getch();
        return 0;
    }

    // Remoção de acordo com a opção escolhida
    if (opc ==  1) // Remover o primeiro funcionário
    {
        amostra(l->primeiro); // Mostra os dados do primeiro funcionário
        gotoxy(8, 23);
        printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
        scanf("%d", &teste);

        // Se o usuário confirmar, remove o funcionário
        if (teste == 1)
        {
            if (l->primeiro->prox == NULL)
            {
                // Caso a lista tenha apenas um funcionário
                free(l->primeiro);
                l->primeiro = NULL;
                l->ultimo = NULL; // Atualiza o último elemento
            }
            else
            {
                // Remove o primeiro funcionário e atualiza o ponteiro
                p = l->primeiro;
                l->primeiro = p->prox;
                free(p);
            }
        }
        else
        {
            return 0; // Não remove
        }
    }
    else if (opc == 2) // Remover o último funcionário
    {
        if (l->primeiro->prox == NULL)
        {
            free(l->primeiro); // Caso a lista tenha apenas um funcionário
            l->primeiro = NULL;
            l->ultimo = NULL;
        }
        else
        {
            aux = l->primeiro; // Apontador auxiliar para percorrer a lista
            p = aux->prox;

            // Percorre até o penúltimo elemento
            while (p->prox != NULL)
            {
                p = p->prox;
                aux = aux->prox; // Move ambos os apontadores
            }

            amostra(p); // Mostra os dados do último funcionário
            gotoxy(8, 23);
            printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
            scanf("%d", &teste);

            // Se o usuário confirmar, remove o último funcionário
            if (teste == 1)
            {
                free(p);
                aux->prox = NULL; // Atualiza o último ponteiro
                l->ultimo = aux;  // Define o novo último funcionário
            }
            else
            {
                return 0; // Não remove
            }
        }
    }
    else if (opc == 3) // Remover um funcionário por posição
    {
        do
        {
            gotoxy(8, 23);
            printf("Digite a posicao a ser apagada: ");
            scanf("%d", &pos);
            gotoxy(8, 23);
            printf("                                                       ");

            qtd = contador(l); // Obtém a quantidade de funcionários

            // Valida a posição inserida
            if (pos > qtd || pos < 1)
            {
                gotoxy(8, 23);
                printf("Posicao invalida");
                getch();
            }

        } while (pos > qtd || pos < 1); // Garante que a posição é válida

        if (pos == 1) // Remoção do primeiro funcionário
        {
            amostra(l->primeiro); // Mostra os dados do primeiro funcionário
            gotoxy(8, 23);
            printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
            scanf("%d", &teste);

            if (teste == 1)
            {
                p = l->primeiro;                 // Armazena o primeiro para liberar
                l->primeiro = l->primeiro->prox; // Atualiza o primeiro
                free(p);

                if (l->primeiro == NULL)
                {
                    l->ultimo = NULL; // Atualiza último se a lista estiver vazia
                }
            }
            else
            {
                return 0; // Não remove
            }
        }
        else // Remoção em qualquer outra posição
        {
            aux = l->primeiro; // Apontador para percorrer a lista
            p = aux->prox;     // Começa do segundo
            cont = 1;          // Contador de posição

            // Percorre até a posição desejada
            while (cont < pos - 1 && p != NULL)
            {
                cont++;
                aux = p;     // Move para o próximo
                p = p->prox; // Move para o próximo
            }

            if (p != NULL) // Se o funcionário existe na posição
            {
                amostra(p); // Mostra os dados do funcionário a ser removido
                gotoxy(8, 23);
                printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
                scanf("%d", &teste);

                if (teste == 1) // Se o usuário confirmar a remoção
                {
                    aux->prox = p->prox; // Remove o funcionário
                    free(p);             // Libera a memória

                    if (aux->prox == NULL)
                    {
                        l->ultimo = aux; // Atualiza o último funcionário se necessário
                    }
                }
            }
        }
    }
    return 0; // Retorna ao chamador
}