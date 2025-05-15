#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Pega o valor do troco do cliente
    float s;
    do
    {
       s = get_float("Digite um troco em dolar: ");
    }
    while (s < 0 );

    int centavos = (s * 100 );

    // Calculando quantas moedas são necessarias para o troco
    int moedas = 0;
    while (centavos >= 25)
    {
         centavos = centavos - 25;
         moedas++;
    }
    while (centavos >= 10)
    {
        centavos = centavos - 10;
        moedas++;
    }
    while (centavos >= 5)
    {
        centavos = centavos - 5;
        moedas++;
    }
    while (centavos >= 1)
    {
        centavos = centavos - 1;
        moedas++;
    }

    // Mostrando quantas moedas o cliente deve receber
    printf("%d\n", moedas);
}
