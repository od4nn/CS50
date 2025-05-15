#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n1 = get_int("Digite o primeiro número: ");
    int n2 = get_int("Digite o segundo número: ");
    char sinal = get_char("Digite um sinal: ");

    if (sinal == '+')
    {
        printf("= %i\n", n1 + n2);
    }

    else if (sinal == '-')
    {
        printf("= %i\n", n1 - n2);
    }

    else if (sinal == '*')
    {
        printf("= %i\n", n1 * n2);
    }

    else if (sinal == '/')
    {
        printf("= %i\n", n1 / n2);
    }
}
