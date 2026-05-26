//
// Created by aluno on 07/05/2026.
//

#include  <stdio.h>
#include  <stdlib.h>
#include "libprg/libprg.h"
#include <stdbool.h>

typedef struct no_duplo {

    int dado;
    no_t *proximo;
    no_t *anterior;

} no_duplo_t;

no_duplo_t* criar_lista_encadeada_dupla(int dado) {}
void inserir_lista_encadeada_dupla(no_duplo_t** inicio, int dado){}
no_duplo_t* buscar_lista_encadeada_dupla(int dado, no_duplo_t **inicio){}
void Destruir_lista_encadeada_dupla(no_duplo_t **inicio){}
bool remover_lista_encadeada_dupla(no_duplo_t **inicio, int dado){}