#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORDS 999
#define _GNU_SOURCE // necessário porque getline() é extensão GNU
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *f= fopen("entrada.txt", "r");
    size_t len= 100; // valor arbitrário
    char *linha= malloc(len);

    if (!f) {
        perror("teste.txt");
        exit(1);
    }
    while (getline(&linha, &len, f) > 0) {
        printf("%s", linha);
    }
    if (linha)
        free(linha);
    fclose(f);
    return 0;
}
/*
COM ESTE CÓD EU LEIO LINHA A LINHA
int main() {
    FILE* arquivo = fopen("arquivo.txt", "r");
    if(arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
        return 1;
    }

    int contagem = 0;
    int caractere;
    do {
        caractere = fgetc(arquivo);
        if(caractere == '\n') {
            contagem++;
        }
    } while(caractere != EOF);
    printf("O arquivo possui %d linhas.\n", contagem);

    fclose(arquivo);

    return 0;
} */



/*
int main() {
    FILE *fp;
    int i=0, j;
    char *words=NULL,*word=NULL,c;
    char *allwords[MAXWORDS];

    if ((fp=fopen("entrada.txt","r"))==NULL) {
        printf("Erro ao abrir o .txt\n");
        exit(1);
    }
    while ((c = fgetc(fp))!= EOF) {
        if (c=='\n') {
            c = ';';
        }
        words = (char *)realloc(words, ++i*sizeof(char));
        words[i-1]=c;
    }
    word=strtok(words,";");
    i=0;
    while(word!= NULL && i < MAXWORDS) {
        //printf("%s\n",word);
        allwords[i] = malloc(strlen(word));
        strcpy(allwords[i], word);
        word = strtok(NULL,";");
        i++;
    }
    printf("\n********************:\n");
    for (j=0; j<i; j++)
        printf("String %d: %s\n", j, allwords[j]);
    exit(0);
}*/
