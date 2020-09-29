#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORDS 999
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *f= fopen("entrada.txt", "r");
    size_t len= 100; // valor arbitrário
    char *linha= malloc(len);//com size 100 pq pretendo alocar mais de 1 byte

    if (!f) {
        perror("teste.txt");
        exit(1);
    }
    printf("\n")
    while (getline(&linha, &len, f) > 0) {
        printf("%s", linha);
    }
    if (linha)
        free(linha);
    fclose(f);
    return 0;
}
