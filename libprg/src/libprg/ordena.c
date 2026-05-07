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

int* insertion_sort(){}

int* selection_sort(){}