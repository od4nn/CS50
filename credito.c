#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

void verificar(char CREDITO[], int comprimento); // Função que verifica a validade do cartão

int main(void)
{
    char CREDITO[20];
    long cartao;
    int comprimento;

    // Recebe o número do cartão e verifica se é positivo
    do
    {
        cartao = get_long("Digite o número do cartão: ");
    }
    while (cartao < 0);

    // Converte o número do cartão em uma string para facilitar o acesso aos dígitos
    sprintf(CREDITO, "%li", cartao);
    comprimento = strlen(CREDITO);

    // Verifica se o número do cartão é válido com o algoritmo de Luhn
    verificar(CREDITO, comprimento);

    // Verifica se o número do cartão é válido para AMEX
    if ((comprimento == 15) && ((CREDITO[0] == '3' && CREDITO[1] == '4') || (CREDITO[0] == '3' && CREDITO[1] == '7')))
    {
        printf("AMEX\n");
    }

    // Verifica se o número do cartão é válido para MasterCard
    else if ((comprimento == 16) && ((CREDITO[0] == '5' && CREDITO[1] == '1') || (CREDITO[0] == '5' && CREDITO[1] == '2') || (CREDITO[0] == '5' && CREDITO[1] == '3') || (CREDITO[0] == '5' && CREDITO[1] == '4') || (CREDITO[0] == '5' && CREDITO[1] == '5')))
    {
        printf("MASTERCARD\n");
    }

    // Verifica se o número do cartão é válido para VISA
    else if ((comprimento >= 13) && (comprimento <= 16) && (CREDITO[0] == '4'))
    {
        printf("VISA\n");
    }

    else
    {
        printf("O número do cartão não é válido.\n");
    }

    return 0;
}

// Função para verificar a validade do cartão usando o algoritmo de Luhn
void verificar(char CREDITO[], int comprimento)
{
    int soma = 0;

    // Lógica para aplicar o algoritmo de Luhn, começando do penúltimo dígito
    for (int i = comprimento - 2; i >= 0; i -= 2)
    {
        int digito = CREDITO[i] - '0'; // Converte o caractere para o número correspondente
        int multiplicado = digito * 2;

        // Se o produto for maior que 9, somamos os dígitos do número
        if (multiplicado > 9)
        {
            soma += multiplicado - 9;
        }
        else
        {
            soma += multiplicado;
        }
    }

    // Soma os dígitos que não foram multiplicados
    for (int i = comprimento - 1; i >= 0; i -= 2)
    {
        int digito = CREDITO[i] - '0'; // Converte o caractere para o número correspondente
        soma += digito;
    }

    // Verifica se o número é válido com o algoritmo de Luhn
    if (soma % 10 != 0)
    {
        printf("O número do cartão não é válido.\n"); 
        exit(0); // Encerra o programa se o cartão for inválido
    }
}
