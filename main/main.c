/*
+-------------------------------------------------------------+
| UNIFAL – Universidade Federal de Alfenas.                   |
| BACHARELADO EM CIENCIA DA COMPUTACAO.                       |
| Trabalho..: Gerência de Memória                             |
| Disciplina: Sistemas Operacionais                           |
| Professor.: Fellipe Rey                                     |
| Aluno(s)..: Rodrigo Luís Gasparino Lucatelli                |
|             José Olavo Monteiro Travassos Pereira da Silva  |
| Data......: 12/06/2024                                      |
+-------------------------------------------------------------+
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../hdr/lista.h"
#include "../hdr/geral.h"
#include "../hdr/firstFit.h"
#include "../hdr/nextFit.h"
#include "../hdr/bestFit.h"
#include "../hdr/worstFit.h"

int main()
{
    int opcao = 0;
    int delay = 0;
    int printMemoria = 0;
    int printMemoriaArquivo = 0;
    int escolhaConfiguracao = 0;
    srand(time(NULL));
    int *memoria = (int *)calloc(2048, sizeof(int));

    system("clear");
    do
    {
        lerOpcao(&opcao);
        switch (opcao)
        {
        case 0:
            printf(AZUL "+-------------------------------------------------+\n");
            printf("| " CIANO "Saindo..." AZUL "                                       |\n");
            printf("+-------------------------------------------------+\n");
            break;
        case 1:
            system("clear");
            firstFit(delay, memoria, printMemoria, printMemoriaArquivo);
            break;
        case 2:
            system("clear");
            nextFit(delay, memoria, printMemoria, printMemoriaArquivo);
            break;
        case 3:
            system("clear");
            bestFit(delay, memoria, printMemoria, printMemoriaArquivo);
            break;
        case 4:
            system("clear");
            worstFit(delay, memoria, printMemoria, printMemoriaArquivo);
            break;
        case 5:
            do
            {
                lerMenuConfig(&escolhaConfiguracao);

                switch (escolhaConfiguracao)
                {
                case 0:
                    break;
                case 1:
                    lerDelay(&delay);
                    break;
                case 2:
                    lerPrintMemoria(&printMemoria);
                    break;
                case 3:
                    lerPrintMemoriaArquivo(&printMemoriaArquivo);
                    break;
                default:
                    printf(AZUL "+-------------------------------------------------+\n");
                    printf("| " CIANO "Opção inválida!" AZUL "                                 |\n");
                    printf("+-------------------------------------------------+\n\n" RESET);
                    break;
                }
            } while (escolhaConfiguracao);
            break;
        default:
            printf(AZUL "+-------------------------------------------------+\n");
            printf("| " CIANO "Opção inválida!" AZUL "                                 |\n");
            printf("+-------------------------------------------------+\n\n" RESET);
            break;
        }
    } while (opcao != 0);

    return 0;
}