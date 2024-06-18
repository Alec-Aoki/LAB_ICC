#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    //Alocação dinâmica da palavra
    char *pont_palavra = (char *)malloc(20*sizeof(char));
    if(pont_palavra == NULL) exit(1);
    scanf(" %s", pont_palavra);
    pont_palavra = (char *)realloc(pont_palavra, strlen(pont_palavra)*sizeof(char));
    if(pont_palavra == NULL) exit(1);


    //Alocação dinâmica do nome do arquivo
    char *pont_nomearq = (char *)malloc(20*sizeof(char));
    if(pont_nomearq == NULL) exit(1);
    scanf(" %s", pont_nomearq);
    pont_nomearq = (char *)realloc(pont_nomearq, strlen(pont_nomearq)*sizeof(char));
    if(pont_nomearq == NULL) exit(1);

    FILE *fp;
    fp = fopen(pont_nomearq, "rb+");
    if (fp == NULL) exit(1);

    fclose(fp);
    free(pont_nomearq);
    free(pont_palavra);
    return 0;
}