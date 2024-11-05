//Renatao

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "tela.c"

typedef struct
{
    int codigo;
    char nome[50];
    char endereco[50];
    char cargo[50];
    char dt_adimissao[11];
    char telefone[15];
    float salario;

} reg_funcionario;

typedef struct Tipoitem *tipoapontador;

typedef struct Tipoitem
{

    reg_funcionario conteudo;
    tipoapontador prox;
} Tipoitem;

typedef struct
{
    tipoapontador primeiro;
    tipoapontador ultimo;

} tipolista;

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

// fucao que realiza a contagem
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

// Monta os campos da tela
void tela_func()
{
    tela();
    gotoxy(29, 3);

    printf("CADASTRO DE CLIENTES");

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

// funcao que mostra os valores da lista
void amostra(tipoapontador p)
{
    tela_func();
    gotoxy(50, 7);
    printf("%d", p->conteudo.codigo);

    gotoxy(50, 9);
    printf("%s", p->conteudo.nome);

    gotoxy(50, 11);
    printf("%s", p->conteudo.endereco);

    gotoxy(50, 13);
    printf("%s", p->conteudo.cargo);

    gotoxy(50, 15);
    printf("%s", p->conteudo.dt_adimissao);

    gotoxy(50, 17);
    printf("%s", p->conteudo.telefone);

    gotoxy(50, 19);
    printf("%.2f", p->conteudo.salario);
}

// funcao que cadastra nas posicoes
int cadastro(tipolista *l, int opc)
{

    int teste;
    int pos;
    int qtd;
    reg_funcionario cont;
    tipoapontador p;
    tipoapontador aux;
    tipoapontador aux2;

    // validacao de cadastrar novamente
    do
    {

        tela();
        tela_func();

        // validacao para sair com o 0
        do
        {

            gotoxy(8, 23);
            printf("Digite \"0\" para sair");
            gotoxy(50, 7);
            printf("                 ");
            gotoxy(50, 7);
            scanf("%d", &cont.codigo);

            if (cont.codigo == 0)
            {

                gotoxy(8, 23);
                printf("Deseja realmente sair (Sim = 1/Nao = 0): ");
                scanf("%d", &teste);
                gotoxy(8, 23);
                printf("                                            ");
                gotoxy(8, 23);

                if (teste == 1)
                {
                    return 0;
                }
            }

            aux = pesquisa(l, cont.codigo); // chama funcao para ver se tem um codigo com aql valor

            // caso nao tenha, ele ira retornar null e pedira entrada de dados novamente
            if (aux != NULL)
            {

                gotoxy(8, 23);
                printf("Digite um codigo nao digitado anteriormente");
                getch();
                gotoxy(8, 23);
                printf("                                            ");
            }

        } while (aux != NULL || cont.codigo == 0);

        // entrada de dados

        gotoxy(8, 23);
        printf("                                                   ");

        gotoxy(50, 9);
        fflush(stdin);
        fgets(cont.nome, 50, stdin);

        gotoxy(50, 11);
        fflush(stdin);
        fgets(cont.endereco, 50, stdin);

        gotoxy(50, 13);
        fflush(stdin);
        fgets(cont.cargo, 50, stdin);

        gotoxy(50, 15);
        fflush(stdin);
        fgets(cont.dt_adimissao, 11, stdin);

        gotoxy(50, 17);
        fflush(stdin);
        fgets(cont.telefone, 15, stdin);

        gotoxy(50, 19);
        scanf("%f", &cont.salario);

        gotoxy(8, 23);
        printf("                                        ");
        gotoxy(8, 23);
        printf("Deseja gravar (Sim = 1/Nao = 0): ");
        scanf("%d", &teste);
        gotoxy(8, 23);
        printf("                               ");

        // verifica se deseja cadastrar outro funcionario
        if (teste == 1)
        {

            // cria o no p

            p = (tipoapontador)malloc(sizeof(Tipoitem));

            p->prox = NULL;

            p->conteudo = cont;

            // adiciona no final
            if (opc == 1)
            {

                if (l->primeiro == NULL)
                {
                    l->primeiro = p;
                    l->ultimo = p;
                }
                else
                {
                    l->ultimo->prox = p;
                    l->ultimo = p;
                }
            } // adiciona no inicio
            else if (opc == 2)
            {

                if (l->primeiro == NULL)
                {
                    l->primeiro = p;
                    l->ultimo = p;
                }
                else
                {
                    p->prox = l->primeiro;
                    l->primeiro = p;
                }
            } //insere na posicao desejada
            else if (opc == 3)
            {
                do
                {
                    gotoxy(8, 23);
                    printf("                                                       ");
                    gotoxy(8, 23);
                    printf("Digite a posicao a ser inserida: ");
                    scanf("%d", &pos);
                    gotoxy(8, 23);
                    printf("                                                       ");

                    qtd = contador(l);

                    if (pos == 1)
                    {
                        qtd = 1;

                        if (l->primeiro == NULL)
                        {
                            l->primeiro = p;
                            l->ultimo = p;
                        }
                        else
                        {
                            p->prox = l->primeiro;
                            l->primeiro = p;
                        }
                    }
                    else if (pos > qtd || pos < 1)
                    {
                        gotoxy(8, 23);
                        printf("                                                       ");
                        gotoxy(8, 23);
                        printf("Posicao invalida");
                        getch();
                        gotoxy(8, 23);
                        printf("                                                       ");
                    }

                } while (pos > qtd || pos < 1);

                if (pos != 1)
                {
                    aux2 = l->primeiro;

                    for (int x = 1; x <= pos - 2; x++)
                    {
                        aux2 = aux2->prox;
                    }

                    p->prox = aux2->prox;

                    aux2->prox = p;
                }
            }

            gotoxy(8, 23);
            printf("                                                       ");
            gotoxy(8, 23);
            printf("Deseja cadastrar outro funcionario? (Sim = 1/Nao = 0): ");
            scanf("%d", &teste);
            gotoxy(8, 23);
            printf("                                                       ");
        }
    } while (teste == 1);

    return 0;
}

//funcao para alterar um cadastro especifico
int alterar(tipolista *l)
{
    int pos;
    int campo;
    reg_funcionario cont;
    tipoapontador p;
    tipoapontador aux;


    //verifica se tem algum valor 
    if (l->primeiro == NULL)
    {
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Nao ha nenhum valor para alterar");
        getch();
        gotoxy(8, 23);
        printf("                                                       ");

        return 0;
    }
    tela();
    tela_func();
    do
    {//faz a entrada de qual codigo do funcionario sera alterado
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Digite o codigo do funcionario a ser alterado: ");
        scanf("%d", &pos);
        gotoxy(8, 23);
        printf("                                                       ");

        aux = pesquisa(l, pos);

        if (aux == NULL)
        {
            gotoxy(8, 23);
            printf("                                                       ");
            gotoxy(8, 23);
            printf("Posicao invalida");
            getch();
            gotoxy(8, 23);
            printf("                                                       ");
        }

    } while (aux == NULL);

    amostra(aux);
    do
    {//faz a entrada de dado de qual campo sera alterado 
        gotoxy(8, 23);
        printf("                                        ");
        gotoxy(8, 23);
        printf("Deseja alterar qual campo ?(0 para sair)");
        scanf("%d", &campo);
        gotoxy(8, 23);
        printf("                                         ");

        if (campo < 0 || campo > 6)
        {
            gotoxy(8, 23);
            printf("                                        ");
            gotoxy(8, 23);
            printf("Campo invalido!");
            getch();
            gotoxy(8, 23);
            printf("                                         ");
        }

    } while (campo < 0 || campo > 6);


    //valida se a entrada eh diferente de 0, caso for ele faz a entrada de dados no campo escolhido
    if (campo != 0)
    {
        cont = aux->conteudo;

        switch (campo)
        {
        case 1:

            gotoxy(50, 9);
            printf("                            ");
            gotoxy(50, 9);
            fflush(stdin);
            fgets(cont.nome, 50, stdin);

            break;

        case 2:

            gotoxy(50, 11);
            printf("                            ");
            gotoxy(50, 11);
            fflush(stdin);
            fgets(cont.endereco, 50, stdin);

            break;
        case 3:

            gotoxy(50, 13);
            printf("                            ");
            gotoxy(50, 13);
            fflush(stdin);
            fgets(cont.cargo, 50, stdin);
            break;

        case 4:

            gotoxy(50, 15);
            printf("                            ");
            gotoxy(50, 15);
            fflush(stdin);
            fgets(cont.dt_adimissao, 11, stdin);

            break;
        case 5:

            gotoxy(50, 17);
            printf("                            ");
            gotoxy(50, 17);
            fflush(stdin);
            fgets(cont.telefone, 15, stdin);

            break;
        case 6:

            gotoxy(50, 19);
            printf("                            ");
            gotoxy(50, 19);
            scanf("%f", &cont.salario);

            break;

        default:
            break;
        }

        //realiza a alteracao

        p = (tipoapontador)malloc(sizeof(Tipoitem));

        p->conteudo = cont;

        if (pos == 1)
        {

            p->prox = l->primeiro->prox;
            l->primeiro = p;
        }

        aux->conteudo = p->conteudo;
    }

    return 0;
}

// comentar as funcoes:  estou comentando neste exato momento

//Funcao pra mostrar os valores armazenados 
int listarFun(tipolista *l)
{
    if (l->primeiro == NULL)
    {
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Nao ha nenhum valor para ler");
        getch();
        gotoxy(8, 23);
        printf("                                                       ");

        return 0;
    }

    tipoapontador p;

    p = l->primeiro;

    while (p != NULL)
    {
        amostra(p);

        p = p->prox;
        getch();
    }

    return 0;
}

//Funcao que realiza as remocoes
int remover(tipolista *l, int opc)
{
    tipoapontador p;
    tipoapontador aux;
    int teste;
    int cont;
    int pos;
    int qtd;

    //verifica se ha valor pra remover
    if (l->primeiro == NULL)
    {
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Nao ha nenhum valor para remover");
        getch();
        gotoxy(8, 23);
        printf("                                                       ");

        return 0;
    }

    //remover no inicio
    if (opc == 4)
    {

        amostra(l->primeiro);


        //verifica se realmente ira excluir
        gotoxy(8, 23);
        printf("                                        ");
        gotoxy(8, 23);
        printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
        scanf("%d", &teste);
        gotoxy(8, 23);
        printf("                               ");

        //verifica se o dado escolhido e o primeiro, pois o tratamento sera diferente
        if (teste == 1)
        {

            if (l->primeiro->prox == NULL)
            {

                free(l->primeiro);
                l->primeiro = NULL;
                l->ultimo = NULL;
            }
            else
            {
                p = l->primeiro;
                l->primeiro = p->prox;
                free(p);
            }
        }
        else
        {

            return 0;
        }
    }
    else if (opc == 5)//exclui no final
    {

        if (l->primeiro->prox == NULL)
        {

            free(l->primeiro);
            l->primeiro = NULL;
            l->ultimo = NULL;
        }
        else
        {
            aux = l->primeiro;
            p = aux->prox;

            while (p->prox != NULL)
            {
                p = p->prox;
                aux = aux->prox;
            }
        }

        amostra(p);

        gotoxy(8, 23);
        printf("                                        ");
        gotoxy(8, 23);
        printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
        scanf("%d", &teste);
        gotoxy(8, 23);
        printf("                               ");

        if (teste == 1)
        {

            free(p);
            aux->prox = NULL;
            l->ultimo = aux;
        }
        else
        {
            return 0;
        }
    }
    else if (opc == 6)//exclui na posicao desejada
    {
        do
        {
            gotoxy(8, 23);
            printf("                                                       ");
            gotoxy(8, 23);
            printf("Digite a posicao a ser apagada: ");
            scanf("%d", &pos);
            gotoxy(8, 23);
            printf("                                                       ");

            qtd = contador(l);

            if (pos > qtd || pos < 1)
            {
                gotoxy(8, 23);
                printf("                                                       ");
                gotoxy(8, 23);
                printf("Posicao invalida");
                getch();
                gotoxy(8, 23);
                printf("                                                       ");
            }

        } while (pos > qtd || pos < 1);

        if (pos == 1)
        {
            amostra(l->primeiro);

            gotoxy(8, 23);
            printf("                                        ");
            gotoxy(8, 23);
            printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
            scanf("%d", &teste);
            gotoxy(8, 23);
            printf("                               ");

            if (teste == 1)
            {
                p = l->primeiro;
                l->primeiro = l->primeiro->prox;
                free(p);

                if (l->primeiro == NULL)
                {
                    l->ultimo = NULL;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            aux = l->primeiro;
            p = aux->prox;
            cont = 1;

            while (cont < pos - 1 && p != NULL)
            {
                cont++;
                aux = p;
                p = p->prox;
            }

            if (p != NULL)
            {
                amostra(p);

                gotoxy(8, 23);
                printf("                                        ");
                gotoxy(8, 23);
                printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
                scanf("%d", &teste);
                gotoxy(8, 23);
                printf("                               ");

                if (teste == 1)
                {
                    aux->prox = p->prox;
                    free(p);

                    if (aux->prox == NULL)
                    {
                        l->ultimo = aux;
                    }
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    return 0;
}

//funcao pra gravar o arquivo no folha.dat
void gravarArquivo(tipolista *l)
{
    FILE *arquivo = fopen("folha.dat", "wb"); // Abre o arquivo para escrita binária
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
//funcao para ler o arquivo folha.dat
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

int main()
{

    int opcao;

    tipolista l;

    l.primeiro = NULL;
    l.ultimo = NULL;

    lerArquivo(&l);

    do
    {
        // Construção da tela

        tela();

        gotoxy(29, 3);
        printf("CADASTRO DE CLIENTES");

        gotoxy(29, 5);
        printf("1-Cadastrar no final da lista ");

        gotoxy(29, 7);
        printf("2-Cadastrar no comeco da lista ");

        gotoxy(29, 9);
        printf("3-Cadastrar em uma posicao da lista ");

        gotoxy(29, 11);
        printf("4-Remover no inicio da lista");

        gotoxy(29, 13);
        printf("5-Remover no final da lista");

        gotoxy(29, 15);
        printf("6-Remover em uma posicao da lista ");

        gotoxy(29, 17);
        printf("7-Alteracao do Cadastro de Funcionario");

        gotoxy(29, 19);
        printf("8-Consultar");

        gotoxy(29, 21);
        printf("9-Sair");

        gotoxy(8, 23);
        printf("Digite o numero da opcao desejada: ");

        // Leitura de dados
        gotoxy(43, 23);
        scanf("%d", &opcao);

        // Verificando se a opcao escolhida eh valida
        if (opcao > 9 || opcao <= 0)
        {
            gotoxy(8, 23);
            printf("                                        ");
            gotoxy(8, 23);
            printf("Digite um valor valido (1 a 8)");
            getch();
            gotoxy(8, 23);
            printf("                               ");
        }

        // Trabalhando a opcao escolhida
        switch (opcao)
        {
        case 1:
            cadastro(&l, opcao);
            gravarArquivo(&l);

            break;

        case 2:
            cadastro(&l, opcao);
            gravarArquivo(&l);

            break;

        case 3:
            cadastro(&l, opcao);
            gravarArquivo(&l);

            break;

        case 4:
            remover(&l, opcao);
            gravarArquivo(&l);

            break;

        case 5:
            remover(&l, opcao);
            gravarArquivo(&l);

            break;

        case 6:
            remover(&l, opcao);
            gravarArquivo(&l);

            break;

        case 7:
            alterar(&l);
            gravarArquivo(&l);

            break;

        case 8:
            listarFun(&l);
            break;

        case 9:
            gravarArquivo(&l);

        default:
            break;
        }

    } while (opcao != 9);

    gotoxy(37, 25);

    return 0;
}
