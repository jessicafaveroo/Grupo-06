#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>


typedef struct Filme
{
    int  codigo;
    char titulo[100];
    int quantidade;
    int ano;
    char genero[50];
    struct Filme *prox;

} filme;

//Função para inserir elemento no começo da lista
filme *insereLista(filme *listaFilme, char *titulo, int ano, int quantidade, char *genero, int codigo)
{
    filme *novo = (filme*) malloc(sizeof(filme)); // alocação dinamica, aloca um espaço de memoria para um nodo da lista
    //Cópia dos dados para cada nodo
    novo->prox = listaFilme;
    strcpy(novo->titulo, titulo);
    novo->ano = ano;
    //gera o codigo...
    novo->codigo = codigo;
    novo->quantidade = quantidade;
    strcpy(novo->genero, genero);
    //Retorna a posição do novo nodo que é o começo da lista
    return novo;
}

void imprimeLista(filme *listaFilme)
{
    filme *aux = listaFilme;
    while(aux != NULL)
    {

        printf("\nCódigo: %d \n", aux->codigo);
        printf("Título: ");
        puts(aux->titulo);
        printf("Ano: %d\nQuantidade: %d\nGênero: %s\n\n", aux->ano, aux->quantidade, aux->genero);
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
        printf("Erro, não foi possível abrir o arquivo\n");
    else
    {
        fscanf(arq, "%d", &num_elementos);
        for(int i=0; i<num_elementos; i++)
        {

            //Ler a string até encontrar o ; para inserindo na lista
            fscanf(arq,"%[^;]s", titulo);
            fscanf(arq,";%d;%d;", &ano, &quantidade);
            fscanf(arq,"%s", genero);

            listaFilme = insereLista(listaFilme, titulo, ano, quantidade, genero,i);


        }
    }
    fclose(arq);

    return listaFilme;
}

int locacao(filme *listaFilmes, char *chave) /*retira o filme da lista de filmes a serem locados.*/
{

    int l1, l2;
    int i = 0;
    int j = 0;
    int locado = -1;
    filme *f = listaFilmes;
    while(f != NULL)
    {
        l1 = strlen(chave);
        l2 = strlen(f->titulo);
        j=0;
        if(l1 == l2)
        {
            for(i=0; i<l1-1; i++)
            {
                if(chave[i] != f->titulo[i+1])
                {
                    j=1;
                    break;
                }
            }
            if(j == 0)
            {
                locado = 0;

                if(f->quantidade <= 0)
                {
                    printf("\n***Filme esgotado***.\n");
                }
                else
                {
                    f->quantidade = f->quantidade - 1;
                }

                printf("\nFilme Alugado: \n");
                printf("\nCódigo: %d \n", f->codigo);
                printf("Título: ");
                puts(f->titulo);

                printf("Ano: %d\nQuantidade: %d\nGênero: %s\n\n",
                       f->ano,
                       f->quantidade,
                       f->genero);
            }

        }
        f = f->prox;
    }
    return locado;



}

int entrega_filmes(filme *listaFilmes, char *chave) /* recoloca o filme na lista. */
{

    int d1, d2;
    int i = 0;
    int j = 0;
    int devolucao = -1;
    int max = 0, max1 = 0;
    filme *f = listaFilmes;
    while(f != NULL)
    {
      d1 = strlen(chave);
      d2 = strlen(f->titulo);
      j=0;
      max1 = max;
      max = f->quantidade;
      if(d1 == d2)
      {
        for(i=0; i<d1-1; i++)
        {
          if(chave[i] != f->titulo[i+1])
          {
            j=1;
            break;
          }
        }
        if(j == 0)
        {
           devolucao = 0;

           if(f->quantidade <= 0 || f->quantidade < max1){
                f->quantidade = f->quantidade + 1;
           } else {
                printf("\n***Limite maximo de filmes***.\n");
           }

           printf("\nFilme Alugado: \n");
           printf("\nCodigo: %d \n", f->codigo);
           printf("\nTitulo: ");
           puts(f->titulo);

           printf("\nAno: %d\n\nQuantidade: %d\n\nGenero: %s\n\n\n",
           f->ano,
           f->quantidade,
           f->genero);
        }

      }
        f = f->prox;
     }
    return devolucao;

}

int busca_titulo(filme *listaFilmes, char *chave)
{
    int t1, t2, i=0, igual=0, encontrado=-1;
    filme *aux = listaFilmes;
    //Busca enquanto não encontrar o título
    while(aux != NULL)
    {
        //Primeiro obtem o tamanho das duas chaves: a ser buscada e o titulo.
        t1 = strlen(chave);
        t2 = strlen(aux->titulo);
        igual=0;
        //Se elas forem de mesmo tamanho, irá comparar letra a letra para identificar se são iguais.
        if(t1 == t2)
        {
            for(i=0; i<t1-1; i++)
            {
                //compara se as duas letras são iguais. )titulo[i+1] para garantir que está comparando a mesma posição da string. por alguma razão, não funciona se não deixar assim.
                if(chave[i] != aux->titulo[i+1])
                {
                    igual=1;
                    break;
                }
            }
            //se o item foi encontrado, imprime as informações.
            if(igual == 0)
            {
                encontrado = 0;
                printf("\nÍtem encontrado: \n");
                printf("\nCódigo: %d \n", aux->codigo);
                printf("Título: ");
                puts(aux->titulo);
                printf("Ano: %d\nQuantidade: %d\nGênero: %s\n\n", aux->ano, aux->quantidade, aux->genero);
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

    int busca, opcao, imprimir;
    char chave[100];

    do
    {

        printf("----- Sistema de Locações -----\n\n");
        printf("1- Locação \n");
        printf("2- Entrega de filmes \n");
        printf("3- Buscas \n");
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
            printf("Digite um titulo de filme para locacao: \n");
            fgets(chave,sizeof(chave),stdin);
            if(locacao(listaFilmes, chave) == -1)
            {
                printf("\nÍtem não encontrado\n");
            }
            break;

        case 2:
            printf("Digite o titulo do filme para devolucao: \n");
            fgets(chave,sizeof(chave),stdin);
            if(entrega_filmes(listaFilmes, chave) == -1)
            {
                printf("Filme não encontrado para devolução");
            }
            break;
        case 3:
            do
            {

                printf("----- Menu de busca -----\n\n");
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
                    printf("Digite o titulo a ser buscado: \n");
                    fgets(chave,sizeof(chave),stdin);
                    if(busca_titulo(listaFilmes, chave) == -1)
                    {
                        printf("\nÍtem não encontrado\n\n");
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
            do
            {

                printf("----- Opções de impressão -----\n\n");
                printf("1- Imprimir informações de um filme especfico \n");
                printf("2- Imprimir informações de todos os filmes \n");
                printf("3- voltar \n");
                printf("0- Sair \n\n");
                printf("Digite a opção desejada: ");
                /*fflush(stdin);*/

                scanf("%d", &imprimir);
                __fpurge(stdin);
                system("clear");

                switch(imprimir)
                {
                case 1:
                    printf("Digite o titulo a ser buscado: \n");
                    fgets(chave,sizeof(chave),stdin);
                    if(busca_titulo(listaFilmes, chave) == -1)
                    {
                        printf("\nÍtem não encontrado\n\n");
                    }
                    break;

                case 2:
                    imprimeLista(listaFilmes);
                    break;

                case 3:
                    printf("você pediu para voltar ao menu principal. \n\n");
                    imprimir = 0;
                    break;

                case 0:
                    printf("Você pediu para sair, fechando programa...\n");
                    exit(0);
                    break;

                default:
                    printf("Digite uma opção válida. \n\n");
                }
            }
            while(imprimir!= 0);
            break;

        case 5:
            relatorios();
            break;

        case 6:
            imprimeLista(listaFilmes);
            break;

        default:
            printf("Digite uma opção válida. \n\n");
        }
    }
    while(opcao != 0);

}
