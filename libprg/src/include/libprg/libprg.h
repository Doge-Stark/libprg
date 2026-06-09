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
void destruir_fila(fila_t* fila);
bool fila_vazia(fila_t* fila);
int inicio_fila(fila_t* fila);
int fila_fim(fila_t* fila);
bool fila_cheia(fila_t* fila);
int desenfileirar_fila(fila_t* fila);
int tamanho_fila(fila_t* fila);

/* === LISTA === */

typedef struct lista lista_linear_t;
lista_linear_t* criar_lista_linear(bool ordenada);
int inserir_lista_linear(lista_linear_t* lista, int valor);
lista_linear_t* retirar_lista_linear(lista_linear_t* lista, int valor);
lista_linear_t* ordenar_lista_linear(lista_linear_t* lista);
lista_linear_t* alterar_lista_linear(lista_linear_t* lista, bool ordenada);
int lista_linear_tamanho(lista_linear_t* lista);
int buscar(lista_linear_t* lista, int valor);
int busca_indice(lista_linear_t* lista, int indice);

/* === LISTA ENCADEADA === */

typedef struct no_encadeado no_encadeado_t;
typedef struct lista_encadeada lista_encadeada_t;

no_encadeado_t* criar_no_encadeado(int dado);
lista_encadeada_t *criar_lista_encadeada(bool ordenada);
void inserir_encadeada(lista_encadeada_t* lista, int dado);
int primeiro_lista_encadeada(lista_encadeada_t *lista);
bool remover_lista_encadeada(lista_encadeada_t* lista, int dado);
no_encadeado_t* buscar_lista_encadeada(lista_encadeada_t* lista, int dado);
int tamanho_lista_encadeada(lista_encadeada_t *lista);
void imprimir_lista_encadeada(lista_encadeada_t *lista);
void destruir_lista_encadeada(lista_encadeada_t* lista);

/* === LISTA ENCADEADA DUPLA === */

typedef struct no_duplo no_duplo_t;

no_duplo_t* criar_lista_encadeada_dupla(int dado);
void inserir_lista_encadeada_dupla(no_duplo_t** inicio, int dado);
no_duplo_t* buscar_lista_encadeada_dupla(int dado, no_duplo_t *inicio);
void Destruir_lista_encadeada_dupla(no_duplo_t **inicio);
bool remover_lista_encadeada_dupla(no_duplo_t **inicio, int dado);

/* === AlGORITIMOS DE ORDENAÇÃO === */

// Troca e seleção;
int* buble_sort(int *vetor, int tamanho);
int* insertion_sort(int *vetor, int tamanho);
int* selection_sort(int *vetor, int tamanho);

// Divisão e conquista;
int* merge_sort(int *vetor, int inicio ,int direita );
int* quick_sort(int *vetor, int esquerda, int direita );

/* === TABELA DE DISPERSÃO === */

typedef struct noh noh_t;
typedef struct dicionario dicionario_t;

dicionario_t* criar_dicionario(int n);
int inserir_hash(dicionario_t* d, char* chave,int valor);
int buscar_hash(dicionario_t *d, char *chave, int *valor);
int remover_hash(dicionario_t *d, char *chave);
void imprimir_tabela(dicionario_t *d);

/* === ARVORE === */

typedef struct no_arvore no_arvore_t;

no_arvore_t* criar_no(int dado);
no_arvore_t* adicionar(no_arvore_t* raiz, int dado);
no_arvore_t* remover(no_arvore_t* raiz, int dado);
no_arvore_t* destruir_arvore(no_arvore_t* raiz);


// Busca na arvore binária;
void travessia_preordem(no_arvore_t* raiz);
void travessia_emordem(no_arvore_t* raiz);
void travessia_posordem(no_arvore_t* raiz);
int altura_arvore(no_arvore_t *raiz);
int maior_valor(no_arvore_t *raiz);
int menor_valor(no_arvore_t *raiz);


/* === ARVORE AVL === */

typedef struct noavl noavl_t;

noavl_t* criar_no_avl(int dado);
int altura_avl(noavl_t* raiz);
int fator_balanceamento(noavl_t* raiz);
noavl_t *remover_noavl(noavl_t *raiz, int valor);
noavl_t* adicionar_noavl(noavl_t* raiz, int dado);
noavl_t* rotacao_esquerda(noavl_t* v);
noavl_t* rotacao_direita(noavl_t* v);
noavl_t* rotacao_dupla_esquerda(noavl_t* v);
noavl_t* rotacao_dupla_direita(noavl_t* v);
noavl_t* balancear(noavl_t* v);

#endif
