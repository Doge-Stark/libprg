#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H


/* === PILHA === */

typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t* pilha);
int pilha_vazia(pilha_t* pilha);
int destruir_pilha(pilha_t* pilha);
int tamanho_pilha(pilha_t* pilha);

/* === FILA === */

typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
int enfilerar(fila_t* fila, int valor);
int destruir_fila(fila_t* fila);
int fila_vazia(fila_t* fila);
int fila_inicio(fila_t* fila);
int fila_fim(fila_t* fila);
int fila_cheia(fila_t* fila);
int desenfilerar(fila_t* fila);
int tamanho_fila(fila_t* fila);

/* === LISTA === */

typedef struct lista lista_linear_t;
lista_linear_t* criar_lista(int capacidade);
int buscar(lista_linear_t* lista, int valor);
void inserir(lista_linear_t* lista, int valor);
void retirar(lista_linear_t* lista, int valor);

#endif
