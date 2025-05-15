#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string text;
    // certifica de que o usuario não envie um espaço vazio
    do
    {
        text = get_string("Digite um texto: ");
    }
    while(strlen(text) == 0);

    //loop que percorre cada char da string, n - 1 para não acessar \0 no final
    for(int i = 0, n = strlen(text); i < n - 1; i++)
    {
        //verifica se o proximo char atual é maior que o proximo
        if(text[i] > text[i + 1])
        {
            //se sim, encerra o programa a retorna 0
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}
