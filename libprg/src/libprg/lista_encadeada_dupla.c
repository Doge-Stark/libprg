//
// Created by aluno on 07/05/2026.
//

#include  <stdio.h>
#include  <stdlib.h>
#include "libprg/libprg.h"
#include <stdbool.h>

typedef struct no_duplo {
    int dado;
    no_duplo_t *proximo;
    no_duplo_t *anterior;
} no_duplo_t;

no_duplo_t *criar_lista_encadeada_dupla(int dado) {
    no_duplo_t *no = malloc(sizeof(no_duplo_t));

    if (no == NULL) {
        printf("Erro de memória\n");
        return 0;
    }

    no->dado = dado;
    no->proximo = NULL;
    no->anterior = NULL;

    return no;
}

void inserir_lista_encadeada_dupla(no_duplo_t **inicio, int dado) {
    no_duplo_t *novo = criar_lista_encadeada_dupla(dado);

    novo->proximo = *inicio;
    novo->anterior = NULL;

    if (*inicio != NULL) {
        (*inicio)->anterior = novo;
    }
    *inicio = novo;
}

no_duplo_t *buscar_lista_encadeada_dupla(int dado, no_duplo_t *inicio) {
    no_duplo_t *atual = inicio;

    while (atual != NULL) {
        if (atual->dado == dado) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

bool remover_lista_encadeada_dupla(no_duplo_t **inicio, int dado) {
    no_duplo_t *atual = *inicio;

    while (atual != NULL && atual->dado != dado) {
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf("Dado não encontrado\n");
        return 0;
    }
    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        *inicio = atual->proximo;
    }
    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
}

void Destruir_lista_encadeada_dupla(no_duplo_t **inicio) {
    no_duplo_t *atual = *inicio;

    while (*inicio != NULL) {
        no_duplo_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    *inicio = NULL;
}
