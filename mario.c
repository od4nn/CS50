#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Loop para certificar de que o usuário não digite um número menor que 3 e maior que 8
    int altura = 0;
    do
    {
        altura = get_int("Altura: ");
    }
    while (altura < 3 || altura > 8);

    // Loop responsavel por implementar cada linha de #
    for (int i = 0; i < altura; i++)
    {
        // Loop responsavel pelos espaços, começa com muitos e vão diminuindo, fazendo com que a pirâmide se alinhe a direita
        for (int j = 0; j < altura - i - 1; j++)
        {
          printf(" ");
        }

        // Imprime os #, o loop de k começa de 0 a cada linha e imprime mais # conforme o valor de i aumenta
        for (int k = 0; k <= i; k++)
        {
          printf("#");
        }

        // Depois de executar os espaços e os #, o loop principal vai dar um espaço para o programa ir para a próxima linha até chegar no numero que o usuario digitou no caso a altura
        printf("\n");
    }

}
