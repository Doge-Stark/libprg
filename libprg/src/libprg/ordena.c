//
// Created by aluno on 07/05/2026.
//
#include "libprg/libprg.h"
#include <stdbool.h>
#include <stdio.h>

int* buble_sort(int *vetor, int tamanho)
{
    int aux = 0;

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
           if (vetor[j] > vetor[j + 1])
           {
               aux = vetor[j];
               vetor[j] = vetor[j + 1];
               vetor[j + 1] = aux;
           }
        }
    }

    return vetor;
}

int* insertion_sort(int *vetor, int tamanho) {

    int sorted;

    for (int i = 0; i < tamanho; i++) {
        sorted = vetor[i];
        if ( sorted > vetor[i]) sorted = vetor[i+1];
        while (vetor[i + 1] > sorted) {
            {
                int temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;

            }
        }
    }


    }

int* selection_sort(int *vetor, int tamanho) {

    int mini_number;

    for (int i = 0; i < tamanho; i++) {
        mini_number = vetor[i];
        for (int j = i + 1; j < tamanho; j++) {
            if ( mini_number > vetor[j]) {
                int temp = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = temp;

            }
        }



    }



}