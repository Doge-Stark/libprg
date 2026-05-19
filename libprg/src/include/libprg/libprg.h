#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

/* === PILHA === */

typedef struct pilha pilha_t;

pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t* pilha);
int pilha_vazia(pilha_t* pilha);
int destruir_pilha(pilha_t* pilha);
int tamanho_pilha(pilha_t* pilha);
int pilha_topo(pilha_t* pilha);

/* === FILA === */

typedef struct fila fila_t;

fila_t* criar_fila(int capacidade);
void enfileirar_fila(fila_t* fila, int valor);
int destruir_fila(fila_t* fila);
int fila_vazia(fila_t* fila);
int inicio_fila(fila_t* fila);
int fila_fim(fila_t* fila);
int fila_cheia(fila_t* fila);
int desenfileirar_fila(fila_t* fila);
int tamanho_fila(fila_t* fila);

/* === LISTA === */

// typedef struct lista lista_linear_t;
// lista_linear_t* criar_lista(int capacidade);
// int buscar(lista_linear_t* lista, int valor);
// void inserir(lista_linear_t* lista, int valor);
// void retirar(lista_linear_t* lista, int valor);

/* === LISTA ENCADEADA === */

typedef struct no no_t;

no_t* criar_lista_encadeada(int dado);
void inserir_lista_encadeada(no_t** inicio, int dado);
no_t* buscar_lista_encadeada(int dado, no_t **inicio);
void Destruir_lista_encadeada(no_t **inicio);
bool remover_lista_encadeada(no_t **inicio, int dado);

/* === LISTA ENCADEADA DUPLA === */


/* === AlGORITIMOS DE ORDENAÇÃO === */

/* --> AlGORITIMOS TROCA E SELEÇÃO <-- */

int* buble_sort(int *vetor, int tamanho);
int* insertion_sort(int *vetor, int tamanho);
int* selection_sort(int *vetor, int tamanho);

/* --> AlGORITIMOS DIVISÃO E CONQUISTA <-- */

int* merge_sort(int *vetor, int inicio ,int direita );
int* quick_sort(int *vetor, int esquerda, int direita );


/* === TABELA DE DISPERSÃO === */

typedef struct noh noh_t;
typedef struct dicionario dicionario_t;

/* === ARVORE === */

typedef struct no_arvore no_arvore_t;

#endif
