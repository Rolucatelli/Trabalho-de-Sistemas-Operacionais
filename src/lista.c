#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"

void buscarLista(no *ptlista, int x, no **ant, no **pont)
{
    *pont = NULL;
    *ant = ptlista;
    no *ptr = ptlista->prox;

    while (ptr != NULL)
    {
        if (ptr->id < x)
        {
            *ant = ptr;
            ptr = ptr->prox;
        }
        else
        {
            if (ptr->id == x)
            {
                *pont = ptr;
            }
            ptr = NULL; // break;
        }
    }
}

int pegarNoAleatorio(no *ptlista)
{
    no *aux = ptlista->prox;
    int i = 0;
    while (aux != NULL)
    {
        i++;
        aux = aux->prox;
    }
    int random = rand() % i;
    aux = ptlista->prox;
    for (int j = 0; j < random; j++)
    {
        aux = aux->prox;
    }
    return aux->id;

}

void inserirListaFim(no *ptlista, no *novo_no)
{
    no *ant = ptlista;
    while (ant->prox != NULL)
    {
        ant = ant->prox;
    }
    ant->prox = novo_no;
    novo_no->prox = NULL;
}

void inserirListaInicio(no *ptlista, no *novo_no)
{
    novo_no->prox = ptlista->prox;
    ptlista->prox = novo_no;
}

no *removerLista(no *ptlista, int x)
{
    no *ant, *pont;
    buscarLista(ptlista, x, &ant, &pont);
    if (pont != NULL)
    {
        ant->prox = pont->prox;
        return pont;
    }
    else
    {
        return NULL;
    }
}