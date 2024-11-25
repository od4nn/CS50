#include <cs50.h>
#include <stdio.h>

const int MEDIA = 3;
float average(int length, int array[]);

int main(void)
{
     //Pergunta a nota para o usuário
    int nota[MEDIA];
    for (int i = 0; i < MEDIA; i++)
    {
     nota[i] = get_int("Digite a nota: ");
    }
    //Fala a media
    printf("A media das notas é: %.1f\n", average(MEDIA, nota));

}
    // Calcula a media do usuario
    float average(int length, int array[])
    {
     int soma = 0;
    for (int i = 0; i < length; i++)
        {
            soma += array[i];
        }
    return soma / (float) length;
    }

