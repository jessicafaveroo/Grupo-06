#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct Filme
{
    int  codigo;
    char *titulo;
    char *quantidade;
    char *ano;
    char *genero;

}filme;

typedef struct node_filme{
  filme titulos;
  struct node_filme * inicio;
  struct node_filme * atual;
  struct node_filme * proximo;
}node_filmes;


void carregarDados(node_filmes * inicio)

{
    int  id = 0;
    const char separador[2] = ";";
    char *token;
    char linha[90];
    char *resultado;

    FILE *arquivoEntrada;
    if((arquivoEntrada = fopen("entrada.txt", "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    token = strtok(arquivoEntrada, separador);

    //variável i percorre cada Struct ou seja cada linha
    int i = 0;
    //tratamento para não ultrapassar o tamanho da lista
    while (!feof(arquivoEntrada) && i < 42)
    {
        resultado = fgets(linha, 90, arquivoEntrada);
        if (resultado)
            token = strtok(resultado, separador);

        // estrutura de loop para um elemento inteiro do tipo filme
        int j = 0;
        while( token != NULL )
        {

            //insere cada atributo no elemento tipo filme
            switch(j)

            {
            case 0:
                inicio->titulos.titulo = token;
                break;
            case 1:
                inicio->titulos.ano = token;
                break;
            case 2:
                inicio->titulos.quantidade = token;
                break;
            case 3:
                inicio->titulos.genero = token;
                break;

            }

            token = strtok(NULL, separador);
            j++;
        }

        // gera um código sequencial para o elemento e passa para a próxima linha do arquivo
        inicio->titulos.codigo = id++;
        inserir(inicio, inicio->titulos);
        i++;

  }

  printf("----------- Base de dados carregada ------------\n\n");

    fclose(arquivoEntrada);

}

void locacao() /*retira o filme da lista de filmes a serem locados.*/
{
    /*struct filme *teste;
    int idFilme;

   printf("Codigo do filme:\n");
   scanf("%d", &idFilme);

    for(int i = 0; i < 41; ++i){
        if(titulos[i].codigo == idFilme){
            printf("ok \n");
        }
        printf("nao ok \n");
    }

   return 0;*/
}

void entrega_filmes() /* recoloca o filme na lista. */
{

}

/* while(fread(&film, sizeof(FILME),1, arquivo_entrada_filmes)==1){
      printf("%d", film.titulo);
  } */

//enquanto não chegar ao fim do arquivo o looping ser executado
//   while(fgets(filme, 50, arquivo_entrada_filmes) != NULL)
//  printf("%s", filme );


//fecha o arquivo
//fclose(arquivo_entrada_filmes);

//stop na tela
//  getchar();
//return(0);



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


void mostrarListaFilmes(node_filmes * inicio){
    node_filmes * atual = inicio;

    while(atual->proximo != NULL){
        if(atual->titulos.codigo != NULL){
            printf("%d\n %s\n %s\n %s\n %s\n",
            atual->titulos.codigo,
            atual->titulos.titulo,
            atual->titulos.quantidade,
            atual->titulos.ano,
            atual->titulos.genero
            );
        }
        atual = atual->proximo;
    }
}

void inserir(node_filmes * inicio, filme f){
    node_filmes * atual = inicio;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }

    atual->proximo = (node_filmes *) malloc(sizeof(node_filmes));
    atual->titulos = f;
    atual->proximo->proximo = NULL;
}

int main ()
{

    node_filmes * inicio = NULL;
    inicio = (node_filmes *) malloc(sizeof(node_filmes));
    if(inicio == NULL){
        return 1;
    }

    carregarDados(inicio);

    mostrarListaFilmes(inicio);

    int busca;
    int opcao;

    do
    {
        printf("Sistema de Locações \n\n");
        printf("1- Locação \n");
        printf("2- Entrega de filmes \n");
        printf("3- Busca de um título \n");
        printf("4- Impressão \n");
        printf("5- Relatório \n");
        printf("6- Acervo completo \n");
        printf("0- Sair \n\n");
        printf("Digite a opção desejada: ");
        /*fflush(stdin); /* WINDOWS limpar o buffer da entrada padrao para evitar que se for digitado letra o programa entre em loop.*/

        scanf("%d", &opcao);
        __fpurge(stdin);  /*limpar o buffer da entrada padrao para evitar que se for digitado letra o programa entre em loop.*/
        system("clear");

        switch(opcao)
        {

        case 0:
            printf("Você pediu para sair, fechando programa...\n");
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

                printf("Menu de busca: \n\n");
                printf("1- Buscar por código \n");
                printf("2- Buscar por título \n");
                printf("3- Buscar por ano \n");
                printf("4- Buscar por gênero \n");
                printf("5- Buscar por quantidade \n");
                printf("6- voltar \n");
                printf("0- Sair \n\n");
                printf("Digite a opção desejada: ");
                /*fflush(stdin);*/


                scanf("%d", &busca);
                __fpurge(stdin);
                system("clear");

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
                    printf("você pediu para voltar ao menu principal \n\n");
                    busca = 0;
                    break;

                case 0:
                    printf("Você pediu para sair, fechando programa...\n");
                    exit(0);
                    break;

                default:
                    printf("Digite uma opção válida \n\n");
                }
            }
            while(busca!= 0);
            break;

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
            printf("Digite uma opção válida \n\n");
            }
        }
        while(opcao != 0);

    }
