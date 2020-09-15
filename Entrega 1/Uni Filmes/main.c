#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct filme FILME;
struct filme{
    int codigo;
    char titulo[200];
    int quantidade;
    int ano;
    char genero[50];
};

void locacao() /*retira o filme da lista de filmes a serem locados.*/
{

typedef struct {
    int codigo;
    char titulo[200];
    int quantidade;
    int ano;
    char genero[50];
} Filme;

    Filme filmes[2];
    char titulo[200];
    int codigo[10];
    int quantidade[10];
    int ano[1000];
    char genero[200];

    int codigoDigitado;

    void remover(int i){

        filmes[i].quantidade = filmes[i].quantidade - 1;

    }

    printf("Funcao de locacao \n \n");

    for(int i=0; i<2; i++) {
        filmes[i].codigo = 0;
        filmes[i].titulo, "*";
        filmes[i].ano = 0;
        filmes[i].quantidade = 0;
        filmes[i].genero, "*";
    }

    for(int i=0; i<2; i++) {
        printf(" \n O código do filme é: %d ", filmes[i].codigo);
        printf(" \n O titulo do filme é: %c ", filmes[i].titulo);
        printf(" \n O genero é: %c ", filmes[i].genero);
        printf(" \n O ano do filme é: %d", filmes[i].ano);
        printf(" \n Quantidades é: %d", filmes[i].quantidade);
        printf(" \n ------------------------------------------------------------------------");
    }

    printf(" \n \n");

    for(int i=0; i<2; i++) {
        printf(" Digite o código do filme: ");
        fflush(stdin);
        //                                   gets(&filmes[i].codigo);
        scanf("%d%*c", &filmes[i].codigo);
        printf(" Digite o titulo do filme: ");
        fflush(stdin);
        gets(&filmes[i].titulo);
        //                                   scanf("%c%*c", &filmes[i].titulo);
        printf(" Digite o genero do filme: ");
        fflush(stdin);
        gets(&filmes[i].genero);
        //                                   scanf("%c%*c", &filmes[i].genero);
        printf(" Digite o ano do filme: ");
        fflush(stdin);
        //                                   gets(&filmes[i].ano);
        scanf("%d%*c", &filmes[i].ano);
        printf(" Digite a quantidade: ");
        fflush(stdin);
        //                                   gets(&filmes[i].quantidade);
        scanf("%d%*c", &filmes[i].quantidade);
        printf(" \n ------------------------------------------------------------------------\n");
    }

    for(int i=0; i<2; i++) {
        printf(" \n O código do filme é: %d ", filmes[i].codigo);
        printf(" \n O titulo do filme é: %s ", filmes[i].titulo);
        printf(" \n O genero do filme é: %s ", filmes[i].genero);
        printf(" \n O ano do filme é: %d", filmes[i].ano);
        printf(" \n A quantidade é: %d", filmes[i].quantidade);
        printf(" \n ------------------------------------------------------------------------");
    }

    printf(" \n ");

        printf(" \n Digite o codigo do filme: ");
        scanf("%d", &codigoDigitado);

        for(int i = 0; i < 2; i++){
            if (filmes[i].codigo == codigoDigitado){
            remover(i);
            printf("\n Filme Alugado!!\n");
            } else {
                printf("\n Filme nao encontrado!! \n");
            }
        }

        for(int i=0; i<2; i++) {
            printf(" \n O código do filme é: %d ", filmes[i].codigo);
            printf(" \n O titulo do filme é: %s ", filmes[i].titulo);
            printf(" \n O genero do filme é: %s ", filmes[i].genero);
            printf(" \n O ano do filme é: %d", filmes[i].ano);
            printf(" \n A quantidade é: %d", filmes[i].quantidade);
            printf(" \n ------------------------------------------------------------------------");
        }

    printf("\n \n");

}

void entrega_filmes() /* recoloca o filme na lista. */
{

   // printf("\n Informe o código do filme: ");

    // abre arquivo em mode de leitura
    FILE *arquivo_entrada_filmes;
    FILME film;
    arquivo_entrada_filmes = fopen("entrada.txt", "r");
    char filme[50];


    //Verifica se o arquivo não é nulo
    if(arquivo_entrada_filmes == NULL){
        printf("Erro ao abri arquivo");
        system("pause");
        return 0;
    }



  /* while(fread(&film, sizeof(FILME),1, arquivo_entrada_filmes)==1){
        printf("%d", film.titulo);
    } */

    //enquanto não chegar ao fim do arquivo o looping ser executado
    while(fgets(filme, 50, arquivo_entrada_filmes) != NULL)
    printf("%s", filme );


    //fecha o arquivo
    fclose(arquivo_entrada_filmes);

    //stop na tela
    getchar();
    return(0);

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
