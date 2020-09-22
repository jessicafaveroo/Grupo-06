#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct Filme
{
    int  codigo;
    char titulo[100];
    int quantidade;
    int ano;
    char genero[50];
    struct Filme *prox;

} filme;


filme *insereLista(filme *listaFilme, char *titulo, int ano, int quantidade, char *genero)
{
    filme *novo = (filme*) malloc(sizeof(filme)); // alocação dinamica, aloca um espaço de memoria para um nodo da lista
    novo->prox = listaFilme;
    strcpy(novo->titulo, titulo);
    novo->ano = ano;
    //gerar o codigo...
    novo->codigo = rand()%42;
    novo->quantidade = quantidade;
    strcpy(novo->genero, genero);
    return novo;
}

void imprimeLista(filme *listaFilme)
{
    filme *aux = listaFilme;
    while(aux != NULL)
    {
        puts(aux->titulo);
        printf("%d %d %s\n", aux->ano, aux->quantidade, aux->genero);
        aux = aux->prox;
    }
}

filme *carregarDados()
{
    filme *listaFilme = (filme*) malloc(sizeof(filme));

    char url[]="entrada.txt",
               titulo[100], genero[10];
    int ano, quantidade;
    int num_elementos;
    FILE *arq;

    arq = fopen(url, "r");
    if(arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else
    {
        fscanf(arq, "%d", &num_elementos);
        for(int i=0; i<num_elementos; i++)
        {
            fscanf(arq,"%[^;]s", titulo);
            fscanf(arq,";%d;%d;", &ano, &quantidade);
            fscanf(arq,"%s", genero);

            listaFilme = insereLista(listaFilme, titulo, ano, quantidade, genero);


        }
    }
    fclose(arq);

    return listaFilme;
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


int busca_titulo(filme *listaFilmes, char *chave)
{
    int t1, t2, i=0, igual=0, encontrado=-1;
    filme *aux = listaFilmes;
    while(aux != NULL)
    {
        t1 = strlen(chave);
        t2 = strlen(aux->titulo);
        igual=0;
        if(t1 == t2)
        {
            for(i=0; i<t1-1; i++)
            {

                if(chave[i] != aux->titulo[i+1])
                {
                    igual=1;
                    break;
                }
            }
            if(igual == 0)
            {
                encontrado = 0;
                printf("\nItem encontrado: \n");
                printf("\nCodigo: %d \n", aux->codigo);
                printf("\nTitulo: ");
                puts(aux->titulo);
                printf("\nAno: %d\n\nQuantidade: %d\n\nGenero: %s\n\n\n", aux->ano, aux->quantidade, aux->genero);
            }
        }
        aux = aux->prox;
    }
    return encontrado;

}

void busca_codigo() /* Busca filme pelo codigo. */
{
    printf("Função Busca de um filme por código \n\n");
}

void busca_ano() /* Busca filme pelo ano. */
{
    printf("Função Busca de um filme por ano \n\n");
}

void busca_quantidade() /* Busca filme pela quantidade. */
{
    printf("Função Busca de um filme por quantidade \n\n");
}

void busca_genero() /* Busca filme pelo genero. */
{
    printf("Função Busca de um filme por gênero \n\n");
}

void impressao() /* mostra as informações de um filme específico ou de todos os filmes do acervo. */
{
    printf("Função Impressão \n\n");
}

void relatorios() /* gera uma lista de filmes pesquisados por ano ou gênero. */
{
    printf("Função Relatórios \n\n");
}

void acervo_completo() /* imprime um backup do acervo atual com nomes e quantidades atualizadas. */
{
    printf("Função Acervo completo \n\n");
}


int main ()
{
    filme *listaFilmes = NULL;

    listaFilmes = carregarDados();

    int busca;
    int opcao;
    char chave[100];

    do
    {

        printf("----- Sistema de Locações -----\n\n");
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

                printf("----- Menu de busca -----\n\n");
                printf("1- Buscar por código \n");
                printf("2- Buscar \n");
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
                    printf("Digite o titulo a ser buscado: \n");
                    fgets(chave,sizeof(chave),stdin);
                    if(busca_titulo(listaFilmes, chave) == -1)
                    {
                        printf("Item não encontrado\n");
                    }
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
                    printf("você pediu para voltar ao menu principal. \n\n");
                    busca = 0;
                    break;

                case 0:
                    printf("Você pediu para sair, fechando programa...\n");
                    exit(0);
                    break;

                default:
                    printf("Digite uma opção válida. \n\n");
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
            printf("Digite uma opção válida. \n\n");
        }
    }
    while(opcao != 0);

}
