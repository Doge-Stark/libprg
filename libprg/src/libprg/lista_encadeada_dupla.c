//
// Created by aluno on 07/05/2026.
//

#include  <stdio.h>
#include  <stdlib.h>
#include "libprg/libprg.h"
#include <stdbool.h>

typedef struct no {

    int dado;
    no_t *proximo;
    no_t *anterior;

} no_t;

no_t *criar_lista_encadeada(int dado) {

    no_t *no = malloc(sizeof(no_t));
    no->dado = dado;
    no->proximo = NULL;
    no->anterior = NULL;

    return no;
}