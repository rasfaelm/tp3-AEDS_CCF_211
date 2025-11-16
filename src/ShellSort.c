#include "../header/ShellSort.h"

Apontador *ConverteLista(TLista *lista)
{
    int n = LQuantidade(lista);
    Apontador *vetor = (Apontador*) malloc(sizeof(Apontador) * n);
    Apontador p = lista->pPrimeiro->pProx;

    for (int i = 0; i < n; i++) {
        vetor[i] = p;
        p = p->pProx;
    }

    return vetor;
}



void ShellSort(TLista *lista)
{
    int n = LQuantidade(lista);
    Apontador *vetor = ConverteLista(lista);
    int h = 1;

    while (h < n) h = 3*h + 1;

    while (h > 1) {
        h /= 3;

        for (int i = h; i < n; i++) {
            Apontador aux = vetor[i];
            int j = i;

            while (j >= h &&
                   vetor[j-h]->Pacote.Prioridade < aux->Pacote.Prioridade)
            {
                vetor[j] = vetor[j-h];
                j -= h;
            }

            vetor[j] = aux;
        }
    }

    for (int i = 0; i < n - 1; i++){
        vetor[i]->pProx = vetor[i+1];
    }
    
    vetor[n-1]->pProx = NULL;
    lista->pPrimeiro->pProx = vetor[0];
    lista->pUltimo = vetor[n-1];

    free(vetor);
}
