#include <stdio.h>
#include <stdlib.h>

#include "../hdr/geral.h"
#include "../hdr/lista.h"

void bestFit(int delay, int *memoria, int printMemoria, int printMemoriaArquivo)
{
    int processosCriados = 0;
    limparArquivo("exe/log/bestFitLog.txt");    // Se existir algo no arquivo, a função vai apagar
    no *listaDeEspera = malloc(sizeof(no));     // Criando uma estrutura para armazenar processos para serem alocados na memória
    no *processosAlocados = malloc(sizeof(no)); // Criando uma estrutura para armazenar processos já alocados na memória
    listaDeEspera->prox = NULL;
    processosAlocados->prox = NULL;

    while (1)
    {
        FILE *arquivo = fopen("exe/log/bestFitLog.txt", "a");
        if (tentarCriarProcesso()) // Verifica se deve criar um novo processo
        {
            // Se sim, cria um novo processo e adiciona ele na lista de espera
            no *novoNo = alocarNo(&processosCriados);
            inserirListaFim(listaDeEspera, novoNo);

            printf(VERDE "Processo " AMARELO "%d " VERDE "criado com tamanho " AMARELO "%d\n" RESET, novoNo->id, novoNo->tamanho);
            fprintf(arquivo, "Processo %d criado com tamanho %d\n", novoNo->id, novoNo->tamanho);
            sleep(delay);
        }
        else // Se não criou um novo processo, tenta remover um processo da memória
        {
            if (!memoriaVazia(memoria)) // Verifica se a memória está vazia
            {
                // Se não estiver vazia, remove um processo aleatório da memória
                int posicao, tamanho;
                int random = pegarNoAleatorio(processosAlocados); // Pega um processo aleatório da lista de processos alocados
                buscaMemoria(memoria, random, &posicao, &tamanho);
                limpaMemoria(memoria, posicao, tamanho); // Remove o processo da memória
                removerLista(processosAlocados, random); // Remove o processo da lista de processos alocados

                printf(VERMELHO "Processo " AMARELO "%d " VERMELHO "removido da posição " AMARELO "%d\n" RESET, random, posicao);
                fprintf(arquivo, "Processo %d removido da posição %d\n", random, posicao);
                sleep(delay);
                if (printMemoria)
                {
                    imprimeMemoria(memoria);
                }
                if (printMemoriaArquivo)
                {
                    imprimeMemoriaArquivo(memoria, arquivo);
                }
            }
        }

        if (listaDeEspera->prox) // Alocação de processos
        {
            // Se existir processos na lista de espera, tenta alocar um processo na memória
            no *noAtual = removerLista(listaDeEspera, listaDeEspera->prox->id);
            int id = noAtual->id;
            int cabe;
            int i;
            int sobra = 0;
            int bestSobra = 9999, bestI = -1;

            for (i = 0; i < 2048; i++)
            {
                if (memoria[i] == 0)
                {
                    cabe = 1;
                    int j;
                    for (j = 1; j < noAtual->tamanho && (i + j) < 2048; j++)
                    {
                        if (memoria[i + j] != 0)
                        {
                            cabe = 0;
                            j = noAtual->tamanho; // Break
                        }
                    }
                    if (i + j >= 2048)
                    {
                        cabe = 0;
                    }

                    if (cabe)
                    {
                        // Calculamos o espaço que sobrará após alocar o processo
                        while (memoria[i + j] == 0 && (i + j) < 2048)
                        {
                            sobra++;
                            j++;
                        }
                        int tmp = i - 1;
                        while (memoria[tmp] == 0 && tmp >= 0)
                        {
                            sobra++;
                            tmp--;
                        }
                        // Se o espaço que sobrará for menor que o melhor espaço que sobrou até agora, atualizamos o melhor espaço
                        if (sobra < bestSobra)
                        {
                            bestSobra = sobra;
                            bestI = i;
                        }
                        sobra = 0;
                    }
                }
            }
            if (bestI != -1) // Se encontramos um espaço para alocar o processo
            {
                // Alocamos o processo na memória
                for (int k = 0; k < noAtual->tamanho; k++)
                {
                    memoria[bestI + k] = id;
                }
                noAtual->prox = NULL;
                inserirListaFim(processosAlocados, noAtual); // Insere o processo na lista de processos alocados
                printf(CIANO "Processo " AMARELO "%d " CIANO "alocado de " AMARELO "%d" CIANO " até " AMARELO "%d\n" RESET, id, bestI, bestI + noAtual->tamanho);
                fprintf(arquivo, "Processo %d alocado de %d até %d\n", id, bestI, bestI + noAtual->tamanho);
                sleep(delay);
                if (printMemoria)
                {
                    imprimeMemoria(memoria);
                }
                if (printMemoriaArquivo)
                {
                    imprimeMemoriaArquivo(memoria, arquivo);
                }
            }
            else // Se o processo não couber na memória, insere ele no comeco da lista de espera
            {
                inserirListaInicio(listaDeEspera, noAtual);
            }
        }
        fclose(arquivo); // Fecha o arquivo para ele atualizar as informações a cada iteração
    }
}