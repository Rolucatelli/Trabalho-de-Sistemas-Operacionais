#include <stdio.h>
#include <stdlib.h>

#include "../hdr/geral.h"
#include "../hdr/lista.h"

void nextFit(int delay, int *memoria, int printMemoria, int printMemoriaArquivo)
{
    int processosCriados = 0;
    int i;
    limparArquivo("exe/log/nextFitLog.txt");    // Se existir algo no arquivo, a função vai apagar
    no *listaDeEspera = malloc(sizeof(no));     // Criando uma estrutura para armazenar processos para serem alocados na memória
    no *processosAlocados = malloc(sizeof(no)); // Criando uma estrutura para armazenar processos já alocados na memória
    listaDeEspera->prox = NULL;
    processosAlocados->prox = NULL;

    while (1)
    {
        FILE *arquivo = fopen("exe/log/nextFitLog.txt", "a");
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
            int ant = i - 1;
            i = i % 2048;
            while (i != ant) // Por conta que esse é o algoritmo de Next Fit, a condição deve ser mudada para ele percorer a memória toda
            {
                if (memoria[i] == 0) // Verifica se a posição está vazia
                {
                    cabe = 1;
                    int j;
                    // Verifica se o processo cabe na memória
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
                        // Se o processo cabe na memória, aloca ele
                        for (int j = 0; j < noAtual->tamanho && (i + j) < 2048; j++)
                        {
                            memoria[i + j] = id;
                        }
                        noAtual->prox = NULL;
                        inserirListaFim(processosAlocados, noAtual); // Insere o processo na lista de processos alocados
                        printf(CIANO "Processo " AMARELO "%d " CIANO "alocado de " AMARELO "%d" CIANO " até " AMARELO "%d\n" RESET, id, i, i + noAtual->tamanho);
                        fprintf(arquivo, "Processo %d alocado de %d até %d\n", id, i, i + noAtual->tamanho);
                        sleep(delay);
                        if (printMemoria)
                        {
                            imprimeMemoria(memoria);
                        }
                        if (printMemoriaArquivo)
                        {
                            imprimeMemoriaArquivo(memoria, arquivo);
                        }

                        i += noAtual->tamanho;
                        break;
                    }
                }
                i = (i + 1) % 2048; // Incrementa a posição
            }
            if (!cabe) // Se o processo não couber na memória, insere ele no comeco da lista de espera
            {
                inserirListaInicio(listaDeEspera, noAtual);
            }
        }
        fclose(arquivo); // Fecha o arquivo para ele atualizar as informações a cada iteração
    }
}