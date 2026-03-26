//
// Created by aluno on 26/03/2026.
//

#include <stdlib.h>

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

int enfilerar(fila_t* fila, int valor) {

    if (fila->tamanho >= fila->capacidade) exit(EXIT_FAILURE);

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;

}
    // TODO fazer as funções a baixo
// int desenfilerar(){}

// int inicio(){}

// int fim(){}

// int vazia(){}

// int cheia(){}

int destruir_fila(fila_t* fila) {

    free(fila->elementos);
    free(fila);

    return 0;
}



