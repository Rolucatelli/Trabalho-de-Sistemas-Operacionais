#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"

int gerarNumeroAleatorio()
{
    return (rand() % 200) + 1; // Gera um número aleatório entre 1 e 20
}

int tentarCriarProcesso()
{
    if (gerarNumeroAleatorio() <= 100)
    {
        return 1;
    }
    return 0;
}

no *alocarNo(int *processosCriados)
{
    no *retorno = malloc(sizeof(no));
    retorno->id = ++(*processosCriados);
    retorno->tamanho = gerarNumeroAleatorio();
    retorno->prox = NULL;
    return retorno;
}

void lerMenu(int *opcao, int *delay)
{

    printf("=====================================\n");
    printf("Escolha o tempo, em segundos, entre mensagens:\n");
    printf("(Caso não queira um tempo de espera, digite 0)\n");
    scanf("%d", delay);
    printf("=====================================\n");
    printf("Escolha uma técnica de gerência de memória:\n");
    printf("0 - Sair\n");
    printf("1 - First-Fit\n");
    printf("2 - Next-Fit\n");
    printf("3 - Best-Fit\n");
    printf("4 - Worst-Fit\n");
    scanf("%d", opcao);
    printf("=====================================\n");
}

void limparArquivo(char *arquivo)
{
    FILE *temp = fopen(arquivo, "w+");
    if (temp == NULL)
    {
        return;
    }
    fprintf(temp, "");
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
    *posicao = i++;
    while (memoria[i] == id && i < 2048)
    {
        i++;
    }
    *tamanho = i - *posicao;
}

void limpaMemoria(int *memoria, int posicao, int tamanho)
{
    for (int i = posicao; i < tamanho; i++)
    {
        memoria[i] = 0;
    }
}