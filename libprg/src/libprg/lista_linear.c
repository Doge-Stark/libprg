


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "libprg/libprg.h"
//
// #define CAPACIDADE_INICIAL 10
//
// typedef struct lista {
//
//     int* elementos;
//     int tamanho;
//     int capacidade;
//     bool ordenada;
//
// }lista_linear_t;
//
// lista_linear_t* criar_lista(bool ordenada)
// {
//
//     lista_linear_t* lista = malloc(sizeof(lista_linear_t));
//     lista->elementos = malloc(sizeof(int) * CAPACIDADE_INICIAL);
//     lista->tamanho = 0;
//     lista->capacidade = CAPACIDADE_INICIAL;
//     lista->ordenada = ordenada;
//     return lista;
//
// }
//
// void inserir(lista_linear_t* lista, int valor)
// {
//
//     if (lista->tamanho == lista->capacidade)
//     {
//         int nova_capacidade = lista->capacidade+1;
//         int* temp = realloc(lista->elementos, nova_capacidade * sizeof(int));
//
//         if (temp == NULL)
//             {printf("Falha na realocação de memoria."); return;}
//
//         lista->elementos = temp;
//         lista->capacidade = nova_capacidade;
//     }
//
//     lista->elementos[lista->tamanho] = valor;
//     lista->tamanho++;
//     lista->capacidade++;
// }
//
// int buscar(lista_linear_t* lista, int valor)
// {
//
//     for (int i = lista->tamanho-1; i > 0 ; i--)
//     {
//         if ( lista->elementos[i] == valor )
//         {
//             printf("O iten %d está na posição %d da lista.", lista->elementos[i], i);
//             return i;
//         }
//
//             printf("O iten não está na lista");
//             return -1;
//
//     }
//
// }
//
// void retirar(lista_linear_t* lista, int alvo)
// {
// }

//alterar(){}
//ordenar(){}
//combinar(){}
//destruir(){}

//buscar {
//          if(lista->ordenada) {indice = buscar_binario } else
//                                                              { indice = buscar_linear }
//                                                                                          }
//buscar_linear(){};
//buscar_binario(){};
//buscar_simples(){};