#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Atribui pontos para cada letra
int pointsc[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int pontos(string word);

int main(void)
{
    // Pega o imput do usuario
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    //Executa a funcao pontos
    int score1 = pontos(word1);
    int score2 = pontos(word2);

    //Quem é maior, player 1, player 2, ou um empate?

    if (score1 > score2)
    {
        printf("Player 1 ganhou!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 ganhou!\n");
    }
    else
    {
        printf ("É um empate!\n");
    }

    return 0;
}
    //Responsavel por ler cada letra e atribuir os pontos

    int pontos(string word)
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char c = word[i];

        c = toupper(c);

        if (c >= 'A' && c <= 'Z')
        {
            score += pointsc[c - 'A'];
        }
    }

    //Retorna score para main
    return score;
}
