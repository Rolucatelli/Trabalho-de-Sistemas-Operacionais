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

void buscarListaTamanho(no *ptlista, int x, no **ant, no **pont)
{
    *pont = NULL;
    *ant = ptlista;
    no *ptr = ptlista->prox;

    while (ptr != NULL)
    {
        if (ptr->tamanho < x)
        {
            *ant = ptr;
            ptr = ptr->prox;
        }
        else
        {
            if (ptr->tamanho == x)
            {
                *pont = ptr;
            }
            ptr = NULL; // break;
        }
    }
}

void inserirListaTamanho(no *ptlista, no *novo_no)
{
    no *ant, *pont;
    buscarListaTamanho(ptlista, novo_no->tamanho, &ant, &pont);
    novo_no->prox = ant->prox;
    ant->prox = novo_no;
}

void inserirListaId(no *ptlista, no *novo_no)
{
    no *ant, *pont;
    buscarLista(ptlista, novo_no->id, &ant, &pont);
    novo_no->prox = ant->prox;
    ant->prox = novo_no;
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

void imprimirLista(no *ptlista)
{
    if (ptlista->prox == NULL)
    {
        printf("<lista vazia!>");
        return;
    }

    ptlista = ptlista->prox;

    printf("Processos restantes: ");
    while (ptlista != NULL)
    {

        printf("%d:%d", ptlista->id, ptlista->tamanho);
        ptlista = ptlista->prox;
        printf(" -> ");
        if (ptlista == NULL)
            printf("NULL\n");
    }
}

void ordenaListaTam(no **ptLista)
{
    no *pTemp = malloc(sizeof(no));
    pTemp->prox = NULL;
    if ((*ptLista)->prox != NULL)
    {
        int i = (*ptLista)->prox->id;
        no *aux = removerLista(*ptLista, i);
        while (aux != NULL)
        {
            inserirListaTamanho(pTemp, aux);
            if ((*ptLista)->prox != NULL)
            {
                i = (*ptLista)->prox->id;
            }
            aux = removerLista(*ptLista, i);
        }
        (*ptLista)->prox = pTemp->prox;
    }
    free(pTemp);
}