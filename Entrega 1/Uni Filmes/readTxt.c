#include <stdio.h>
//#include <conio2.h>

void main() {
    FILE *arq;
    char Linha[100];
    char *result;
    int i = 1;

    //clrscr();

    arq = fopen("Arquivo de entrada.txt", "rt");

    if(arq == NULL) {
        printf("Erro na leitura do arquivo\n");
        return;
    }
    //i = 1;
    while(!feof(arq)) {
        result = fgets(Linha, 100, arq);
        if(result) {
            //printf("Linha %d : %s", i, Linha);
            printf(Linha);
            i++;
        }
    }
    fclose(arq);
}
