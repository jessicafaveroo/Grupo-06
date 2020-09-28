#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>


struct filme
{
    int  codigo;
    char titulo[100];
    int quantidade;
    int ano;
    char genero[100];
    struct Filme *prox;

}Filme;

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

void carregarDados()
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
}

filme *carregarDados()
{
    filme *listaFilme = (filme*) malloc(sizeof(filme));

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

            //Ler a string até encontrar o ; para inserindo na lista
            fscanf(arq,"%[^;]s", titulo);
            fscanf(arq,";%d;%d;", &ano, &quantidade);
            fscanf(arq,"%s", genero);

            listaFilme = insereLista(listaFilme, titulo, ano, quantidade, genero,i);


        }

        // gera um código sequencial para o elemento e passa para a próxima linha do arquivo
        titulos[i].codigo = id++;

        printf("%d\n%s\n%s\n%s\n%s\n",
        titulos[i].codigo,
        titulos[i].titulo,
        titulos[i].quantidade,
        titulos[i].ano,
        titulos[i].genero
        );

     i++;
  }
  printf("----------- Base de dados carregada ------------\n\n");

    return listaFilme;
}

void locacao() /*retira o filme da lista de filmes a serem locados.*/
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

void entrega_filmes() /* recoloca o filme na lista. */
{

    int t1, t2, encontrado=-1;
    filme *aux = listaFilmes;

    //Busca enquanto não chegar ao fim da lista
    while(aux != NULL)
    {
        //guarda a chave na variável
        t1 = chaveInt;
        t2 = aux->codigo;

        //Se elas forem iguais, então mostra os dados do filme
        if(t1 == t2)
        {
                encontrado = 0;
                printf("\nÍtem encontrado: \n");
                printf("\nCódigo: %d \n", aux->codigo);
                printf("Título: ");
                puts(aux->titulo);
                printf("Ano: %d\nQuantidade: %d\nGênero: %s\n\n", aux->ano, aux->quantidade, aux->genero);

        }
        aux = aux->prox;
    }
    return encontrado;
}

void busca_ano(filme *listaFilmes, int chaveInt) /* Busca filme pelo ano. */
{
    int t1, t2, encontrado=-1;
    filme *aux = listaFilmes;

    //Busca enquanto não chegar ao fim da lista
    while(aux != NULL)
    {
        //guarda a chave na variável
        t1 = chaveInt;
        t2 = aux->ano;

        //Se elas forem iguais, então mostra os dados do filme
        if(t1 == t2)
        {
                encontrado = 0;
                printf("\nÍtem encontrado: \n");
                printf("\nCódigo: %d \n", aux->codigo);
                printf("Título: ");
                puts(aux->titulo);
                printf("Ano: %d\nQuantidade: %d\nGênero: %s\n\n", aux->ano, aux->quantidade, aux->genero);


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

    do
    {

    int busca;
    int opcao;

    do
    {
        printf("Sistema de Locações \n\n");
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
                    printf("Digite o código a ser buscado: ");
                    scanf("%d", &chaveInt);
                    busca_codigo(listaFilmes, chaveInt);
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
                    printf("Digite o ano a ser buscado: ");
                    scanf("%d", &chaveInt);
                    busca_ano(listaFilmes, chaveInt);
                    break;

                case 4:
                    printf("Digite o gênero a ser buscado: \n");
                    fgets(chave,sizeof(chave),stdin);
                    if(busca_genero(listaFilmes, chave) == -1)
                    {
                        printf("\nÍtem não encontrado\n\n");
                    }
                    break;

                case 5:
                    printf("Digite o código a ser buscado: ");
                    scanf("%d", &chaveInt);
                    busca_quantidade(listaFilmes, chaveInt);
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
            printf("Digite uma opção válida \n\n");
            }
        }
        while(opcao != 0);

    }
