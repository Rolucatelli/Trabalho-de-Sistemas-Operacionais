#ifndef _H_LISTA
#define _H_LISTA

#include "../hdr/geral.h"

/**
 * @brief Busca um elemento na lista pelo Id
 * @param *ptlista Ponteiro para o inicio da lista
 * @param x Id do elemento a ser buscado
 * @param **ant Ponteiro para o nó anterior ao elemento buscado
 * @param **pont Ponteiro para o elemento buscado
*/
void buscarLista(no *ptlista, int x, no **ant, no **pont);

/**
 * @brief Pega um nó aleatório da lista
 * @param *ptlista Ponteiro para o inicio da lista
 * @return Id do nó aleatório
 */
int pegarNoAleatorio(no *ptlista);

/**
 * @brief Insere um novo nó no fim da lista
 * @param *ptlista Ponteiro para o inicio da lista
 * @param *novo_no Ponteiro para o novo nó
 * @return Nada, pois é possível que haja nós repetidos na lista
*/
no *inserirListaFim(no *ptlista, no *novo_no);

/**
 * @brief Insere um novo nó no inicio da lista
 * @param *ptlista Ponteiro para o inicio da lista
 * @param *novo_no Ponteiro para o novo nó
 * @return Nada, pois é possível que haja nós repetidos na lista
*/
void inserirListaInicio(no *ptlista, no *novo_no);

/**
 * @brief Remove um elemento da lista
 * @param *ptlista Ponteiro para o inicio da lista
 * @param x Id do elemento a ser removido
 * @return Ponteiro para o nó removido
*/
no *removerLista(no *ptlista, int x);

#endif