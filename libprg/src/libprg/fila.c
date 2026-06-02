//
// Created by aluno on 26/03/2026.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "libprg/libprg.h"

typedef struct fila {

    int *elementos;   // elementos armazenados
    int capacidade;   // capacidade máxima
    int tamanho;      // quantidade atual de elementos
    int inicio;       // índice do primeiro elemento
    int fim;          // próxima posição de inserção

} fila_t;

fila_t* criar_fila(int capacidade)
{
    if (capacidade <= 0)
        return NULL;

    fila_t *fila = malloc(sizeof(fila_t));

    if (fila == NULL)
        return NULL;

    fila->elementos = malloc(sizeof(int) * capacidade);

    if (fila->elementos == NULL) {
        free(fila);
        return NULL;
    }

    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;

    return fila;
}

bool fila_vazia(fila_t *fila)
{
    return fila->tamanho == 0;
}

bool fila_cheia(fila_t *fila)
{
    return fila->tamanho == fila->capacidade;
}

void enfileirar_fila(fila_t *fila, int valor)
{
    if (fila_cheia(fila)) {
        fprintf(stderr, "Erro: fila cheia (overflow)\n");
        exit(EXIT_FAILURE);
    }

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

int desenfileirar_fila(fila_t *fila)
{
    if (fila_vazia(fila)) {
        exit(EXIT_FAILURE);
    }

    int valor = fila->elementos[fila->inicio];

    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;

    return valor;
}

int inicio_fila(fila_t *fila)
{
    if (fila_vazia(fila)) {
        fprintf(stderr, "Erro: fila vazia\n");
        exit(EXIT_FAILURE);
    }

    return fila->elementos[fila->inicio];
}

int fim_fila(fila_t *fila)
{
    if (fila_vazia(fila)) {
        fprintf(stderr, "Erro: fila vazia\n");
        exit(EXIT_FAILURE);
    }

    int indice_fim =
        (fila->fim - 1 + fila->capacidade) % fila->capacidade;

    return fila->elementos[indice_fim];
}

int tamanho_fila(fila_t *fila)
{
    return fila->tamanho;
}

void destruir_fila(fila_t *fila)
{
    if (fila == NULL)
        return;

    free(fila->elementos);
    free(fila);
}

