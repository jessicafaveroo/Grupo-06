#include "params.h"

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

int locacao(filme *listaFilmes, int *chaveInt) /*retira o filme da lista de filmes a serem locados.*/
{

    int l1, l2;
    int j = 0;
    int quantidadeTotal;
    int locado = -1;
    filme *f = listaFilmes;
    while(f != NULL)
    {
        l1 = chaveInt;
        l2 = f->codigo;
        j=0;
        if(l1 == l2)
        {
            quantidadeTotal = listaFilmes->quantidade;
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

int entrega_filmes(filme *listaFilmesAlugadosParam, int *chaveInt) /* recoloca o filme na lista. */
{

    int codigoDigitado, codigoFilmeAlugado;
    int devolucao = -1;
    int max, quantidadeTotal;
    filme *filmesAlugados = listaFilmesAlugadosParam;

    filme *listaFilmes = NULL;
    listaFilmes = carregarDados();

    codigoDigitado = chaveInt;

    while(filmesAlugados != NULL) {

        codigoFilmeAlugado = filmesAlugados->codigo;
        if(codigoDigitado == codigoFilmeAlugado)
        {
            devolucao = 0;
            max = listaFilmes->quantidade;
            quantidadeTotal = max;

            if(filmesAlugados->quantidade >= 0 && filmesAlugados->quantidade < quantidadeTotal){
                filmesAlugados->quantidade = filmesAlugados->quantidade + 1;

                printf("\nFilme encontrado: \n");
                printf("\nCodigo: %d \n", filmesAlugados->codigo);
                printf("\nTitulo: ");
                puts(filmesAlugados->titulo);
                printf("\nAno: %d\n\nQuantidade: %d\n\nGenero: %s\n\n\n",
                filmesAlugados->ano,
                filmesAlugados->quantidade,
                filmesAlugados->genero);
                break;

            } else {
                printf("\n***Limite maximo de filmes***.\n");
            }
        }
            filmesAlugados = filmesAlugados->prox;
            listaFilmes = listaFilmes->prox;
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

int busca_codigo(filme *listaFilmes, int chaveInt) /* Busca filme pelo codigo. */
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

int busca_ano(filme *listaFilmes, int chaveInt) /* Busca filme pelo ano. */
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

        }
        aux = aux->prox;
    }
    return encontrado;
}

int busca_quantidade(filme *listaFilmes, int chaveInt) /* Busca filme pela quantidade. */
{
    int t1, t2, encontrado=-1;
    filme *aux = listaFilmes;

    //Busca enquanto não chegar ao fim da lista
    while(aux != NULL)
    {
        //guarda a chave na variável
        t1 = chaveInt;
        t2 = aux->quantidade;

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

int busca_genero(filme *listaFilmes, char *chave) /* Busca filme pelo genero. */
{

    int t1, t2, i=0, igual=0, encontrado=-1;
    filme *aux = listaFilmes;
    //Busca enquanto não encontrar o título
    while(aux != NULL)
    {
        //Primeiro obtem o tamanho das duas chaves: a ser buscada e o titulo.
        t1 = strlen(chave);
        t2 = strlen(aux->genero) +1;
        igual=0;
        //Se elas forem de mesmo tamanho, irá comparar letra a letra para identificar se são iguais.
        if(t1 == t2)
        {
            for(i=0; i<t1-1; i++)
            {
                //compara se as duas letras são iguais. )titulo[i+1] para garantir que está comparando a mesma posição da string.
                if(chave[i] != aux->genero[i])
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

void imprimeLista(filme *listaFilme) /* mostra as informações de um filme específico ou de todos os filmes do acervo. */
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

void relatorios() /* gera uma lista de filmes pesquisados por ano ou gênero. */
{
    printf("Função Relatórios \n\n");
}

void menu(){
filme *listaFilmes = NULL;
    listaFilmes = carregarDados();
    int busca, opcao, imprimir;
    char chave[100];
    int chaveInt;

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
            printf("Digite um codigo de filme para locacao: \n");
            scanf("%d", &chaveInt);
            if(locacao(listaFilmes, chaveInt) == -1)
            {
                printf("\nÍtem não encontrado\n");
            }
            break;

        case 2:
            printf("Digite o codigo do filme para devolucao: \n");
            scanf("%d", &chaveInt);
            if(entrega_filmes(listaFilmes, chaveInt) == -1)
            {
                printf("\nFilme não encontrado para devolução\n\n");
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
            do
            {

                printf("----- Opções de relatório -----\n\n");
                printf("1- Digite o ano a ser buscado:  \n");
                printf("2- Digite o gênero a ser buscado: \n");
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
                    printf("Digite o ano a ser buscado: ");
                    scanf("%d", &chaveInt);
                    busca_ano(listaFilmes, chaveInt);
                    break;

                case 2:
                    printf("Digite o gênero a ser buscado: \n");
                    fgets(chave,sizeof(chave),stdin);
                    if(busca_genero(listaFilmes, chave) == -1)
                    {
                        printf("\nÍtem não encontrado\n\n");
                    }
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

        case 6:
            imprimeLista(listaFilmes);
            break;

        default:
            printf("Digite uma opção válida. \n\n");
        }
    }
    while(opcao != 0);

    }
