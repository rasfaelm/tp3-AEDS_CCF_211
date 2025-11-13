#include "../header/galpao.h"

// remove o pacote no índice da lista encadeada
int LRetiraIndice(TLista *lista, int indice) {
    if (LEhVazia(lista)) return 0;

    Apontador ant = lista->pPrimeiro;
    Apontador atual = lista->pPrimeiro->pProx;
    int i = 0;

    while (atual != NULL && i < indice) {
        ant = atual;
        atual = atual->pProx;
        i++;
    }

    if (atual == NULL) return 0;

    ant->pProx = atual->pProx;

    if (atual == lista->pUltimo)
        lista->pUltimo = ant;

    free(atual);
    return 1;
}

// inicializa galpão
void InicializaGalpao(TADGalpao *galpao) {
    FLVazia(&galpao->Pacotes);
}

// insere pacote na lista
void RecebePacote(TADGalpao *galpao, TADPacote *pacote) {
    LInsere(&galpao->Pacotes, pacote);
}

// carrega o drone
void CarregaDrone(TADGalpao *galpao, TADDrone *drone) {
    int n = LQuantidade(&galpao->Pacotes);

    if (n == 0) {
        printf("\nNenhum pacote disponível no galpão.\n");
        return;
    }

    int pesoMaximo = drone->PesoMaximo;
    int pesoAtual = 0;
    int prioridadeTotal = 0;

    Apontador aux = galpao->Pacotes.pPrimeiro->pProx;
    int idx = 0;

    while (aux != NULL) {
        int peso = GetPesoPacote(&aux->Pacote);
        int prioridade = GetPrioridade(&aux->Pacote);

        if (pesoAtual + peso <= pesoMaximo) {
            pesoAtual += peso;
            prioridadeTotal += prioridade;

            CarregarPacote(drone, &aux->Pacote);

            LRetiraIndice(&galpao->Pacotes, idx);
            aux = galpao->Pacotes.pPrimeiro->pProx;
            idx = 0;
            continue;
        }

        aux = aux->pProx;
        idx++;
    }

    if (pesoAtual == 0)
        printf("\nNenhum pacote pôde ser carregado (peso máximo: %d).\n", pesoMaximo);
    else
        printf("\nPeso total: %d kg | Prioridade total: %d\n", pesoAtual, prioridadeTotal);
}

// imprimir pacotes no galpão
void ImprimirGalpao(TADGalpao *galpao) {
    if (LEhVazia(&galpao->Pacotes)) {
        printf("\nO galpão está vazio, nenhum pacote disponível.\n");
        return;
    }

    printf("\n=== Pacotes Armazenados no Galpao ===\n");

    Apontador atual = galpao->Pacotes.pPrimeiro->pProx;
    int contador = 1;

    while (atual != NULL) {
        printf("Pacote %d:\n", contador++);
        printf("  Conteudo: %s\n", GetConteudo(&atual->Pacote));
        printf("  Destinatario: %s\n", GetDestinatario(&atual->Pacote));
        printf("  Peso: %dkg\n", GetPesoPacote(&atual->Pacote));
        printf("  Distancia: %dkm\n", GetDistanciaDest(&atual->Pacote));
        printf("  Prioridade: %d\n", GetPrioridade(&atual->Pacote));
        printf("--------------------------------------\n");

        atual = atual->pProx;
    }
}
