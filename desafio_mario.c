#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int altura;

    // Certifica de que o usuário digite somente um número de 1 a 8
    do
    {
       altura = get_int("Altura: ");
    }
    while (altura > 8 || altura < 1);

    // Loop responsável por decidir a altura da piramide
    for (int i = 0; i < altura; i++)
    {
        // Loop responsável por colocar os espaços da primeira piramide que fica alinhada a direita
        for (int k = 0; k <= altura - i - 1; k++)
        {
            printf(" ");
        }

        // Coloca os # na piramide 1 em cada linha de acordo com o tamanho escolhido
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Espaço para separar as piramides
        printf("  ");

        // Faz a pirâmide 2, essa é alinhada a esquerda logo não precisa de espaços
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }

        // Depois de cada incrementação em i ele salta uma linha assim a piramide vai sendo construida linha a linha
        printf("\n");
    }
}

