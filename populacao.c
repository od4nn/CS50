#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int lhama;
    int lhamaf;
    do
    //Pergunta a população inicial e final para o usuario
    {
        lhama = get_int("Qual a população inicial? ");
    }
    while (lhama < 9);

    do
    {
        lhamaf = get_int("Qual será a população final? ");
    }
    while (lhamaf < 9 || lhamaf < lhama);
    //Calcula quantos anos levará para alcançar a população final
    int time = 0;
    int dif;
    while (lhama < lhamaf)
    {
        dif = (lhama / 3) - (lhama / 4);
        lhama = lhama + dif;
        time++;
    }

    //Mostra quantos anos levará
    printf("Levará: %i ano(s)\n", time);
}
