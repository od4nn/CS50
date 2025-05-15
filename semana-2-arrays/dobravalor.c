#include <stdio.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int dados[5];

    // Inicializa o primeiro valor
    dados[0] = 1;

    // Preenche os outros valores do array
    for (int i = 1; i < 5; i++) // Começa de i = 1, pois dados[0] já está inicializado
    {
        dados[i] = dados[i-1] * 2; // Dobra o valor anterior
    }

    // Imprime o conteúdo do array
    for (int i = 0; i < 5; i++)
    {
        printf("%i ", dados[i]);
    }

    return 0;
}
