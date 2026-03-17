//
// Created by aluno on 17/03/2026.
//


#include <stdlib.h>


typedef struct pilha {

    int* elementos;
    int topo;
    int tamanho;

}pilha_t;

// Função cria pilha;

pilha_t* criar_pilha(int capacidade) {
    pilha_t* pilha = malloc(sizeof(pilha_t));
    pilha->elementos = malloc(sizeof(int) * capacidade);
    pilha->topo = -1;
    pilha->tamanho = capacidade;
    return pilha;
}

// empilhar
// desempilhar
// tamanho
// vazia