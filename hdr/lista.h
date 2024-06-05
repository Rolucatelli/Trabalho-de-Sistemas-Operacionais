#ifndef _H_LISTA
#define _H_LISTA

#include "../hdr/geral.h"

/*
    @brief Busca um elemento na lista pelo Id
    @param *ptlista Ponteiro para o inicio da lista
    @param x Id do elemento a ser buscado
    @param **ant Ponteiro para o nó anterior ao elemento buscado
    @param **pont Ponteiro para o elemento buscado
*/
void buscarLista(no *ptlista, int x, no **ant, no **pont);

/*
    @brief Busca um elemento na lista pelo tamanho
    @param *ptlista Ponteiro para o inicio da lista
    @param x Id do elemento a ser buscado
    @param **ant Ponteiro para o nó anterior ao elemento buscado
    @param **pont Ponteiro para o elemento buscado
*/
void buscarListaTamanho(no *ptlista, int x, no **ant, no **pont);

/*
    @brief Insere um novo nó na lista por ordem de tamanho
    @param *ptlista Ponteiro para o inicio da lista
    @param *novo_no Ponteiro para o novo nó
    @return Nada, pois é possível que haja nós repetidos na lista
*/
no *inserirListaTamanho(no *ptlista, no *novo_no);

/*
    @brief Insere um novo nó na lista por ordem de id
    @param *ptlista Ponteiro para o inicio da lista
    @param *novo_no Ponteiro para o novo nó
    @return Nada, pois é possível que haja nós repetidos na lista
*/
no *inserirListaId(no *ptlista, no *novo_no);

/*
    @brief Insere um novo nó no fim da lista
    @param *ptlista Ponteiro para o inicio da lista
    @param *novo_no Ponteiro para o novo nó
    @return Nada, pois é possível que haja nós repetidos na lista
*/
no *inserirListaFim(no *ptlista, no *novo_no);

/*
    @brief Remove um elemento da lista
    @param *ptlista Ponteiro para o inicio da lista
    @param x Id do elemento a ser removido
    @return Ponteiro para o nó removido
*/
no *removerLista(no *ptlista, int x);

/*
    @brief Imprime a lista
    @param *ptlista Ponteiro para o inicio da lista
*/
void imprimirLista(no *ptlista);

/*
    @brief Ordena a lista por tamanho
    @param **ptLista: Um ponteiro pra o ptLista
*/
void ordenaListaTam(no **ptLista);

#endif