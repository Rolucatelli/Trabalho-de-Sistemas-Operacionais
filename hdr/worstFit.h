#ifndef _H_WORSTFIT
#define _H_WORSTFIT

#include "geral.h"

/**
 * @brief Aloca processos na memória utilizando o algoritmo Worst Fit
 * @param delay: Delay entre as alocações
 * @param *memoria: Ponteiro para a memória
 * @param printMemoria: Flag para imprimir a memória
 * @param printMemoriaArquivo: Flag para imprimir a memória no arquivo
 */
void worstFit(int delay, int *memoria, int printMemoria, int printMemoriaArquivo);

#endif // _H_WORSTFIT