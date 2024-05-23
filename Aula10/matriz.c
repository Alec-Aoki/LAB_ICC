#include <stdio.h>
#include <stdlib.h>
#include <math.h> //vamos usar math.h para conseguir a raiz quadrada

/*
Implemente um programa em C que recebe um inteiro N que representa a quantidade de elementos
de uma matriz, vocˆe dever´a alocar uma matriz dinamicamente para receber esses n elementos, e
desenvolver fun¸c˜oes para preenche-la, e depois printa-la na tela

main:
-> receber n
-> Aloque();
-> Receba();
-> Imprima();

Aloque:
-> receber n
-> sqrt(n) = linha = coluna;
-> criar vetor de ponteiros que vão apontar para a matriz:
    -> **p = (int **)malloc(linha*sizeof(int *));
-> criar o vetor que vai servir de matriz:
    -> *v = (int *)malloc((linha*coluna)*sizeof(int));
-> dar o endereço do início de cada coluna a cada ponteiro no vetor de ponteiros:
    -> for(int i=0; i<linha; i++){
        p[i] = &v[i*coluna];
    }
-> retornar p;

Receba:
//loop para receber valores (n sei de vai dar certo):
-> for (int i=0; i<linha; i++){
    for (int j=0; j<coluna; j++){
        scanf(" %d", p[i][j]);
    }
}
return;

Imprima:
//loop para imprimir os valores (tmb n sei se funciona):
-> for (int i=0; i<linha; i++){
    for (int j=0; j<coluna; j++){
        printf("%d", *p[i][j]);
        //colocar aquele if macabro pra printar bonitinho
    }
}
return.
*/

int **Aloque(int tam_Aloque){
    int linha, coluna;
    //pegando a quant. de linhas e colunas (a matriz é quadrada)
    linha = coluna = sqrt(tam_Aloque);

    //criação do vetor de ponteiros
    int **vet_pont;
    vet_pont = (int **)malloc(linha*sizeof(int *));
    //criação do vetor que é a matriz em si
    int *vet;
    vet = (int *)malloc((linha*coluna)*sizeof(int));
    for (int i=0; i<linha; i++){
        vet_pont[i] = &vet[i*coluna];
    }

    return vet_pont;
}

void Receba(){

    return;
}

void Imprima(){

    return;
}

int main(void){
    int **pont_matriz, tam_m;
    //recebendo o tamanho da matriz
    scanf(" %d", &tam_m);

    //alocação da matriz na  heap:
    pont_matriz = Aloque(tam_m);

    //desalocação
    free(*pont_matriz);
    free(pont_matriz);
    *pont_matriz = NULL;
    return 0;
}