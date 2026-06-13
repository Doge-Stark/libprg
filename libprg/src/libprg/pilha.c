//
// Created by aluno on 17/03/2026.
//


#include <stdlib.h>
#include "libprg/libprg.h"


typedef struct pilha {

    int* elementos;
    int topo;
    int tamanho;

}pilha_t;

pilha_t* criar_pilha(int capacidade) {
    pilha_t* pilha = malloc(sizeof(pilha_t));
    pilha->elementos = malloc(sizeof(int) * capacidade);
    pilha->topo = -1;
    pilha->tamanho = capacidade;
    return pilha;
}

int empilhar(pilha_t* pilha, int valor) {

    if (pilha->topo >= pilha->tamanho - 1) {
        pilha->tamanho  *= 2;
        pilha->elementos = realloc(pilha->elementos, sizeof(int) * pilha->tamanho);
    }
        pilha->topo++;
        pilha->elementos[pilha->topo] = valor;

    return 0;
}

int desempilhar(pilha_t* pilha) {

    if (pilha->topo < 0) {
        exit(EXIT_FAILURE);
    }

    int valor = pilha->elementos[pilha->topo];
    pilha->topo--;
    return valor;

}

int tamanho_pilha(pilha_t* pilha) {

    if (pilha_vazia(pilha)) {
        return -1;
    }
    return pilha->elementos[pilha->topo];
}

int pilha_vazia(pilha_t* pilha) {return pilha->topo < 0;}

int destruir_pilha(pilha_t* pilha) {

    free(pilha->elementos);
    free(pilha);
    return 0;

}

int pilha_topo(pilha_t* pilha) {

    int temp = desempilhar(pilha);
    int topo = temp;
    empilhar(pilha, temp);

    return topo;
}