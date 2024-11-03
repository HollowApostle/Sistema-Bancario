//a viadagem
//Pablo

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

#include "YaTela.c"

typedef struct
{
    int gay;
    char nom[50];
    char ende[50];
    char cargo[50];
    char dt_admissao[11];
    char numTelefone[15];
    float salar;

} reg_funci;

typedef struct tipoItem *tipoApontador;

typedef struct tipoItem
{

    reg_funci conte;
    tipoApontador proxi;

} tipoItem;

typedef struct
{

    tipoApontador prime;
    tipoApontador ult;

} tipoLista;

// Função para pesquisar um funcionário na lista pelo código
tipoApontador pesquisa(tipoLista *l, int cod)
{

    tipoApontador aux = l->prime;

    while (aux != NULL)
    {
        if (aux->conte.codigo == cod)
        {
            return aux;
        }
        aux = aux->proxi;
    }
    return NULL;
}

int Contad(tipoLista *l)
{

    tipoApontador aux;

    int conta = 0;

    aux = l->prime;

    while (aux != NULL)
    {
        conta++;

        aux = aux->proxi;
    }

    return conta;
}

// Função que imprime o layout da tela de cadastro de funcionários
void TelaFunci()
{

    YaTela();

    gotoxy(30, 7);
    printf("codigo............: ");

    gotoxy(30, 9);
    printf("1.nome............: ");

    gotoxy(30, 11);
    printf("2.endereco........: ");

    gotoxy(30, 13);
    printf("3.cargo...........: ");

    gotoxy(30, 15);
    printf("4.data de admissao: ");

    gotoxy(30, 17);
    printf("5.telefone........: ");

    gotoxy(30, 19);
    printf("6.salario.........: ");
}

// Função que exibe os dados de um funcionário na tela
void Mostrar_Tel(tipoApontador P)
{
    TelaFunci();

    gotoxy(54, 7);
    printf("%d", P->conte.codigo);

    gotoxy(54, 9);
    printf("%s", P->conte.nom);

    gotoxy(54, 11);
    printf("%s", P->conte.ende);

    gotoxy(54, 13);
    printf("%s", P->conte.cargo);

    gotoxy(54, 15);
    printf("%s", P->conte.dt_admissao);

    gotoxy(54, 17);
    printf("%s", P->conte.numTelefone);

    gotoxy(54, 19);
    printf("%.2f", P->conte.salar);
}

// Função para cadastrar um novo funcionário na lista
int Cadast(tipoLista *l, int opc)
{
    reg_funci conte;
    tipoApontador P;
    tipoApontador aux;
    tipoApontador aux2;
    int test;
    int posi;
    int quant;

    do
    {
        YaTela();
        TelaFunci();

        // Laço para garantir que o código inserido seja único
        do
        {
            gotoxy(8, 23);
            printf("Digite \"0\" para sair");
            gotoxy(54, 7);
            printf("                 ");
            gotoxy(54, 7);
            scanf("%d", &conte.codigo);

            if (conte.codigo == 0)
            {
                gotoxy(8, 23);
                printf("Deseja realmente sair (Sim = 1/Nao = 0): ");
                scanf("%d", &test);
                gotoxy(8, 23);
                printf("                                            ");
                gotoxy(8, 23);

                if (test == 1)
                {

                    return 0;  // Sai da função se a resposta for sim
                }
            }

            aux = pesquisa(l, conte.codigo);  // Pesquisa se o código já existe

            if (aux != NULL) // Se o código já existir, exibe mensagem
            {

                gotoxy(8, 23);
                printf("Digite um codigo nao digitado anteriormente");
                getch();
                gotoxy(8, 23);
                printf("                                            ");
            }

        } while (aux != NULL || conte.codigo == 0);

        getchar(); // Limpa o buffer de entrada

        // Lê os dados do funcionário e armazena na estrutura 'conte'
        gotoxy(54, 9);
        fflush(stdin);
        fgets(conte.nom, 50, stdin);

        gotoxy(54, 11);
        fflush(stdin);
        fgets(conte.ende, 50, stdin);

        gotoxy(54, 13);
        fflush(stdin);
        fgets(conte.cargo, 50, stdin);

        gotoxy(54, 15);
        fflush(stdin);
        fgets(conte.dt_admissao, 11, stdin);

        gotoxy(54, 17);
        fflush(stdin);
        fgets(conte.numTelefone, 15, stdin);

        gotoxy(54, 19);
        scanf("%f", &conte.salar);

        // Pergunta se deseja gravar as informações
        gotoxy(8, 23);
        printf("Deseja gravar as informacoes? (Sim = 1/Nao = 0): ");
        scanf("%d", &test);

        if (test == 1)
        {
            P = (tipoApontador)malloc(sizeof(tipoItem));
            P->conte = conte;
            P->proxi = NULL;

            // Insere o novo item no final da lista (opção 1)
            if (opc == 1)
            {
                if (l->prime == NULL)
                {
                    l->prime = P;
                    l->ult = P;
                }
                else
                {
                    l->ult->proxi = P;
                    l->ult = P;
                }
            }

            // Insere o novo item no início da lista (opção 2)
            else if (opc == 2)
            {
                if (l->prime == NULL)
                {
                    l->prime = P;
                    l->ult = P;
                }
                else
                {
                    P->proxi = l->prime;
                    l->prime = P;
                }
            }

            // Insere o novo item em uma posição específica (opção 3)
            else if (opc == 3)
            {
                do
                {
                    gotoxy(8, 23);
                    printf("                                                       ");
                    gotoxy(8, 23);
                    printf("Digite qual posicao deseja inserir: ");
                    scanf("%d", &posi);

                    quant = Contad(l);

                    if (posi == 1) // Insere na primeira posição
                    {

                        if (l->prime == NULL)
                        {

                            l->prime = P;
                            l->ult = P;
                            P->proxi = NULL;
                        }

                        else
                        {

                            P->proxi = l->prime; // Insere no início da lista
                            l->prime = P;
                        }

                        break;
                    }
                    else if (posi > quant || posi < 1) // Validação da posição
                    {

                        gotoxy(8, 23);
                        printf("Opcao de posicao invalida. Tente outra posicao");
                        getch();
                    }

                } while (posi > quant || posi < 1);

                if (posi != 1)
                {

                    // Percorre até a posição anterior à desejada
                    aux2 = l->prime;

                    for (int x = 1; x <= posi - 2; x++)
                    {
                        aux2 = aux2->proxi;
                    }

                    P->proxi = aux2->proxi;
                    aux2->proxi = P;
                }
            }

            // Pergunta se deseja cadastrar outro funcionário
            gotoxy(8, 23);
            printf("                                                       ");
            gotoxy(8, 23);
            printf("Deseja cadastrar outro funcionario? (Sim = 1/Nao = 0): ");
            scanf("%d", &test);
            gotoxy(8, 23);
            printf("                                                       ");
        }

    } while (test == 1);

    return 0;
}

int Alterar_Dad(tipoLista *l)
{

    reg_funci conte;
    tipoApontador P;
    tipoApontador aux;
    int posi;
    int camp;

    // Verifica se a lista está vazia
    if (l->prime == NULL)
    {
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Nao ha nenhum funcionario para alterar");
        getch();
        gotoxy(8, 23);
        printf("                                                       ");

        return 0; // Sai da função se não houver funcionários na lista
    }

    YaTela();
    TelaFunci();
    do
    {
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Digite o codigo do funcionario a ser alterado: ");
        scanf("%d", &posi);
        gotoxy(8, 23);
        printf("                                                       ");

        aux = pesquisa(l, posi);

        // Se o código for inválido (funcionário não encontrado)
        if (aux == NULL)
        {
            gotoxy(8, 23);
            printf("                                                       ");
            gotoxy(8, 23);
            printf("Posicao invalida. Tente novamente");
            getch();
            gotoxy(8, 23);
            printf("                                                       ");
        }

    } while (aux == NULL);

    Mostrar_Tel(aux);

    // Pergunta ao usuário qual campo deseja alterar
    do
    {

        gotoxy(8, 23);
        printf("Deseja alterar que campo? (0 para sair): ");
        scanf("%d", &camp);
        gotoxy(8, 23);
        printf("                                         ");

        if (camp < 0 || camp > 6)
        {

            gotoxy(8, 23);
            printf("Campo invalido!");
            getch();
        }

    } while (camp < 0 || camp > 6);

    if (camp != 0)
    {
        conte = aux->conte;

        // Switch-case para selecionar qual campo será alterado
        switch (camp)
        {
        case 1:

            getchar();
            gotoxy(50, 9);
            printf("                          ");
            gotoxy(50, 9);
            fflush(stdin);
            fgets(conte.nom, 50, stdin);
            break;
        case 2:

            getchar();
            gotoxy(50, 11);
            printf("                          ");
            gotoxy(50, 11);
            fflush(stdin);
            fgets(conte.ende, 50, stdin);
            break;
        case 3:

            getchar();
            gotoxy(50, 13);
            printf("                          ");
            gotoxy(50, 13);
            fflush(stdin);
            fgets(conte.cargo, 50, stdin);
            break;
        case 4:

            getchar();
            gotoxy(50, 15);
            printf("                          ");
            gotoxy(50, 15);
            fflush(stdin);
            fgets(conte.dt_admissao, 11, stdin);
            break;
        case 5:

            getchar();
            gotoxy(50, 17);
            printf("                          ");
            gotoxy(50, 17);
            fflush(stdin);
            fgets(conte.numTelefone, 15, stdin);
            break;
        case 6:

            getchar();
            gotoxy(50, 19);
            printf("                            ");
            gotoxy(50, 19);
            scanf("%f", &conte.salar);
            break;

        default:
            break;
        }

        // Aloca um novo item na memória e atualiza os dados alterados
        P = (tipoApontador)malloc(sizeof(tipoItem));

        P->conte = conte;
        aux->conte = P->conte;
    }

    return 0;
}

int Consult(tipoLista *l)
{
    tipoApontador P = l->prime;

    if (l->prime == NULL)
    {
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Nao ha nenhum funcionario cadastrado.");
        getch();
        gotoxy(8, 23);
        printf("                                                       ");

        return 0;
    }

    while (P != NULL)
    {
        Mostrar_Tel(P);

        P = P->proxi;
        getch();
    }

    return 0;
}

int Remov(tipoLista *l, int opc)
{
    tipoApontador P;
    tipoApontador aux;
    int test;
    int posi;
    int quant;
    int conta;

    // Verifica se a lista está vazia
    if (l->prime == NULL)
    {
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Nenhum funcionario cadastrado!");
        getch();
        gotoxy(8, 23);
        printf("                                                       ");
        return 0;
    }

    // Remoção do primeiro funcionário
    if (opc == 4)
    {
        Mostrar_Tel(l->prime);
        gotoxy(8, 23);
        printf("Deseja realmente apagar os dados (Sim = 1/Nao = 0): ");
        scanf("%d", &test);

        if (test == 1)
        {
            if (l->prime->proxi == NULL)
            {
                free(l->prime);
                l->prime = NULL;
                l->ult = NULL;
            }
            else
            {
                P = l->prime;
                l->prime = P->proxi;
                free(P);
            }
        }
        return 0;
    }

    // Remoção do último funcionário
    else if (opc == 5)
    {
        if (l->prime->proxi == NULL)
        {
            free(l->prime);
            l->prime = NULL;
            l->ult = NULL;
        }
        else
        {
            aux = l->prime;
            P = aux->proxi;

            // Percorre a lista até encontrar o penúltimo funcionário
            while (P->proxi != NULL)
            {
                aux = P;
                P = P->proxi;
            }

            Mostrar_Tel(l->prime);
            gotoxy(8, 23);
            printf("Deseja realmente apagar os dados (Sim = 1/Nao = 0): ");
            scanf("%d", &test);

            if (test == 1) // Confirmação de exclusão
            {
                free(P);
                aux->proxi = NULL;
                l->ult = aux;
            }

            else
            {

                return 0;  // Caso o usuário opte por não excluir, a função termina
            }
        }
        return 0;  // Finaliza a função
    }

    // Remoção de um funcionário em uma posição específica
    else if (opc == 6)
    {
        do
        {
            gotoxy(8, 23);
            printf("                                                       ");
            gotoxy(8, 23);
            printf("Digite a posicao que deseja apagar: ");
            scanf("%d", &posi);
            gotoxy(8, 23);
            printf("                                                       ");

            quant = Contad(l); // Conta quantos funcionários existem na lista

            // Verifica se a posição é válida
            if (posi < 1 || posi > quant)
            {
                gotoxy(8, 23);
                printf("                                                       ");
                gotoxy(8, 23);
                printf("Posicao invalida. Tente novamente!");
                getch();
                gotoxy(8, 23);
                printf("                                                       ");
            }

        } while (posi < 1 || posi > quant); // Repete até que uma posição válida seja fornecida

        // Se a posição for a primeira
        if (posi == 1)
        {
            Mostrar_Tel(l->prime); // Exibe os dados do primeiro funcionário
            gotoxy(8, 23);
            printf("Deseja realmente apagar os dados (Sim = 1/Nao = 0): ");
            scanf("%d", &test);

            if (test == 1) // Confirmação de exclusão
            {
                aux = l->prime;
                l->prime = l->prime->proxi;
                free(aux);

                // Se a lista ficar vazia, ajusta o ponteiro do último
                if (l->prime == NULL)
                {
                    l->ult = NULL;
                }

                return 0;
            }
            else
            {
                return 0;
            }
        }

         // Se a posição for intermediária ou a última
        else
        {
            aux = l->prime;
            P = aux->proxi;
            conta = 1;

            // Avança até a posição desejada
            while (conta < posi - 1 && P != NULL)
            {
                conta++;
                aux = P;
                P = P->proxi;
            }

            // Se encontrar a posição, remove o funcionário
            if (P != NULL)
            {
                Mostrar_Tel(P);
                gotoxy(8, 23);
                printf("Deseja realmente apagar os dados (Sim = 1/Nao = 0): ");
                scanf("%d", &test);

                if (test == 1)
                {
                    aux->proxi = P->proxi;
                    free(P);

                     // Se o último funcionário for removido, ajusta o ponteiro do último
                    if (aux->proxi == NULL)
                    {
                        l->ult = aux;
                    }
                }
            }
        }
    }

    // Finaliza a função
    return 0;
}

void gravArqui(tipoLista *l)
{
    FILE *arquivo = fopen("folha.dat", "wb"); // Abre ou cria um arquivo para escrita em modo binário
    if (arquivo == NULL)
    {
        gotoxy(8, 23);
        printf("Não foi possivel abrir o arquivo!");
        getch();
        return;
    }

    tipoApontador P = l->prime; // Inicia o ponteiro P no primeiro elemento da lista
    while (P != NULL)
    {
        fwrite(&(P->conte), sizeof(reg_funci), 1, arquivo); // Escreve os dados do funcionário no arquivo
        P = P->proxi;
    }

    fclose(arquivo); // Fecha o arquivo
}

void lerArqui(tipoLista *l)
{
    // Tenta criar o arquivo se não existir
    FILE *arquivo = fopen("folha.dat", "rb");
    if (arquivo == NULL)
    {

        arquivo = fopen("folha.dat", "wb");
        if (arquivo == NULL)
        {
            gotoxy(8, 23);
            printf("Erro ao criar o arquivo!"); // Mensagem de erro se não for possível criar o arquivo
            getch();
            getch();
            return;
        }
        fclose(arquivo); // Fecha o arquivo criado

        arquivo = fopen("folha.dat", "rb");
        if (arquivo == NULL)
        {
            gotoxy(8, 23);
            printf("Erro ao abrir o arquivo para leitura!");
            getch();
            return;
        }
    }

    reg_funci conte;
    while (fread(&conte, sizeof(reg_funci), 1, arquivo)) // Lê os dados do arquivo
    {
        tipoApontador novo = (tipoApontador)malloc(sizeof(tipoItem));
        novo->conte = conte;
        novo->proxi = NULL;

        if (l->prime == NULL)
        {
            l->prime = novo;
            l->ult = novo;
        }
        else
        {
            l->ult->proxi = novo;
            l->ult = novo;
        }
    }

    fclose(arquivo);
}

int main()
{

    int opc;
    tipoLista lista;
    lista.prime = NULL;
    lista.ult = NULL;

    lerArqui(&lista); // Lê os dados do arquivo e carrega na lista

    do
    {
        // Exibe as opções disponíveis para o usuário
        YaTela();
        gotoxy(29, 3);
        printf("CADASTRO DE FUNCIONARIOS");

        gotoxy(29, 5);
        printf("1 - Cadastrar no final da lista");

        gotoxy(29, 7);
        printf("2 - Cadastrar no inicio da lista");

        gotoxy(29, 9);
        printf("3 - Cadastrar em alguma posicao da lista ");

        gotoxy(29, 11);
        printf("4 - Remover do inicio da lista");

        gotoxy(29, 13);
        printf("5 - Remover do final da lista");

        gotoxy(29, 15);
        printf("6 - Remover de alguma posicao da lista");

        gotoxy(29, 17);
        printf("7 - Alterar dados");

        gotoxy(29, 19);
        printf("8 - Consultar funcionarios");

        gotoxy(29, 21);
        printf("9 - Sair");

        gotoxy(8, 23);
        printf("Digite a opcao desejada: ");
        scanf("%d", &opc);

        // Verifica se a opção está dentro dos limites válidos
        if (opc > 9 || opc <= 0)
        {

            gotoxy(8, 23);
            printf("                                                              ");
            gotoxy(8, 23);
            printf("Entrada invalida! Digite um numero entre 1 e 9.");
            getch();
            gotoxy(8, 23);
            printf("                                                              ");
        }
        else
        {

            switch (opc)
            {
            case 1:
                Cadast(&lista, opc); // Cadastra no final da lista
                gravArqui(&lista); // Grava no arquivo
                break;
            case 2:
                Cadast(&lista, opc); // Cadastra no início da lista
                gravArqui(&lista); // Grava no arquivo
                break;
            case 3:
                Cadast(&lista, opc); // Cadastra em uma posição específica
                gravArqui(&lista); // Grava no arquivo
                break;
            case 4:
                Remov(&lista, opc); // Remove do início da lista
                gravArqui(&lista); // Grava no arquivo
                break;
            case 5:
                Remov(&lista, opc); // Remove do final da lista
                gravArqui(&lista); // Grava no arquivo
                break;
            case 6:
                Remov(&lista, opc); // Remove de uma posição específica
                gravArqui(&lista); // Grava no arquivo
                break;
            case 7:
                Alterar_Dad(&lista); // Altera dados de um funcionário
                gravArqui(&lista); // Grava no arquivo
                break;
            case 8:
                Consult(&lista); // Consulta funcionários
                break;
            case 9:
                gotoxy(8, 23);
                printf("                                          ");
                gotoxy(8, 23);
                printf("Saindo...\n\n");
                break;
            }
        }

    } while (opc != 9); // Continua até que o usuário escolha sair

    return 0; // Finaliza o programa
}
