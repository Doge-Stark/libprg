//
// Created by aluno on 26/03/2026.
//

#include <stdlib.h>
#include <stdio.h>

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

int desenfilerar(fila_t* fila) {

    int valorant = fila->inicio;

    // Verificação de overflow;

    if ( fila->tamanho == 0) {
        printf("Erro: Fila vazia( Underflow");
        exit(EXIT_FAILURE);
    }

    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    return valorant;
}

int fila_vazia(fila_t* fila)
{
    if (fila->tamanho == 0) return 1;
}


int fila_inicio(fila_t* fila)
{
    if (fila_vazia(fila)) exit(EXIT_FAILURE);
    int inicio_fila;
    inicio_fila = fila->inicio;
    return inicio_fila;

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
    if (fila->tamanho == fila->capacidade) return 1;

}

int destruir_fila(fila_t* fila) {

    free(fila->elementos);
    free(fila);

    return 0;
}



