


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "libprg/libprg.h"

// FUNÇÕES ULTILIZADAS PELO BUSCAR;

int buscar_linear(lista_linear_t* lista, int valor);
int buscar_binario(lista_linear_t* lista, int valor);

#define CAPACIDADE_INICIAL 10

typedef struct lista {

    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;

}lista_linear_t;

lista_linear_t* criar_lista_linear(bool ordenada)
{

    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int) * CAPACIDADE_INICIAL);
    lista->tamanho = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->ordenada = ordenada;
    return lista;

}

int inserir_lista_linear(lista_linear_t* lista, int valor)
{

    if (lista->tamanho == lista->capacidade)
    {
        int nova_capacidade = lista->capacidade+1;
        int* temp = realloc(lista->elementos, nova_capacidade * sizeof(int));

        if (temp == NULL)
            {printf("Falha na realocação de memoria."); return 0;}

        lista->elementos = temp;
        lista->capacidade = nova_capacidade;
    }

    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

lista_linear_t* retirar_lista_linear(lista_linear_t* lista, int alvo)
{
    int temp = buscar_linear(lista, alvo);

    for (int i = temp; i < lista->tamanho - 1; i++)
    {
        lista->elementos[i] = lista->elementos[i + 1];
    }

    lista->tamanho--;

    if (lista->ordenada == true)
    {
        ordenar_lista_linear(lista);
    }
    return lista;
}

int lista_linear_tamanho(lista_linear_t* lista) {

    return lista->tamanho;
}

int buscar(lista_linear_t* lista, int valor)
{
    if (lista->ordenada == true)
    {
        return buscar_binario(lista, valor);
    }
    return buscar_linear(lista, valor);
}

lista_linear_t* ordenar_lista_linear(lista_linear_t* lista)
{
    selection_sort(lista->elementos, lista->tamanho);
    return lista;
}

int buscar_linear(lista_linear_t* lista, int valor)
{
    for ( int i = 0; i < lista->tamanho; i++ )
    {
        if ( lista->elementos[i] == valor )
            return i;
    }
    printf("Elemento não encontrado.");
    return false;
};

int buscar_binario(lista_linear_t* lista, int valor)
{
    int temp; lista->tamanho / 2;

    // caso do valor ser o elemento do meio da lista;
    if (lista->elementos[temp] == valor) return printf("O valor : %d , está na %d° posição da lista.", lista->elementos[temp], temp );

    // caso do valor ser maior que o elemento do meio da lista;
    if ( lista->elementos[temp] < valor)
    {
        for ( int i = temp; i < lista->tamanho; i++ )
        {
            if (lista->elementos[temp] == valor);
            printf("O valor : %d , está na %d° posição da lista.", lista->elementos[i], i );
            return temp;
        }
    }

    // caso do valor ser menor que o meio da lista;
    if ( lista->elementos[temp] > valor)
    {
        for ( int i = temp; i > 0; i-- )
        {
            if (lista->elementos[temp] == valor);
            printf("O valor : %d , está na %d° posição da lista.", lista->elementos[i], i );
            return temp;
        }
    }

    printf("Elemento não encontrado.");
    return false;

};

int busca_indice(lista_linear_t* lista, int indice) {

return lista->elementos[indice];

}

lista_linear_t* alterar_lista_linear(lista_linear_t* lista, bool ordenada)
{
    if (lista->ordenada == true)
    {
       lista->ordenada = false;
    }
    lista->ordenada = true;

    return lista;
}

// TODO Perguntar ao professor sobre a função combinar

//combinar(){}
