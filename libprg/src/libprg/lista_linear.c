


#include <stdlib.h>

typedef struct lista {

    int* elementos;
    int tamanho;
    int capacidade;

}lista_t;

lista_t* criar_criar(int capacidade)
{

    lista_t* lista = malloc(sizeof(lista_t));
    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->tamanho = 0;
    lista->capacidade = capacidade;

    return lista;

}

// TODO finalizar as funções;

void inserir(lista_t* lista, int valor)
{

    if (lista->tamanho == lista->capacidade) lista->capacidade = realloc(sizeof(int)*);

    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;




}
int retirar();
int buscar();


