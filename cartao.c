#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

long luhn(void);

int main(void)
{
    // Chama o algoritmo e executa ele, usando o long n_v para atribuir o valor de luhn para ele
    long n_verificado = luhn();
    long prefixo = n_verificado;
    while (prefixo >= 100)
    {
        prefixo /= 10;
    }
    
    if (prefixo == 34 || prefixo == 37)
    {
        printf("AEXPRESS\n");
    }

    else if (prefixo == 51 || prefixo == 52 || prefixo == 53 || prefixo == 54 || prefixo == 55)
    {
        printf("MASTERCARD\n");
    }

    else if ((prefixo / 10) == 4)
    {
        printf("VISA\n");
    }
}

long luhn(void)
{
    // declara variaveis aqui para não ter problema de sumir valores depois do loop
    int i = 0;
    long cartao_original;
    long cartao;
    do
    {
        i = 0;
        cartao = get_long("Digite o numero do cartão: ");
        // atribui o valor de cartão para outra variavel para não perder o valor original
        cartao_original = cartao;

        // Conta quantos numeros o cartão tem, para verificar se é um numero valido
        while (cartao > 0)
        {
            cartao = cartao / 10;
            i++;
        }

    }

    while (i < 13 || i > 19);
    // declara variaveis
    long cartao_verif = cartao_original;
    int digito_soma = 0;
    int contador = 0;
    // variavel onde vai ficar guardada os numeros do cartao a cada loop, e mesmo fora dele, para que seja possivel usar o algoritmo de luhn mais tarde
    int digito_temp;
    while (cartao_original > 0)
    {
       // o ultimo digito do numero
       int digito = cartao_original % 10;
       cartao_original /= 10;
       // se a posição for par de trás para frente dobra o numero
       if (contador % 2 == 1)
       {
            // se for par, dobra, se o numero dobrado for maior que 9 diminui 9
            digito *= 2;
            if (digito > 9)
            {
                digito -= 9;
            }
       }
        // soma o total
        digito_soma += digito;
        // incrementa a posição do numero
        contador++;
    }
    if (digito_soma % 10 == 0)
    {
         printf("O cartão é válido!\n");
         return cartao_verif;
    }
    else
    {
         printf("O cartão é invalido!\n");
         // retorna 0 para indicar que não é valido
         exit (0);
    }

}


