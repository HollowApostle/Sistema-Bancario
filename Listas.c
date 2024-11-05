typedef struct
{
    int codigo;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];
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
