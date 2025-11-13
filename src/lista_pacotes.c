#include "../header/lista_pacotes.h"
#include <stdlib.h>

// Inicializa a lista como vazia
void FLVazia(TLista *lista) {
    lista->pPrimeiro = (Apontador) malloc(sizeof(TCelula));
    lista->pUltimo = lista->pPrimeiro;
    lista->pPrimeiro->pProx = NULL;
}

// Retorna 1 se estiver vazia, 0 caso contrário
int LEhVazia(const TLista *lista) {
    return (lista->pPrimeiro == lista->pUltimo);
}

// Insere novo pacote no final da lista
void LInsere(TLista *lista, const TADPacote *pacote) {
    lista->pUltimo->pProx = (Apontador) malloc(sizeof(TCelula));
    lista->pUltimo = lista->pUltimo->pProx;
    lista->pUltimo->Pacote = *pacote;
    lista->pUltimo->pProx = NULL;
}

// Remove o primeiro elemento da lista
int LRetira(TLista *lista, TADPacote *pacote) {
    if (LEhVazia(lista)) return 0;

    Apontador pAux = lista->pPrimeiro->pProx;
    *pacote = pAux->Pacote;
    lista->pPrimeiro->pProx = pAux->pProx;

    if (pAux == lista->pUltimo)
        lista->pUltimo = lista->pPrimeiro;

    free(pAux);
    return 1;
}

// Retorna a quantidade de elementos na lista
int LQuantidade(const TLista *lista) {
    int count = 0;
    Apontador p = lista->pPrimeiro->pProx;

    while (p != NULL) {
        count++;
        p = p->pProx;
    }

    return count;
}
