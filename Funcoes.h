#ifndef FUNCOES_H
#define FUNCOES_H

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int codigo;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;

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

typedef struct 
{
    int sequencial;
    int codigo_conta;
    char dt_movimento[11];
    char tp_movimento[15];
    char ds_favorecido[50];
    float vl_movimento;
    float vl_saldo;

}reg_movimentos;

typedef struct Tipoitem_movim *tipoapontador_movim;

typedef struct
{
    tipoapontador_movim primeiro;
    tipoapontador_movim ultimo;

}TipoLista_movim;



#endif

