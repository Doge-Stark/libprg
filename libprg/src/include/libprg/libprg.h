#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H


/* === PILHA === */

typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t* pilha);
int vazia(pilha_t* pilha);
int destruir_pilha(pilha_t* pilha);

/* === FILA === */

typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
int enfilerar(fila_t* fila, int valor);
int destruir_fila(fila_t* fila);
int vazia(fila_t* fila);
int inicio(fila_t* fila);
int fim(fila_t* fila);
int cheia(fila_t* fila);

#endif
