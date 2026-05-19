//
// Created by aluno on 19/05/2026.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "libprg/libprg.h"

typedef struct no_arvore {

  int dado;
  no_arvore_t* filho_esquerda;
  no_arvore_t* filho_direita;

}no_arvore_t ;

no_arvore_t* criar_no(int dado) {

  no_arvore_t* no = malloc(sizeof(no_arvore_t));
  no->dado = dado;
  no->filho_esquerda = NULL;
  no->filho_direita = NULL;

}

no_arvore_t* adicionar(no_arvore_t* raiz, int dado) {

  // Verifica se o nó está vazio e cria um novo nó;
  if (raiz == NULL) { return criar_no(raiz->dado); }

  // verifica se o dado e maior que a raiz e aloca ele para o nó filho da direita ( Recursivamente );
  if (raiz->dado < dado) { raiz->filho_direita = adicionar(raiz->filho_direita, dado); }

  // verifica se o dado e menor que a raiz e aloca ele para o nó filho da esquerda ( Recursivamente );
  if (raiz->dado > dado) { raiz->filho_esquerda = raiz->filho_esquerda,dado; }

  return raiz;
}
no_arvore_t* remover(int dado) {




}



no_arvore_t* destruir(){}