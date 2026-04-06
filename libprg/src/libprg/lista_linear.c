


#include <stdlib.h>
#include <stdio.h>

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

void inserir(lista_t* lista, int valor)
{

    if (lista->tamanho == lista->capacidade)
    {
        int nova_capacidade = lista->capacidade+1;
        int* temp = realloc(lista->elementos, nova_capacidade * sizeof(int));

        if (temp == NULL)
            {printf("Falha na realocação de memoria."); return;}

        lista->elementos = temp;
        lista->capacidade = nova_capacidade;
    }

    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
    lista->capacidade++;
}
int retirar();
int buscar();


