#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../hdr/geral.h"

int tentarCriarProcesso()
{
    if (((int)(rand() % 100)) < 60)
    {
        return 1;
    }
    return 0;
}

no *alocarNo(int *processosCriados)
{
    no *retorno = malloc(sizeof(no));
    retorno->id = ++(*processosCriados);
    retorno->tamanho = (rand() % 200) + 1;
    retorno->prox = NULL;
    return retorno;
}

void lerOpcao(int *opcao)
{
    printf(AZUL "+-------------------------------------------------+\n");
    printf("| " CIANO "Simulador de Gerência de Memória" AZUL "                |\n");
    printf("+-------------------------------------------------+\n");
    printf("| " CIANO "Escolha uma opção:" AZUL "                              |\n");
    printf("| " VERMELHO "0 - Sair" AZUL "                                        |\n");
    printf("| " AMARELO "1 - Executar First-Fit" AZUL "                          |\n");
    printf("| " AMARELO "2 - Executar Next-Fit" AZUL "                           |\n");
    printf("| " AMARELO "3 - Executar Best-Fit" AZUL "                           |\n");
    printf("| " AMARELO "4 - Executar Worst-Fit" AZUL "                          |\n");
    printf("| " VERDE "5 - Configurações de execução" AZUL "                   |\n");
    printf("+-------------------------------------------------+\n" RESET);
    printf("Opção: ");
    scanf("%d", opcao);
    system("clear");
}

void lerDelay(int *delay)
{
    printf(AZUL "+-------------------------------------------------+\n");
    printf("| " CIANO "Escolha o tempo, em segundos, entre mensagens:" AZUL "  |\n");
    printf("| " CIANO "(Caso não queira um tempo de espera, digite 0)" AZUL "  |\n");
    printf("+-------------------------------------------------+\n");
    printf("| " CIANO "Valor atual: " AMARELO "%d" AZUL "                                  |\n", *delay);
    printf("+-------------------------------------------------+\n" RESET);
    printf("Delay: ");
    scanf("%d", delay);
    system("clear");
}

void lerPrintMemoria(int *printMemoria)
{
    printf(AZUL "+-------------------------------------------------+\n");
    printf("| " CIANO "Deseja imprimir a memória a cada iteração?" AZUL "    |\n");
    printf("| " CIANO "Valor atual: " AMARELO "%d" AZUL "                                  |\n", *printMemoria);
    printf("+-------------------------------------------------+\n");
    printf("| " VERMELHO "0 - Não" AZUL "                                         |\n");
    printf("| " VERDE "1 - Sim" AZUL "                                         |\n");
    printf("+-------------------------------------------------+\n" RESET);
    printf("Opção: ");
    scanf("%d", printMemoria);
    system("clear");
}

void lerPrintMemoriaArquivo(int *printMemoriaArquivo)
{
    printf(AZUL "+-------------------------------------------------+\n");
    printf("| " CIANO "Deseja escrever a memória no arquivo de log?" AZUL "      |\n");
    printf("| " CIANO "Valor atual: " AMARELO "%d" AZUL "                                  |\n", *printMemoriaArquivo);
    printf("+-------------------------------------------------+\n");
    printf("| " VERMELHO "0 - Não" AZUL "                                         |\n");
    printf("| " VERDE "1 - Sim" AZUL "                                         |\n");
    printf("+-------------------------------------------------+\n" RESET);
    printf("Opção: ");
    scanf("%d", printMemoriaArquivo);
    system("clear");
}

void lerMenuConfig(int *escolha)
{
    printf(AZUL "+-------------------------------------------------+\n");
    printf("| " CIANO "Configurações de execução" AZUL "                       |\n");
    printf("+-------------------------------------------------+\n");
    printf("| " CIANO "Escolha uma opção:" AZUL "                              |\n");
    printf("| " VERMELHO "0 - Voltar" AZUL "                                      |\n");
    printf("| " AMARELO "1 - Alterar tempo de espera entre mensagens" AZUL "     |\n");
    printf("| " AMARELO "2 - Alterar impressão da memória" AZUL "                |\n");
    printf("| " AMARELO "3 - Escrever memória no arquivo de log" AZUL "          |\n");
    printf("+-------------------------------------------------+\n" RESET);
    printf("Opção: ");
    scanf("%d", escolha);
    system("clear");
}

void limparArquivo(char *arquivo)
{
    FILE *temp = fopen(arquivo, "w+");
    if (temp == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    fprintf(temp, "Log de execução:\n");
    fclose(temp);
}

void buscaMemoria(int *memoria, int id, int *posicao, int *tamanho)
{

    int i = 0;
    while (memoria[i] != id && i < 2048)
    {
        i++;
    }
    if (i >= 2048)
    {
        return;
    }
    *posicao = i;
    while (memoria[i] == id && i < 2048)
    {
        i++;
    }
    *tamanho = i - (*posicao);
}

void limpaMemoria(int *memoria, int posicao, int tamanho)
{
    for (int i = posicao; i < (posicao + tamanho); i++)
    {
        memoria[i] = 0;
    }
}

int memoriaVazia(int *memoria)
{
    for (int i = 0; i < 2048; i++)
    {
        if (memoria[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

void imprimeMemoria(int *memoria)
{
    int ant = 0;
    int atual = memoria[0];
    int i;
    printf("\nEstado da memória: \n");
    printf(AZUL "+--------------------------------+\n");
    for (i = 0; i < 2048; i++)
    {
        if (memoria[i] != atual)
        {
            if (atual)
            {
                if (atual < 10 && i - ant < 10)
                {
                    printf("| " CIANO "Processo " AMARELO "%d" CIANO " de tamanho %d" AZUL "        |\n", atual, i - ant);
                }
                else if (atual < 100 && i - ant < 10 || atual < 10 && i - ant < 100)
                {
                    printf("| " CIANO "Processo " AMARELO "%d" CIANO " de tamanho %d" AZUL "       |\n", atual, i - ant);
                }
                else if (atual < 1000 && i - ant < 10 || atual < 100 && i - ant < 100 || atual < 10 && i - ant < 1000)
                {
                    printf("| " CIANO "Processo " AMARELO "%d" CIANO " de tamanho %d" AZUL "      |\n", atual, i - ant);
                }
                else if (atual < 1000 && i - ant < 100 || atual < 100 && i - ant < 1000)
                {
                    printf("| " CIANO "Processo " AMARELO "%d" CIANO " de tamanho %d" AZUL "     |\n", atual, i - ant);
                }
                else
                {
                    printf("| " CIANO "Processo " AMARELO "%d" CIANO " de tamanho %d" AZUL "    |\n", atual, i - ant);
                }

                printf("+--------------------------------+\n");
            }
            else
            {
                if (i - ant < 10)
                {
                    printf("| " VERDE "Espaço livre de tamanho %d" AZUL "      |\n", i - ant);
                }
                else if (i - ant < 100)
                {
                    printf("| " VERDE "Espaço livre de tamanho %d" AZUL "     |\n", i - ant);
                }
                else if (i - ant < 1000)
                {
                    printf("| " VERDE "Espaço livre de tamanho %d" AZUL "    |\n", i - ant);
                }
                else
                {
                    printf("| " VERDE "Espaço livre de tamanho %d" AZUL "   |\n", i - ant);
                }
                printf("+--------------------------------+\n");
            }
            ant = i;
            atual = memoria[i];
        }
    }
    if (atual)
    {
        if (atual < 10 && i - ant < 10)
        {
            printf("| " CIANO "Processo " AMARELO "%d" CIANO " de tamanho %d" AZUL "        |\n", atual, i - ant);
        }
        else if (atual < 100 && i - ant < 10 || atual < 10 && i - ant < 100)
        {
            printf("| " CIANO "Processo " AMARELO "%d" CIANO " de tamanho %d" AZUL "       |\n", atual, i - ant);
        }
        else if (atual < 1000 && i - ant < 10 || atual < 100 && i - ant < 100 || atual < 10 && i - ant < 1000)
        {
            printf("| " CIANO "Processo " AMARELO "%d" CIANO " de tamanho %d" AZUL "      |\n", atual, i - ant);
        }
        else if (atual < 1000 && i - ant < 100 || atual < 100 && i - ant < 1000)
        {
            printf("| " CIANO "Processo " AMARELO "%d" CIANO " de tamanho %d" AZUL "     |\n", atual, i - ant);
        }
        else
        {
            printf("| " CIANO "Processo " AMARELO "%d" CIANO " de tamanho %d" AZUL "    |\n", atual, i - ant);
        }

        printf("+--------------------------------+\n\n" RESET);
    }
    else
    {
        if (i - ant < 10)
        {
            printf("| " VERDE "Espaço livre de tamanho %d" AZUL "      |\n", i - ant);
        }
        else if (i - ant < 100)
        {
            printf("| " VERDE "Espaço livre de tamanho %d" AZUL "     |\n", i - ant);
        }
        else if (i - ant < 1000)
        {
            printf("| " VERDE "Espaço livre de tamanho %d" AZUL "    |\n", i - ant);
        }
        else
        {
            printf("| " VERDE "Espaço livre de tamanho %d" AZUL "   |\n", i - ant);
        }

        printf("+--------------------------------+\n\n" RESET);
    }
}

void imprimeMemoriaArquivo(int *memoria, FILE *arquivo)
{
    int ant = 0;
    int atual = memoria[0];
    int i;
    fprintf(arquivo, "\nEstado da memória: \n");
    fprintf(arquivo, "+--------------------------------+\n");
    for (i = 0; i < 2048; i++)
    {
        if (memoria[i] != atual)
        {
            if (atual)
            {
                if (atual < 10 && i - ant < 10)
                {
                    fprintf(arquivo, "| Processo %d de tamanho %d        |\n", atual, i - ant);
                }
                else if (atual < 100 && i - ant < 10 || atual < 10 && i - ant < 100)
                {
                    fprintf(arquivo, "| Processo %d de tamanho %d       |\n", atual, i - ant);
                }
                else if (atual < 1000 && i - ant < 10 || atual < 100 && i - ant < 100 || atual < 10 && i - ant < 1000)
                {
                    fprintf(arquivo, "| Processo %d de tamanho %d      |\n", atual, i - ant);
                }
                else if (atual < 1000 && i - ant < 100 || atual < 100 && i - ant < 1000)
                {
                    fprintf(arquivo, "| Processo %d de tamanho %d     |\n", atual, i - ant);
                }
                else
                {
                    fprintf(arquivo, "| Processo %d de tamanho %d    |\n", atual, i - ant);
                }

                fprintf(arquivo, "+--------------------------------+\n");
            }
            else
            {
                if (i - ant < 10)
                {
                    fprintf(arquivo, "| Espaço livre de tamanho %d      |\n", i - ant);
                }
                else if (i - ant < 100)
                {
                    fprintf(arquivo, "| Espaço livre de tamanho %d     |\n", i - ant);
                }
                else if (i - ant < 1000)
                {
                    fprintf(arquivo, "| Espaço livre de tamanho %d    |\n", i - ant);
                }
                else
                {
                    fprintf(arquivo, "| Espaço livre de tamanho %d   |\n", i - ant);
                }
                fprintf(arquivo, "+--------------------------------+\n");
            }
            ant = i;
            atual = memoria[i];
        }
    }
    if (atual)
    {
        if (atual < 10 && i - ant < 10)
        {
            fprintf(arquivo, "| Processo %d de tamanho %d        |\n", atual, i - ant);
        }
        else if (atual < 100 && i - ant < 10 || atual < 10 && i - ant < 100)
        {
            fprintf(arquivo, "| Processo %d de tamanho %d       |\n", atual, i - ant);
        }
        else if (atual < 1000 && i - ant < 10 || atual < 100 && i - ant < 100 || atual < 10 && i - ant < 1000)
        {
            fprintf(arquivo, "| Processo %d de tamanho %d      |\n", atual, i - ant);
        }
        else if (atual < 1000 && i - ant < 100 || atual < 100 && i - ant < 1000)
        {
            fprintf(arquivo, "| Processo %d de tamanho %d     |\n", atual, i - ant);
        }
        else
        {
            fprintf(arquivo, "| Processo %d de tamanho %d    |\n", atual, i - ant);
        }

        fprintf(arquivo, "+--------------------------------+\n\n");
    }
    else
    {
        if (i - ant < 10)
        {
            fprintf(arquivo, "| Espaço livre de tamanho %d      |\n", i - ant);
        }
        else if (i - ant < 100)
        {
            fprintf(arquivo, "| Espaço livre de tamanho %d     |\n", i - ant);
        }
        else if (i - ant < 1000)
        {
            fprintf(arquivo, "| Espaço livre de tamanho %d    |\n", i - ant);
        }
        else
        {
            fprintf(arquivo, "| Espaço livre de tamanho %d   |\n", i - ant);
        }

        fprintf(arquivo, "+--------------------------------+\n\n");
    }
}