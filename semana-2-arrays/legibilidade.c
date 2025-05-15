#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void contar(string texto);
int main(void)
{
    // Pega o texto do usuario
    string texto = get_string("Digite o texto: ");

    // Executa a função "contar"
    contar(texto);

    // Indica que o programa terminou com sucesso
    return 0;
}

// Função "contar"
void contar(string texto)
{
    int palavras = 0;
    int letras = 0;
    int frases = 0;
    float L = 0;
    float S = 0;
    float indice = 0;

    // Pega cada caractere do texto
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        char c = texto[i];

        // Verifica se c é uma letra do alfabeto ou se ele é um digito
        if (isalpha(c) || isdigit(c))
        {
            letras++;
        }

        // Verifica na contagem o que é espaço ' ' e se o texto começar com um espaço ou durante ele tiver um espaço seguido de outro, ele não conta
        if (isspace(c) && i > 0 && !isspace(texto[i - 1]))
        {
            palavras++;
        }

        //Considera que uma frase é um conjunto de palavras terminados por '!' por '?' ou '.'
        if (c == '!' || c == '?' || c == '.')
        {
            frases++;
        }
    }

    //Usado para evitar que o programa não calcule incorretamente se o usuário não comperar e enviar um texto em branco ' '
    if (palavras > 0)
    {
         // Sutil, mas é necessario para que a contagem de palavras seja feita de maneira precisa
         palavras++;

         // Calcula a media de letras por palavras e número médio de sentenças por 100 palavras no texto
         L = (letras / (float)palavras) * 100;
         S = (frases / (float)palavras) * 100;

         // Calculo de indice para descobrir a qual grau o texto mandado pertence
         indice = 0.0588 * L - 0.296 * S - 15.8;
    }

    // Arredonda o valor
    indice = round(indice);

    // Mostra as informações sobre o texto
    printf("Letras: %i\n", letras);
    printf("Palavras: %i\n", palavras);
    printf("Frases: %i\n", frases);


    // Se o texto tiver grau maior que 16: Grau 16+
    if (indice >= 16)
    {
        printf("Grau: 16+\n");
    }

    // Se o texto tiver grau menos que 2: antes do grau 2
    else if (indice < 2)
    {
        printf("Grau: antes do grau 2.\n");
    }

    // Senão, mostrar a qual grau aquele texto pertence
    else
    {
        printf("Grau: %i\n", (int) indice);
    }
}
