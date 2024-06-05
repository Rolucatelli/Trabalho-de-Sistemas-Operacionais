#include <stdio.h>
#include <stdlib.h>

#include "../hdr/geral.h"
#include "../hdr/lista.h"


void firstFit(int delay, int *memoria){
    int processosCriados = 0;
    // Se existir algo no arquivo, a função vai apagar
    limparArquivo("exe/logs/firsFitLog.txt");
    no *ptLista = malloc(sizeof(no)); // Criando uma estrutura para alocar os processos.
    ptLista->prox = NULL;
    printf("debug");
    
    while (1)
    {
        FILE *arquivo = fopen("exe/logs/firsFitLog.txt", "a");
        if (tentarCriarProcesso())
        {
            no *novoNo = alocarNo(&processosCriados);
            inserirListaFim(ptLista, novoNo);
            
        }else{
            int posicao, tamanho;
            buscaMemoria(memoria, ((rand() % processosCriados) + 1), &posicao, &tamanho);
            limpaMemoria(memoria, posicao, tamanho);
        }

        if (ptLista->prox)
        {
            no *noAtual = removerLista(ptLista, ptLista->prox->id);
            int i;

            for (i = 0; i < 2048; i++)
            {
                if (memoria[i] == 0)
                {
                    for (int j = 0; j < noAtual->tamanho; j++)
                    {
                        if (memoria[i + j] != 0)
                        {
                            break;
                        }
                        if (j == noAtual->tamanho - 1)
                        {
                            for (int k = 0; k < noAtual->tamanho; k++)
                            {
                                memoria[i + k] = noAtual->id;
                            }
                            fprintf(arquivo, "Processo %d alocado na posição %d\n", noAtual->id, i);
                            break;
                        }
                    }
                }
                printf("Memória: ");
                
            }


            
            
        }
        


        
        
    }
    

}