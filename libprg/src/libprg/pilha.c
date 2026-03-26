//
// Created by aluno on 17/03/2026.
//


#include <stdlib.h>
#include <stdio.h>


typedef struct pilha {

    int* elementos;
    int topo;
    int tamanho;

}pilha_t;

// Função cria a pilha;

pilha_t* criar_pilha(int capacidade) {
    pilha_t* pilha = malloc(sizeof(pilha_t));
    pilha->elementos = malloc(sizeof(int) * capacidade);
    pilha->topo = -1;
    pilha->tamanho = capacidade;
    return pilha;
}

// Função empilhar a pilha;

int empilhar(pilha_t* pilha, int valor) {

    if (pilha->topo >= pilha->tamanho) {
        pilha->tamanho  *= 2;
        pilha->elementos = realloc(pilha->elementos, sizeof(int) * pilha->tamanho);
    } else
        pilha->topo++;
        pilha->elementos[pilha->topo] = valor;

    return 0;
}

// Função desempilhar a pilha;

int desempilhar(pilha_t* pilha) {

    if (pilha->topo < 0) {
        exit(EXIT_FAILURE);
    }

    int valor = pilha->elementos[pilha->topo];
    pilha->topo--;
    return valor;

}

// Função diz tamanho da pilha;

int tamanho(pilha_t* pilha) {
    int N = pilha->tamanho;
    return N;
}

// Função verifica se a pilha está vazia;

int vazia(pilha_t* pilha) {return pilha->topo < 0;}

// Função destroi a pilha;

int destruir_pilha(pilha_t* pilha) {

    free(pilha->elementos);
    free(pilha);
    return 0;

}
