#ifndef _H_GERAL
#define _H_GERAL

typedef struct no_
{
    int id;
    int tamanho;
    struct no_ *prox;
} no;

// Definição de cores
#define AZUL "\033[34m"
#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define MAGENTA "\033[35m"
#define CIANO "\033[36m"
#define AMARELO "\033[33m"
#define RESET "\033[0m"


/**
 * @brief Verifica se deve criar um processo ou não
 * @return 1 60% das vezes, 0 40% das vezes
 */
int tentarCriarProcesso();

/**
 * @brief Cria um Nó
 * @param *processosCriados: Número do processo criado
 * @return Nó com id = argumento e tamanho = gerarNumeroAleatorio()
*/
no *alocarNo(int *processosCriados);

/**
 * @brief Lê uma opção
 * @param *opcao: Opção lida
 */
void lerOpcao(int *opcao);

/**
 * @brief Lê um delay
 * @param *delay: Delay lido
 */
void lerDelay(int *delay);

/**
 * @brief Lê se a memória deve ser impressa
 * @param *printMemoria: Opção lida
 */
void lerPrintMemoria(int *printMemoria);

/**
 * @brief Lê se a memória deve ser impressa no arquivo
 * @param *printMemoriaArquivo: Opção lida
 */
void lerPrintMemoriaArquivo(int *printMemoriaArquivo);

/**
 * @brief Lê o menu de configuração
 * @param *escolha: Escolha lida
 */
void lerMenuConfig(int *escolha);

/**
 * @brief Cria / Limpa o conteúdo de um arquivo
 * @param *arquivo: O nome do arquivo
*/
void limparArquivo(char *arquivo);

/**
 * @brief Busca um processo na memória
 * @param *memoria: Vetor de memória
 * @param id: ID do processo
 * @param *posicao: Posição do processo
 * @param *tamanho: Tamanho do processo
*/
void buscaMemoria(int *memoria, int id, int *posicao, int *tamanho);

/**
 * @brief Limpa a memória
 * @param *memoria: Vetor de memória
 * @param posicao: Posição do processo
 * @param tamanho: Tamanho do processo
*/
void limpaMemoria(int *memoria, int posicao, int tamanho);


/**
 * @brief Verifica se a memória está vazia
 * @param *memoria: Vetor de memória
 * @return 1 se a memória estiver vazia, caso contrário, 0
 */
int memoriaVazia(int *memoria);

/**
 * @brief Imprime a memória
 * @param *memoria: Vetor de memória
 */
void imprimeMemoria(int *memoria);

/**
 * @brief Imprime a memória em um arquivo
 * @param *memoria: Vetor de memória
 * @param *arquivo: Arquivo de log
 */
void imprimeMemoriaArquivo(int *memoria, FILE *arquivo);

#endif