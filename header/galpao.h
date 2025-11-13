#ifndef GALPAO_H
#define GALPAO_H

#include "drone.h"

typedef struct {
    TLista Pacotes;
} TADGalpao;

// Inicializa galpão
void InicializaGalpao(TADGalpao *galpao);

// Recebe pacotes (insere no final da lista)
void RecebePacote(TADGalpao *galpao, TADPacote *pacote);

// Carrega pacotes do galpão para o drone
void CarregaDrone(TADGalpao *galpao, TADDrone *drone);

// Imprime os pacotes armazenados no galpão
void ImprimirGalpao(TADGalpao *galpao);

// Função de selectionsort
void SelectionSort(TLista *lista);

#endif
