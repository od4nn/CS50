#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    //garante que tenha no minimo dois argumentos 
    if (argc != 2)
    {
        printf("Falta o comando na linha de argumento.\n");
        return 1;
    }
    printf("Ola %s\n", argv [1]);
    return 0;
}
