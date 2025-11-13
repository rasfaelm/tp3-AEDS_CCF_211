#ifndef DRONE_H
#define DRONE_H

#include "lista_pacotes.h"

typedef struct {
    const int PesoMaximo;
    int PesoCarregado;
    int DistanciaTotal;
    TLista Pacotes; // lista de pacotes carregados
} TADDrone;

// Inicializa drone com peso máximo
void InicializaDrone(TADDrone *drone, int pesoMaximo);

// Carrega um pacote no drone (se couber no peso)
int CarregarPacote(TADDrone *drone, TADPacote *pacote);

// Realiza entrega: calcula distância, esvazia lista e chama função de impressão
void RealizarEntrega(TADDrone *drone, int viagem, int *distanciaTotalDia);

// Exibe informações dos pacotes que estão no drone
void ImprimirEntregasDrone(TADDrone *drone, int viagem);

#endif
