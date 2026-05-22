//
// Created by aluno on 07/05/2026.
//
#include "libprg/libprg.h"
#include <stdbool.h>
#include <stdio.h>

int *merge(int *vetor, int esquerda, int meio, int direita);

int *buble_sort(int *vetor, int tamanho) {
    int aux = 0;

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

    return vetor;
}

int *insertion_sort(int *vetor, int tamanho) {

    int aux = 0;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;

            }
        }
    }
}

int *selection_sort(int *vetor, int tamanho) {

    for (int i = 0; i < tamanho - 1; i++) {

        int minimo = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[minimo]) {
                minimo = j;
            }
        }


        if (minimo != i) {
            int temp = vetor[i];
            vetor[i] = vetor[minimo];
            vetor[minimo] = temp;
        }
    }
    return vetor;
}

int *merge_sort(int *vetor, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        merge_sort(vetor, esquerda, direita);
        merge_sort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
    return vetor;
}

int *merge(int *vetor, int esquerda, int meio, int direita) {
    int aux[direita - esquerda + 1];

    int i = esquerda, j = (meio + 1), k = 0;

    while (i <= meio && j <= direita) {
        if (vetor[i] <= vetor[j]) {
            aux[k] = vetor[i];
            i = i + 1;
        } else {
            aux[k] = vetor[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i <= meio) {
        aux[k] = vetor[i];
        i = i + 1;
        k = k + 1;
    }

    while (j <= direita) {
        aux[k] = vetor[j];
        j = j + 1;
        k = k + 1;
    }

    for (int i = 0; i < esquerda; i++) {
        vetor[i] = aux[i - esquerda];
    }
}

int *quick_sort(int *vetor, int esquerda, int direita) {












}
