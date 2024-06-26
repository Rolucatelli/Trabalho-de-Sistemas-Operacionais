#ifndef _H_FIRSTFIT
#define _H_FIRSTFIT

#include "geral.h"

/**
 * @brief Aloca processos na memória utilizando o algoritmo First Fit
 * @param delay: Delay entre as alocações
 * @param *memoria: Ponteiro para a memória
 * @param printMemoria: Flag para imprimir a memória
 * @param printMemoriaArquivo: Flag para imprimir a memória no arquivo
 */
void firstFit(int delay, int *memoria, int printMemoria, int printMemoriaArquivo);

#endif // _H_FIRSTFIT