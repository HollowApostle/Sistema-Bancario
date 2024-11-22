#include "Funcoes.h"

int bissexto(int ano){

    if (ano % 4 == 0) {
        if (ano % 100 != 0 || ano % 400 == 0) {
            return 1; // Ano é bissexto
        }
    }
    return 0; // Ano não é bissexto

}

int comparar_datas(const char* data1, const char* data2) {
    // Comparar as duas datas no formato yyyyMMdd
    return strcmp(data1, data2);
}

int validar_data(const char* data, TipoLista_movim *m) { 
    int dia, mes, ano;
    int dias_no_mes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Separar a string em dia, mês e ano
    int partes_lidas = sscanf(data, "%2d/%2d/%2d", &dia, &mes, &ano);
    if (partes_lidas != 3) {
        return 0; // Formato inválido
    }

    // Ajustar o ano para considerar século 20 ou 21
    if (ano < 50) {
        ano += 2000;
    } else {
        ano += 1900;
    }

    // Verificar se o mês é válido
    if (mes < 1 || mes > 12) {
        return 0; // Mês inválido
    }

    // Ajustar os dias de fevereiro para anos bissextos
    if (mes == 2 && bissexto(ano)) {
        dias_no_mes[1] = 29;
    }

    // Verificar se o dia é válido para o mês
    if (dia < 1) {
        return 0; // Dia inválido (menor que 1)
    }
    if (dia > dias_no_mes[mes - 1]) {
        return 0; // Dia inválido (maior que o permitido no mês)
    }

    // Transformar a data inserida no formato yyyymmdd
    char data_invertida[9];
    sprintf(data_invertida, "%04d%02d%02d", ano, mes, dia);

    // Obter a data da última movimentação no formato dd/mm/yyyy e transformá-la
    char ultima_data[9];
    int ult_dia, ult_mes, ult_ano;

    // Supomos que m.ultimo->conteudo.dt_movimento esteja no formato dd/mm/yyyy
    sscanf(m->ultimo->conteudo.dt_movimento, "%2d/%2d/%4d", &ult_dia, &ult_mes, &ult_ano);

    // Ajustar o ano para considerar século 20 ou 21
    if (ult_ano < 50) {
        ult_ano += 2000;
    } else {
        ult_ano += 1900;
    }

    // Transformar a última data no formato yyyymmdd
    sprintf(ultima_data, "%04d%02d%02d", ult_ano, ult_mes, ult_dia);

    // Comparar as datas
    if (comparar_datas(data_invertida, ultima_data) > 0) {
        return 1; // Data inserida é posterior à última movimentação
    } else {
        return 0; // Data inserida é anterior ou igual à última movimentação
    }
}