#ifndef _H_FILA
#define _H_FILA

#include "../hdr/geral.h"

/*
    @brief Insere um novo nó na fila
    @param **f Ponteiro para o inicio da fila
    @param **r Ponteiro para o final da fila
    @param *novoNo Ponteiro para o novo nó
*/
void inserirFila(no **f, no **r, no *novoNo);

/*
    @brief Remove o primeiro elemento da fila
    @param **f Ponteiro para o inicio da fila
    @param **r Ponteiro para o final da fila
    @return Ponteiro para o nó removido
*/
no *removerFila(no **f, no **r);

/* 
    @brief Imprime a fila
    @param *inicio Ponteiro para o inicio da fila
*/
void imprimirFila(no *inicio);

#endif