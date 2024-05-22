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
-> ordernar elementos da uniao e interseccao

Leia_Elementos:
-> calloc
-> retorna ponteiro para o inicio desse vetor

Ordene_Elementos:
-> bubble sort neles
-> usar indicies
-> return nada

Uniao_AB:
-> criar vetor Uniao
    -> do tamamho de A
-> jogar A no vetor Uniao
-> verificar se o elemento de B ja existe em Uniao
    -> se sim: fodase
    -> se nao: add um espaço no Uniao e colocar o valor

Intersec_AB:
-> jogar A no vetor Intersec
-> verificar se o elemento de B ja existe em Intersec
    -> se sim: tirar do Intersec
    -> se nao: colocar no vetor Intersec
*/

int *Leia_Elementos(int tam){
    int *ponteiro_Leia;
    ponteiro_Leia = (int *)calloc(tam, sizeof(int));
    // acabamos de criar o vetor na memória heap
    if (ponteiro_Leia == NULL){
        exit(1);
    }
    //leitura dos elementos do vetor:
    for (int i=0; i<tam; i++){
        scanf(" %d", ponteiro_Leia+i);
    }
    //retornando o endereço do começo do vetor na heap:
    return ponteiro_Leia;
}

void Ordene_Elementos(int tam, int *ponteiro_Ordene){
    int aux;
    //Bubblesort
    for (int i=0; i<tam; i++){
        for (int j=1; j<tam; j++){
            if (ponteiro_Ordene[j] < ponteiro_Ordene[j-1]){
                aux = ponteiro_Ordene[j];
                ponteiro_Ordene[j] = ponteiro_Ordene[j-1];
                ponteiro_Ordene[j-1] = aux;
            }
        }
    }
    return;
}

int *Uniao_AB(int *tam_Uniao, int tam_A, int tam_B, int *ponteiro_UA, int *ponteiro_UB){
    int flag = 0, tam_novo=tam_A;
    /*
    -> criar vetor Uniao
        -> do tamamho de A
    -> jogar A no vetor Uniao
    -> verificar se o elemento de B ja existe em Uniao
        -> se sim: fodase
        -> se nao: add um espaço no Uniao e colocar o valor*/
    int *pont_vet_Uniao;
    pont_vet_Uniao = (int *)calloc(tam_A, sizeof(int));

    //jogando os valores de A em Uniao
    for (int i=0; i<tam_A; i++){
        pont_vet_Uniao[i] = ponteiro_UA[i];
    }

    for (int i=0; i<tam_B; i++){
        flag = 0;
        for (int j=0; j<tam_A; j++){
            if (ponteiro_UB[i] == pont_vet_Uniao[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            tam_novo += 1;
            pont_vet_Uniao = (int *)realloc(pont_vet_Uniao, (tam_novo*sizeof(int)));
            pont_vet_Uniao[tam_novo-1] = ponteiro_UB[i];
        }
    }

    *tam_Uniao = tam_novo;

    return pont_vet_Uniao;
}

int *Intersec_AB(int *tam_Intersec, int tam_A, int tam_B, int *ponteiro_UA, int *ponteiro_UB){
    int tam_novo=tam_A;
    int *aux;
    //vai ser basicamente o Uniao, so mudando a logica do if else
    /*
    Intersec_AB:
    -> jogar A no vetor Intersec
    -> verificar se o elemento de B ja existe em Intersec
        -> se sim: tirar do Intersec
        -> se nao: colocar no vetor Intersec*/
    int *pont_vet_Intersec;
    pont_vet_Intersec = (int *)calloc(tam_A, sizeof(int));

    //jogando os valores de A em Intersec
    for (int i=0; i<tam_A; i++){
        pont_vet_Intersec[i] = ponteiro_UA[i];
    }

    for (int i=0; i<tam_B; i++){
        for (int j=0; j<tam_A; j++){
            if (ponteiro_UB[i] == pont_vet_Intersec[j]) {
                aux = &pont_vet_Intersec[j];
                free(aux);
                tam_novo -= 1;
                pont_vet_Intersec = (int *)realloc(pont_vet_Intersec, tam_novo*sizeof(int));
            }
        }
    }

    *tam_Intersec = tam_novo;

    return pont_vet_Intersec;
}

int main(void){
    int tam_A, tam_B, *ponteiro_A, *ponteiro_B;

    printf("Tamanho de A:\n");
    scanf(" %d", &tam_A);
    //ponteiro_A recebe o endereço do começo do vetor na heap
    printf("Digite os elementos de A:\n");
    ponteiro_A = Leia_Elementos(tam_A);

    printf("Tamanho de B:\n");
    scanf(" %d", &tam_B);
    //ponteiro_B recebe o endereço do começo do vetor na heap
    printf("Digite os elementos de B:\n");
    ponteiro_B = Leia_Elementos(tam_B);

    int *ponteiro_Uniao, *ponteiro_Intersec;
    int tam_Uniao, tam_Intersec;

    //ponteiro_Uniao aponta para o começo do vetor Uniao na heap
    ponteiro_Uniao = Uniao_AB(&tam_Uniao, tam_A, tam_B, ponteiro_A, ponteiro_B);
    //ordenando o vetor Uniao
    Ordene_Elementos(tam_Uniao, ponteiro_Uniao);

    //mesma coisa, so que com o Intersec
    ponteiro_Intersec = Intersec_AB(&tam_Intersec, tam_A, tam_B, ponteiro_A, ponteiro_B);
    Ordene_Elementos(tam_Intersec, ponteiro_Intersec);

    for (int i=0; i<tam_Intersec; i++){
        printf("%d\n", ponteiro_Intersec[i]);
    }


    free(ponteiro_Uniao);
    free(ponteiro_Intersec);
    return 0;
}