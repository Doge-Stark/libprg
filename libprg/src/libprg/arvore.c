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

no_arvore_t* remover(no_arvore_t* raiz, int dado) {

  // caso de nó sem filhos;
  if ( raiz->filho_direita == NULL && raiz->filho_esquerda == NULL ) {
    free(raiz);
  }

  // caso de nó com apenas um filho;
  if ( raiz->filho_direita == NULL || raiz->filho_esquerda == NULL ) {
    if (raiz->filho_direita == NULL) {
      no_arvore_t* temp = raiz;
      raiz = raiz->filho_esquerda;
      free(temp);
    } else {
      no_arvore_t* temp = raiz;
      raiz = raiz->filho_direita;
      free(temp);
    }
  }

  // caso de nó com dois filhos;
  if ( raiz->filho_direita != NULL && raiz->filho_esquerda != NULL ) {

    no_arvore_t* predecessor = raiz->filho_esquerda;
    no_arvore_t* pai_predecessor = raiz;

    while ( predecessor->filho_direita!= NULL){
    pai_predecessor = predecessor;
      predecessor = predecessor->filho_direita;
    }
    raiz->dado = predecessor->dado;
    if (pai_predecessor->filho_direita == predecessor) {
      pai_predecessor->filho_direita = pai_predecessor->filho_esquerda;
    } else {
      pai_predecessor->filho_esquerda = pai_predecessor->filho_esquerda;
    }
    free(predecessor);
  }

  return raiz;
}

no_arvore_t* destruir_arvore(no_arvore_t* raiz) {
  if (raiz == NULL) return 0;

  destruir_arvore(raiz->filho_esquerda);
  destruir_arvore(raiz->filho_direita);

  free(raiz);

}

void travessia_preordem(no_arvore_t* raiz) {
  if (raiz != NULL)
  printf("%d, ", raiz->dado);
  travessia_preordem(raiz->filho_esquerda);
  travessia_preordem(raiz->filho_direita);
}

void travessia_emordem(no_arvore_t* raiz) {

  if (raiz != NULL)
    travessia_emordem(raiz->filho_esquerda);
    printf("%d, ", raiz->dado);
    travessia_emordem(raiz->filho_direita);
}

void travessia_posordem(no_arvore_t* raiz) {

  if (raiz != NULL)
  travessia_posordem(raiz->filho_esquerda);
  travessia_posordem(raiz->filho_direita);
  printf("%d, ", raiz->dado);
}