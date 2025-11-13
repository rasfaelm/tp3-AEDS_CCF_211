#ifndef LISTA_DE_PACOTES_H
#define LISTA_DE_PACOTES_H

#include "pacote.h"

typedef struct Celula {
    TADPacote Pacote;
    struct Celula *pProx;
} TCelula;

typedef TCelula *Apontador;

typedef struct {
    Apontador pPrimeiro;
    Apontador pUltimo;
} TLista;

void FLVazia(TLista *lista);
void LInsere(TLista *lista, const TADPacote *pacote);
int LEhVazia(const TLista *lista);
int LRetira(TLista *lista, TADPacote *pacote);
int LQuantidade(const TLista *lista);

#endif
