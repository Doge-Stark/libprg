//
// Created by aluno on 14/05/2026.
//

#include <stdlib.h>
#include "libprg/libprg.h"
#include <string.h>

int hash(char* chave,int n);

typedef struct noh {

    char* chave;
    int valor;
    noh_t* proximo;

}noh_t;

typedef struct dicionario {

    int tamanho;
    noh_t** vetor;

}dicionario_t;

dicionario_t* criar_dicionario(int n) {

    dicionario_t* d;
    if ( n < 1) return NULL;
    d = malloc(sizeof(dicionario_t));
    d->vetor = malloc(n * sizeof(noh_t*));
    d->tamanho = n;

    return d;
}

int hash(char* chave,int n){

    int soma = 0;
    for (int i = 0; chave[i] != '\0';i++){

        soma += (i+1) * chave[i];;
    }

    return soma % n;
}

int inserir_hash(dicionario_t* d, char* chave,int valor) {

    int indice = hash(chave,d->tamanho);
    noh_t* no = malloc(sizeof(noh_t));
    if (no == NULL) return 1;

    no->chave = strdup(chave);
    if (no->chave == NULL) {
        free(no);
        return 1;
    }

    no->valor = valor;

    // TODO tratar colisões;

    no->proximo = NULL;

    d->vetor[indice] = no;

    return 0;
}