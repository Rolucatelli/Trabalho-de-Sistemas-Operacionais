#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"

void inserirFila(no **f, no **r, no *novoNo)
{
    if (*r == NULL)
    {
        *f = *r = novoNo;
    }
    else
    {
        (*r)->prox = novoNo;
        *r = novoNo;
    }
}

no *removerFila(no **f, no **r)
{
    no *retorno = NULL;
    if (*f != NULL)
    {
        retorno = *f;
        *f = retorno->prox;
        if (*f == NULL)
        {
            *r = *f;
        }
    }
    return retorno;
}

void imprimirFila(no *inicio)
{
    if (inicio == NULL)
    {
        printf("Sem processos na fila!\n");
        return;
    }

    printf("Processos restantes: ");
    while (inicio != NULL)
    {
        printf("%d:%d", inicio->id, inicio->tamanho);
        inicio = inicio->prox;
        if (inicio != NULL)
            printf(" -> ");
    }
    printf("\n");
}