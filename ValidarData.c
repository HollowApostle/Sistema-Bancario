#include "Funcoes.h"

int bissexto(int ano){

    if (ano % 4 == 0) {
        if (ano % 100 != 0 || ano % 400 == 0) {
            return 1; // Ano é bissexto
        }
    }
    return 0; // Ano não é bissexto

}

int validar_data(const char* data) {
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

    return 1; // Data válida
}