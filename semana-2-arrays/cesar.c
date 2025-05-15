#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void criptografar(string texto, int key);

int main(int argc, string argv[])
{
    // Garante que o usuario digite somente um numero após o comando ./cesar e certifica de que seja um numero
    if (argc != 2 || atoi(argv[1]) <= 0)
    {
        printf("Use: ./cesar numero\n");
        return 1;
    }

    // Converte string para um inteiro
    int key = atoi(argv[1]);

    //Pega o o texto do usuario
    string user_text = get_string("Texto para criptografar: ");

    // Executa a função
    criptografar (user_text, key);

    return 0;
}

    void criptografar(string texto, int key)
{
        printf("Texto criptografado: ");

        // Inicia um loop para pegar cada letra do texto
        for (int i = 0, n = strlen(texto); i < n; i++)
    {
        char c = texto[i];

        //Confere se é uma letra maiscula ou minúscula e então salta o número de casas no alfabeto que o usuário escolheu
        if (c >= 'A' && c <= 'Z')
        {
            printf("%c", ((c - 'A' + key) % 26 ) + 'A');
        }

        else if (c >= 'a' && c <= 'z')
        {
            printf("%c", ((c - 'a' + key) % 26 ) + 'a');
        }

        else
        {
            printf("%c", c);
        }
    }
        printf ("\n");
}
