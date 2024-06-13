#ifndef _H_NEXTFIT
#define _H_NEXTFIT

#include "geral.h"

/**
 * @brief Aloca processos na memória utilizando o algoritmo Next Fit
 * @param delay: Delay entre as alocações
 * @param *memoria: Ponteiro para a memória
 * @param printMemoria: Flag para imprimir a memória
 * @param printMemoriaArquivo: Flag para imprimir a memória no arquivo
 */
void nextFit(int delay, int *memoria, int printMemoria, int printMemoriaArquivo);

#endif // _H_NEXTFIT