#include <stdio.h>
#include <stdlib.h>

#include "../hdr/geral.h"
#include "../hdr/lista.h"


void firstFit(int delay, int *memoria){
    int processosCriados = 0;
    // Se existir algo no arquivo, a função vai apagar
    limparArquivo("exe/logs/firsFitLog.txt");
    printf("debug\n");
    no *ptLista = malloc(sizeof(no)); // Criando uma estrutura para alocar os processos.
    ptLista->prox = NULL;
    
    while (1)
    {
        FILE *arquivo = fopen("exe/log/firsFitLog.txt", "a");
        if (tentarCriarProcesso())
        {
            printf("dentro do if do tentar criar processo\n");
            no *novoNo = alocarNo(&processosCriados);
            inserirListaFim(ptLista, novoNo);

            printf("Processo %d criado com tamanho %d\n", novoNo->id, novoNo->tamanho);
            fprintf(arquivo, "Processo %d criado com tamanho %d\n", novoNo->id, novoNo->tamanho);
            
        }else{
            int posicao, tamanho, random = ((rand() % processosCriados) + 1);
            buscaMemoria(memoria, random, &posicao, &tamanho);
            limpaMemoria(memoria, posicao, tamanho);

            printf("Processo %d removido da posição %d\n", ((rand() % processosCriados) + 1), posicao);
            fprintf(arquivo, "Processo %d removido da posição %d\n", ((rand() % processosCriados) + 1), posicao);
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
                            printf("Processo %d alocado na posição %d\n", noAtual->id, i);
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