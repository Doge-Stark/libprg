


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
    int inicio = 0;
    int fim = lista->tamanho - 1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        if (lista->elementos[meio] == valor)
        {
            return meio;
        }
        else if (lista->elementos[meio] < valor)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return false;
}

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
