#include "../header/selectionSort.h"
#include <time.h>


// Selection Sort para lista encadeada (ordena por prioridade)
void SelectionSort(TLista *lista) {
    if (LEhVazia(lista)) return;

    Apontador i, j, maxNode;
    int compSelection = 0;  // quantidade de comparacoes
    int movSelection = 0;   // quantidade de movimentações (trocas)

    //Medida do tempo metodo SelectionSort
    clock_t start, end;
    double time_selection;

    start = clock(); // inicio da contagem

    for (i = lista->pPrimeiro->pProx; i != NULL; i = i->pProx) {

        maxNode = i; // assume que o maior é o próprio i

        // busca o maior no restante da lista
        for (j = i->pProx; j != NULL; j = j->pProx) {

            // Uma comparação de prioridade ocorre aqui
            compSelection++;
            if (GetPrioridade(&j->Pacote) > GetPrioridade(&maxNode->Pacote)) {
                maxNode = j;
            }
        }

        // se achou maior prioridade à frente -> troca dados
        if (maxNode != i) {
            TADPacote temp = i->Pacote;
            i->Pacote = maxNode->Pacote;
            maxNode->Pacote = temp;

            movSelection++;  //adiciona uma movimentacao
        }
    }
    end = clock(); // final contagem
    time_selection = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execucao: \n%fs\n", time_selection);
    printf("Comparações: %d\n", compSelection);
    printf("Movimentações: %d\n", movSelection);
}