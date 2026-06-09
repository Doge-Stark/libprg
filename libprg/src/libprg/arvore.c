//
// Created by aluno on 19/05/2026.
//

#include <stdlib.h>
#include <stdio.h>
#include "libprg/libprg.h"

typedef struct no_arvore {
    int dado;
    no_arvore_t *filho_esquerda;
    no_arvore_t *filho_direita;
} no_arvore_t;

no_arvore_t *criar_no(int dado) {
    no_arvore_t *no = malloc(sizeof(no_arvore_t));
    no->dado = dado;
    no->filho_esquerda = NULL;
    no->filho_direita = NULL;

    return no;
}

no_arvore_t *adicionar(no_arvore_t *raiz, int dado) {
    // Verifica se o nó está vazio e cria um novo nó;
    if (raiz == NULL) {
        return criar_no(dado);
    }

    // verifica se o dado e maior que a raiz e aloca ele para o nó filho da direita ( Recursivamente );
    if (raiz->dado < dado) { raiz->filho_direita = adicionar(raiz->filho_direita, dado); }

    // verifica se o dado e menor que a raiz e aloca ele para o nó filho da esquerda ( Recursivamente );
    if (raiz->dado > dado) { raiz->filho_esquerda = adicionar(raiz->filho_esquerda, dado); }

    return raiz;
}

no_arvore_t *remover_noa (no_arvore_t * raiz, int valor) {

    if (raiz == NULL) return NULL;

    if (valor < raiz->dado) {
        raiz->filho_esquerda = remover_noa(raiz->filho_esquerda,valor);
    } else if (valor > raiz->dado) {
        raiz->filho_direita = remover_noa(raiz->filho_direita,valor);
    } else {
        if ((raiz->filho_esquerda == NULL) || (raiz->filho_direita == NULL)) { // 1 ou 0 filhos
            no_arvore_t* temp = raiz->filho_esquerda ? raiz->filho_esquerda : raiz->filho_direita;
            if (temp == NULL) {
                free(raiz);
                return NULL;
            }
            free(raiz);
            return temp;
        } else {
            no_arvore_t * temp = raiz->filho_direita;
            while (temp != NULL && temp->filho_esquerda != NULL) {
                temp = temp->filho_esquerda;
            }
            raiz->dado = temp->dado;
            raiz->filho_direita = remover_noa(raiz->filho_direita, temp->dado);
        }
    }
    return raiz;
}

no_arvore_t *destruir_arvore(no_arvore_t *raiz) {
    if (raiz == NULL) return NULL;

    destruir_arvore(raiz->filho_esquerda);
    destruir_arvore(raiz->filho_direita);

    free(raiz);

    return NULL;
}

void travessia_preordem(no_arvore_t *raiz) {
    if (raiz == NULL) return;
    printf("%d, ", raiz->dado);
    travessia_preordem(raiz->filho_esquerda);
    travessia_preordem(raiz->filho_direita);
}

void travessia_emordem(no_arvore_t *raiz) {
    if (raiz == NULL) return;

    travessia_emordem(raiz->filho_esquerda);
    printf("%d, ", raiz->dado);
    travessia_emordem(raiz->filho_direita);
}

void travessia_posordem(no_arvore_t *raiz) {
    if (raiz == NULL) return;

    travessia_posordem(raiz->filho_esquerda);
    travessia_posordem(raiz->filho_direita);
    printf("%d, ", raiz->dado);
}

int maior_valor(no_arvore_t *raiz) {
    if (raiz == NULL) return -1; // ou outro valor sentinela

    while (raiz->filho_direita != NULL) {
        raiz = raiz->filho_direita;
    }

    return raiz->dado;
}

int menor_valor(no_arvore_t *raiz) {
    if (raiz == NULL) return -1;

    while (raiz->filho_esquerda != NULL) {
        raiz = raiz->filho_esquerda;
    }

    return raiz->dado;
}

int altura_arvore(no_arvore_t *raiz) {
    if (raiz == NULL) return -1;

    int altura_esq = altura_arvore(raiz->filho_esquerda);
    int altura_dir = altura_arvore(raiz->filho_direita);

    if (altura_esq > altura_dir)
        return altura_esq + 1;
    else
        return altura_dir + 1;
}

