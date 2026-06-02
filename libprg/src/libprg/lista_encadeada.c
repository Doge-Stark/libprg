//
// Created by aluno on 30/04/2026.
//

#include  <stdio.h>
#include  <stdlib.h>
#include "libprg/libprg.h"
#include <stdbool.h>

typedef struct no_encadeado {
    int dado;
    no_encadeado_t* proximo;
}no_encadeado_t;

typedef struct lista_encadeada {
    no_encadeado_t* inicio;
    bool ordenada;
}lista_encadeada_t;

no_encadeado_t* criar_no_encadeado(int dado) {
    no_encadeado_t* no = malloc(sizeof(no_encadeado_t));
    no->dado = dado;
    no->proximo = NULL;

    return no;
}

lista_encadeada_t *criar_lista_encadeada(bool ordenada) {
    lista_encadeada_t* lista = malloc(sizeof(lista_encadeada_t));
    lista->inicio = NULL;
    lista->ordenada = ordenada;

    return lista;
}

void inserir_encadeada(lista_encadeada_t* lista, int dado) {
    no_encadeado_t* novo = criar_no_encadeado(dado);
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

int primeiro_lista_encadeada(lista_encadeada_t *lista) {

    if (lista == NULL || lista->inicio == NULL)
        return -1;

    return lista->inicio->dado;
}

bool remover_lista_encadeada(lista_encadeada_t* lista, int dado) {

    no_encadeado_t* atual = lista->inicio;
    no_encadeado_t* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == dado) {
            if (anterior == NULL) lista->inicio = atual->proximo;
            else anterior->proximo = atual->proximo;

            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;

    }
    return false;
}

no_encadeado_t* buscar_lista_encadeada(lista_encadeada_t* lista, int indice){
    no_encadeado_t* atual = lista->inicio;

    while (atual != NULL) {
        if (atual->dado == indice) return atual;
        atual = atual->proximo;
    }
   return NULL;
}

int tamanho_lista_encadeada(lista_encadeada_t *lista) {

    int tamanho = 0;
    no_encadeado_t *atual = lista->inicio;

    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }

    return tamanho;
}

void imprimir_lista_encadeada(lista_encadeada_t *lista) {

    no_encadeado_t *atual = lista->inicio;

    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }

    printf("\n");
}

void destruir_lista_encadeada(lista_encadeada_t* lista) {

    no_encadeado_t* atual = lista->inicio;

    while (atual != NULL) {
        no_encadeado_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(lista);
}


