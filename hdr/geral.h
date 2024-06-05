#ifndef _H_GERAL
#define _H_GERAL

typedef struct no_
{
    int id;
    int tamanho;
    struct no_ *prox;
} no;

/*
    @brief Gera um número aleatório entre 1 e 20
    @return Número aleatório entre 1 e 20
*/
int gerarNumeroAleatorio();

/*
    @brief Verifica a chance de criar um processo
    @return 1 30% das vezes, caso contrário, 0
*/
int tentarCriarProcesso();

/*
    @brief Cria um Nó
    @param *processosCriados: Número do processo criado
    @return Nó com id = argumento e tamanho = gerarNumeroAleatorio()
*/
no *alocarNo(int *processosCriados);

/*
    @brief Permite o usuário a escolher o método de escalonamento
    @param *opcao: É a resposta do usuário
    @return 0 = sair; 1 = FCFS; 2 = SJF; 3 = RoundRobin.
*/
void lerMenu(int *opcao, int *delay);

/*
    @brief Cria / Limpa o conteúdo de um arquivo
    @param *arquivo: O nome do arquivo
*/
void limparArquivo(char *arquivo);

/*
    @brief Busca um processo na memória
    @param *memoria: Vetor de memória
    @param id: ID do processo
    @param *posicao: Posição do processo
    @param *tamanho: Tamanho do processo
*/
void buscaMemoria(int *memoria, int id, int *posicao, int *tamanho);

/*
    @brief Limpa a memória
    @param *memoria: Vetor de memória
    @param posicao: Posição do processo
    @param tamanho: Tamanho do processo
*/
void limpaMemoria(int *memoria, int posicao, int tamanho);

#endif