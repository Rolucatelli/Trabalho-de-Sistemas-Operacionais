#ifndef _H_BESTFIT
#define _H_BESTFIT

#include "geral.h"

/**
 * @brief Aloca processos na memória utilizando o algoritmo Best Fit
 * @param delay: Delay entre as alocações
 * @param *memoria: Ponteiro para a memória
 * @param printMemoria: Flag para imprimir a memória
 * @param printMemoriaArquivo: Flag para imprimir a memória no arquivo
 */
void bestFit(int delay, int *memoria, int printMemoria, int printMemoriaArquivo);

#endif // _H_BESTFIT