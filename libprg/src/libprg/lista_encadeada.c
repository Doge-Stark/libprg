//
// Created by aluno on 30/04/2026.
//

#include  <stdio.h>
#include  <stdlib.h>
#include "libprg/libprg.h"
#include <stdbool.h>

typedef struct no {

    int dado;
    no_t *proximo;

} no_t;

no_t *criar_lista_encadeada(int dado) {

    no_t *no = malloc(sizeof(no_t));
    no->dado = dado;
    no->proximo = NULL;

    return no;
}

void inserir_lista_encadeada(no_t **inicio, int dado) {

    no_t *novo = criar_lista_encadeada(dado);
    novo->proximo = *inicio;
    *inicio = novo;

}

no_t* buscar_lista_encadeada(int dado, no_t **inicio) {

    no_t* atual = *inicio;
    no_t* anterior;

    while(atual != NULL) {
        if (atual->dado == dado) return atual;
        atual = atual->proximo;
    }

    return atual;

}

bool remover_lista_encadeada(no_t **inicio, int dado) {
    no_t* atual = *inicio;
    no_t* anterior = NULL;

    while(atual != NULL) {
        if (atual->dado == dado) {
            if (anterior == NULL) *inicio = atual->proximo;
            else anterior->proximo = atual->proximo;

            free(atual);
            return true;
        }

        anterior = atual;
        atual = atual->proximo;

    }

    return false;
}

void Destruir_lista_encadeada(no_t **inicio) {

    no_t* atual = *inicio;

    while ( *inicio != NULL ){
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}
