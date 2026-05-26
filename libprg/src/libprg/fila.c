//
// Created by aluno on 26/03/2026.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "libprg/libprg.h"

typedef struct fila {

    int* elementos;
    int capacidade; // quantos elementos são possiveis caber na fila;
    int tamanho; // quantidade de elementos na fila;
    int inicio;
    int fim;

}fila_t;

fila_t* criar_fila(int capacidade) {

    fila_t* fila = malloc(sizeof(fila_t));
    fila->elementos = malloc(sizeof(int) * capacidade);
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;

    return fila;

 }

void enfileirar_fila(fila_t* fila, int valor) {

    if (fila->tamanho >= fila->capacidade) exit(EXIT_FAILURE);

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

int desenfileirar_fila(fila_t* fila) {
    if (fila->tamanho == 0) {
        printf("Erro: Fila vazia(underflow)");
        exit(EXIT_FAILURE);
    }

    int valor = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;

    return valor;
}

int fila_vazia(fila_t* fila)
{
    if (fila->tamanho == 0) return true;
}


int inicio_fila(fila_t* fila) {
    if (fila_vazia(fila) == true) exit(EXIT_FAILURE);
    int inicio = fila->elementos[fila->inicio];
    return inicio;


}
int fila_fim(fila_t* fila)
{
    if (fila_vazia(fila)) exit(EXIT_FAILURE);
    int fim_corrigido = fila->fim - 1;
    if (fim_corrigido < 0 ) fim_corrigido = fila->capacidade - 1;
    return fila->elementos[fim_corrigido];

}

int fila_cheia(fila_t* fila)
{
    if (fila->tamanho == fila->capacidade) return true;

}

int destruir_fila(fila_t* fila) {
    free(fila->elementos);
    free(fila);

    return 0;
}

int tamanho_fila(fila_t* fila) {

    int tamanho = fila->tamanho;
    return tamanho;
}

