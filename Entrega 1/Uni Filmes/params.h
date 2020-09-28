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
    char genero[100];
    struct Filme *prox;

} filme;

void menu();

filme *insereLista(filme *listaFilme, char *titulo, int ano, int quantidade, char *genero, int codigo);

filme *carregarDados();

int locacao(filme *listaFilmes, char *chave);

int entrega_filmes(filme *listaFilmes, char *chave);

int busca_titulo(filme *listaFilmes, char *chave);

int busca_codigo(filme *listaFilmes, int chaveInt);

int busca_ano(filme *listaFilmes, int chaveInt);

int busca_quantidade(filme *listaFilmes, int chaveInt);

int busca_genero(filme *listaFilmes, char *chave);

void imprimeLista(filme *listaFilme);

void relatorios() ;
