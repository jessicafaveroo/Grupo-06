#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void locacao() /*retira o filme da lista de filmes a serem locados.*/
{
    printf("Funcao de locacao \n\n");
}

void entrega_filmes() /* recoloca o filme na lista. */
{
    printf("Funcao Entrega de filmes \n\n");
}

void busca_titulo() /* Busca filme pelo titulo. */
{
    printf("Funcao Busca de um filme por titulo \n\n");
}

void busca_codigo() /* Busca filme pelo codigo. */
{
    printf("Funcao Busca de um filme por codigo \n\n");
}

void busca_ano() /* Busca filme pelo ano. */
{
    printf("Funcao Busca de um filme por ano \n\n");
}

void busca_quantidade() /* Busca filme pela quantidade. */
{
    printf("Funcao Busca de um filme por quantidade \n\n");
}

void busca_genero() /* Busca filme pelo genero. */
{
    printf("Funcao Busca de um filme por genero \n\n");
}

void impressao() /* mostra as informações de um filme específico ou de todos os filmes do acervo. */
{
    printf("Funcao Impressao \n\n");
}

void relatorios() /* gera uma lista de filmes pesquisados por ano ou gênero. */
{
    printf("Funcao Relatorios \n\n");
}

void acervo_completo() /* imprime um backup do acervo atual com nomes e quantidades atualizadas. */
{
    printf("Funcao Acervo completo \n\n");
}

int main ()
{

    int busca;
    int opcao;

    do
    {
        printf("Sistema de Locacoes \n\n");
        printf("Digite a opcao desejada \n");
        printf("1- Locacao \n");
        printf("2- Entrega de filmes \n");
        printf("3- Busca de um titulo \n");
        printf("4- Impressao \n");
        printf("5- Relatorios \n");
        printf("6- Acervo completo \n");
        printf("0- Sair \n");
        fflush(stdin); /*limpar o buffer da entrada padrao para evitar que se for digitado letra o programa entre em loop.*/

        scanf("%d", &opcao);
        system("cls");

        switch(opcao)
        {

        case 0:
            printf("voce pediu para sair, fechando programa...\n");

            exit(0);
            break;

        case 1:
            locacao();
            break;

        case 2:
            entrega_filmes();
            break;

        case 3:
            do
            {

                printf("Buscar por codigo ou titulo \n");
                printf("1- Buscar por codigo \n");
                printf("2- Buscar por titulo \n");
                printf("3- Buscar por ano \n");
                printf("4- Buscar por genero \n");
                printf("5- Buscar por quantidade \n");
                printf("6- Sair \n");

                scanf("%d", &busca);
                system("cls || clear");

                switch(busca)
                {
                case 1:
                    busca_codigo();
                    break;

                case 2:
                    busca_titulo();
                    break;

                case 3:
                    busca_ano();
                    break;

                case 4:
                    busca_genero();
                    break;

                case 5:
                    busca_quantidade();
                    break;

                case 6:
                    printf("voce pediu para sair, fechando programa...\n");

                    exit(0);
                    break;

                default:
                    printf("Digite uma opcao valida \n\n");
                }
            }
            while(busca);

        case 4:
            impressao();
            break;

        case 5:
            relatorios();
            break;

        case 6:
            acervo_completo();
            break;

        default:
            printf("Digite uma opcao valida \n\n");
        }

    }
    while(opcao != 0);

}
