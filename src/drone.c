#include "../header/drone.h"

void InicializaDrone(TADDrone *drone, int pesoMaximo) {
    *(int*)&drone->PesoMaximo = pesoMaximo;
    drone->PesoCarregado = 0;
    drone->DistanciaTotal = 0;
    FLVazia(&drone->Pacotes);
}

int CarregarPacote(TADDrone *drone, TADPacote *pacote) {
    if (drone->PesoCarregado + GetPesoPacote(pacote) <= drone->PesoMaximo) {
        LInsere(&drone->Pacotes, pacote);
        drone->PesoCarregado += GetPesoPacote(pacote);
        return 1;
    }
    return 0; // não coube
}

void ImprimirEntregasDrone(TADDrone *drone, int viagem) {
    if (LEhVazia(&drone->Pacotes)) {
        printf("\nDrone vazio, nenhuma entrega a exibir.\n");
        return;
    }

    printf("\n=== Viagem %d ===\n", viagem);
    Apontador atual = drone->Pacotes.pPrimeiro->pProx;

    while (atual != NULL) {
        printf("Entrega: \"%s\" para \"%s\"\n",
               GetConteudo(&atual->Pacote),
               GetDestinatario(&atual->Pacote));
        atual = atual->pProx;
    }
}

void RealizarEntrega(TADDrone *drone, int viagem, int *distanciaTotalDia) {
    if (LEhVazia(&drone->Pacotes)) return;

    // Exibe as entregas desta viagem
    ImprimirEntregasDrone(drone, viagem);

    int distanciaPercorrida = 0;
    int ultimaDistancia = 0;
    Apontador atual = drone->Pacotes.pPrimeiro->pProx;

    // Cálculo da distância total percorrida nesta viagem
    while (atual != NULL) {
        distanciaPercorrida += abs(GetDistanciaDest(&atual->Pacote) - ultimaDistancia);
        ultimaDistancia = GetDistanciaDest(&atual->Pacote);
        atual = atual->pProx;
    }

    // Retorna à base
    distanciaPercorrida += ultimaDistancia;

    printf("Distância Total da Viagem: %dkm\n", distanciaPercorrida);

    // Atualiza totais
    *distanciaTotalDia += distanciaPercorrida;
    drone->DistanciaTotal += distanciaPercorrida;

    // Limpa lista do drone (entregas finalizadas)
    TADPacote tmp;
    while (LRetira(&drone->Pacotes, &tmp));

    drone->PesoCarregado = 0;
}
