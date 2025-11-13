#include "../header/selectionSort.h"

// Selection Sort para lista encadeada (ordena por prioridade)
void SelectionSort(TLista *lista) {
    if (LEhVazia(lista)) return;

    Apontador i, j, maxNode;

    for (i = lista->pPrimeiro->pProx; i != NULL; i = i->pProx) {

        maxNode = i; // assume que o maior é o próprio i

        // busca o maior no restante da lista
        for (j = i->pProx; j != NULL; j = j->pProx) {
            if (GetPrioridade(&j->Pacote) > GetPrioridade(&maxNode->Pacote)) {
                maxNode = j;
            }
        }

        // se achou maior prioridade à frente -> troca dados
        if (maxNode != i) {
            TADPacote temp = i->Pacote;
            i->Pacote = maxNode->Pacote;
            maxNode->Pacote = temp;
        }
    }
}