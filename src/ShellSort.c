#include "../header/ShellSort.h"
#include <stdlib.h>
#include <time.h>

Apontador *ConverteLista(TLista *lista)
{
    int n = LQuantidade(lista);
    Apontador *vetor = (Apontador*) malloc(sizeof(Apontador) * n);
    Apontador p = lista->pPrimeiro->pProx;

    for (int i = 0; i < n; i++) {
        vetor[i] = p;
        Apontador next = p->pProx;
        p->pProx = NULL;
        p = next;
    }

    return vetor;
}

void ShellSort(TLista *lista)
{
    clock_t start, end;
    double sort_time;
    start = clock();

    int n = LQuantidade(lista);
    Apontador *vetor = ConverteLista(lista);
    int h = 1;

    int compShell = 0; // quantidade de comparações
    int movShell = 0;  // quantidade de movimentações

    while (h < n) h = 3*h + 1;

    while (h > 1) {
        h /= 3;

        for (int i = h; i < n; i++) {
            Apontador aux = vetor[i];
            int j = i;

            while (j >= h &&
                   (compShell++, vetor[j-h]->Pacote.Prioridade < aux->Pacote.Prioridade))
            {
                vetor[j] = vetor[j-h];
                movShell++;   
                j -= h;
            }

            vetor[j] = aux;
            movShell++; 
        }
    }

    for (int i = 0; i < n - 1; i++){
        vetor[i]->pProx = vetor[i+1];
    }

    vetor[n-1]->pProx = NULL;
    lista->pPrimeiro->pProx = vetor[0];
    lista->pUltimo = vetor[n-1];

    free(vetor);

    end = clock();
    sort_time = ((double)(end - start) / CLOCKS_PER_SEC);

    printf("Tempo de execucao: \n%fs\n", sort_time);
    printf("Comparações: %d\n", compShell);
    printf("Movimentações: %d\n", movShell);
}
