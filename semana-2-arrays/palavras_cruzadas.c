#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//array que declara valor a cada letra
const int PONTOS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
1, 4, 4, 8, 4, 10};

int pontos(string palavra);
int main(void){

    string jogador_1 = get_string("Jogador 1 digite uma palavra: ");
    string jogador_2 = get_string("Jogador 2 digite uma palavra: ");
    //chamar função "calcular"

    int pontos_1 = pontos(jogador_1);
    int pontos_2 = pontos(jogador_2);
    //if e else para comparara valores de jogador 1 e 2}

    if (pontos_1 > pontos_2){
        printf("Jogador 1 ganhou!\n");
    }

    else if (pontos_1 < pontos_2){
        printf("Jogador 2 ganhou!\n");
    }

    else{
        printf("É um empate!\n");
    }
}
//{função que percorre a string e calcula o valor de cada letra}
int pontos(string palavra){
int valor = 0;
    for (int i = 0, n = strlen(palavra); n > i; i++){
    int indice;
    if(isdigit(palavra[i])){
        printf("Digite somente letras.\n");
        exit(1);
    }
    if(ispunct(palavra[i])){
        continue;
    }
    indice = toupper(palavra[i]) - 'A';
    valor += PONTOS[indice];
    }
    return valor;
}
