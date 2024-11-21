
#include "Funcoes.h"

int cadastro(tipolista *l, int opc)
{

    int teste;
    int testeOPC;
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
        tela_conta();

        // validacao para sair com o 0
        do
        {

            gotoxy(8, 23);
            printf("Digite \"0\" para sair");
            gotoxy(51, 7);
            printf("                 ");
            gotoxy(51, 7);
            scanf("%d", &cont.codigo);

            if (cont.codigo == 0)
            {

                gotoxy(8, 23);
                printf("Deseja realmente sair (Sim = 1/Nao = 2): ");
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

        getchar();
        gotoxy(8, 23);
        printf("                                                   ");

        gotoxy(51, 9);
        fflush(stdin);
        fgets(cont.banco, 50, stdin);

        gotoxy(51, 11);
        fflush(stdin);
        fgets(cont.agencia, 10, stdin);

        gotoxy(51, 13);
        fflush(stdin);
        fgets(cont.numero_conta, 20, stdin);

        do
        {
            gotoxy(8, 23);
            printf("Utilizar: 1=Corrente / 2=Poupanca / 3=Cartao Credito: ");
            scanf("%d", &testeOPC);

            
            if (testeOPC < 1 || testeOPC > 3)
            {
                gotoxy(8, 23);
                printf("Opcao invalida. Escolha entre 1, 2 ou 3.               ");
                getch(); 
                gotoxy(8, 23);
                printf("                                                       "); 
            }
            else
            {
                
                switch (testeOPC)
                {
                case 1: 
                    strcpy(cont.tipo_conta, "Corrente");
                    gravarArquivo(l);
                    break;

                case 2: 
                    strcpy(cont.tipo_conta, "Poupanca");
                    gravarArquivo(l);
                    break;

                case 3: 
                    strcpy(cont.tipo_conta, "Cartao Credito"); 
                    gravarArquivo(l);
                    break;
                }
            }
        } while (testeOPC < 1 || testeOPC > 3);

        gotoxy(51, 17);
        fflush(stdin);
        scanf("%lf", &cont.vl_saldo);

        gotoxy(51, 19);
        scanf("%lf", &cont.vl_limite);

        strcpy(cont.status, "Ativo");

        gotoxy(8, 23);
        printf("                                        ");
        gotoxy(8, 23);
        printf("Deseja gravar (Sim = 1/Nao = 2): ");
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
            } // insere na posicao desejada
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
            printf("Deseja cadastrar outra conta? (Sim = 1/Nao = 2): ");
            scanf("%d", &teste);
            gotoxy(8, 23);
            printf("                                                       ");
        }
    } while (teste == 1);

    return 0;
}