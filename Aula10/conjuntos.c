#include <stdio.h>
#include <stdlib.h>

/*
Implemente um programa em C que leia 2 vetores (lendo o tamanho do vetor antes), os veto-
res s˜ao compostos por n´umeros inteiros(positivos e negativos) n˜ao ordenados, os vetores devem ser
compreendidos como conjuntos A e B.
O programa DEVE conter uma fun¸c˜ao que retorna o conjunto A uni˜ao B e outra que retorne
o conjunto (A uni˜ao B) - (A intersec¸c˜ao B), os vetores retornados devem ocupar somente o espa¸co
estritamente necess´ario. Em seguida, o programa deve imprimir os conjuntos como mostrado no
exemplo abaixo

OBRIGAT ´ORIO que as duas fun¸c˜oes especificadas retornem vetores, e que esses vetores
ocupem somente o espa¸co utilizado.
• Os elementos dos conjuntos impressos devem estar ordenados.
• caso o conjunto seja vazio, deve ser impresso ”vazio”.

main:
-> ler tamanho dos vetores
-> receber comeco dos vetores em dois ponteiros diferentes
-> criar vetor pra uniao e interseccao

Leia_Elementos:
-> calloc
-> retorna ponteiro para o inicio desse vetor

Ordene_Elementos:
-> bubble sort neles
-> usar indicies
-> return nada

Uniao_AB:
-> jogar A no vetor Uniao
-> verificar se o elemento de B ja existe em Uniao
    -> se sim: fodase
    -> se nao: colocar no vetor Uniao
    -> Ordene_Elementos vetor Uniao

Intersec_AB:
-> jogar A no vetor Intersec
-> verificar se o elemento de B ja existe em Intersec
    -> se sim: tirar do Intersec
    -> se nao: colocar no vetor Intersec
    -> Ordene_Elementos vetor Intersec
*/

int *Leia_Elementos(int tam){
    int *ponteiro_Leia;
    ponteiro_Leia = (int *)calloc(tam, sizeof(int));
    if (ponteiro_Leia == NULL){
        printf("Deu ruim no calloc\n");
        exit(1);
    }
    printf("Deu bom no calloc\n");
    for (int i=0; i<tam; i++){
        scanf(" %d", ponteiro_Leia+i);
    }

    return ponteiro_Leia;
}

void Ordene_Elementos(int tam, int **ponteiro_Ordene){
    int aux;
    for (int i=0; i<tam; i++){
        for (int j=1; j<tam; j++){
            if (**(ponteiro_Ordene+j) < **(ponteiro_Ordene+(j-1))){
                aux = **(ponteiro_Ordene+j);
                **(ponteiro_Ordene+j) = **(ponteiro_Ordene+(j-1));
                **(ponteiro_Ordene+(j-1)) = aux;
            }
        }
    }
    return;
}

// Uniao_AB(){

// }

// Intersec_AB(){

// }

int main(void){
    int tam_A, tam_B, *ponteiro_A, *ponteiro_B;

    scanf(" %d", &tam_A);
    ponteiro_A = Leia_Elementos(tam_A);

    scanf(" %d", &tam_B);
    ponteiro_B = Leia_Elementos(tam_B);

    Ordene_Elementos(tam_A, &ponteiro_A);

    return 0;
}