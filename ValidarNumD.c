#include "Funcoes.h"

double validarNumD(char *mensagem, int x, int y)
{
    char buffer[50];
    float valor;
    int resultado;

    do
    {
        gotoxy(x, y);
        printf("                                                    ");
        gotoxy(x, y);
        printf("%s", mensagem);

        fflush(stdin);

        fgets(buffer, sizeof(buffer), stdin);

        resultado = sscanf(buffer, "%lf", &valor); // Converte a string para double

        size_t length = strlen(buffer);

        if (buffer[length - 1] == '\n')
        {
            buffer[length - 1] = '\0';
        }

        // Verifica se a conversão falhou (quando não há dígitos válidos)
        if (resultado != 1 || valor <= 0)
        {
            gotoxy(8, 23);
            printf("Entrada invalida, tente novamente (somente numeros positivos).");
            getch();
            gotoxy(8, 23);
            printf("                                                               ");
        }


    } while (resultado != 1 || valor <= 0); // Verifica se a entrada foi válida

    return valor;
}