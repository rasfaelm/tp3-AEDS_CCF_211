#include "../header/inserir_dados.h"

void InserirDadosManualmente(TADGalpao *galpao, TADDrone *drone) {
    int pesoMaximo = 0, qtd = 0;
    printf("Digite o peso maximo suportado pelo drone: ");
    if (scanf("%d", &pesoMaximo) != 1) return;

    InicializaDrone(drone, pesoMaximo);
    InicializaGalpao(galpao);

    printf("Digite a quantidade de pacotes: ");
    if (scanf("%d", &qtd) != 1) return;

    for (int i = 0; i < qtd; ++i) {
        char conteudo[TAM_CONTEUDO];
        char destinatario[TAM_DESTINATARIO];
        int peso, distancia, prioridade;

        printf("\nPacote %d:\n", i + 1);
        printf("Conteudo: ");
        scanf("%24s", conteudo);
        printf("Destinatario: ");
        scanf("%29s", destinatario);
        printf("Peso: ");
        scanf("%d", &peso);
        printf("Distancia: ");
        scanf("%d", &distancia);
        printf("Prioridade (1 a 5): ");
        scanf("%d", &prioridade);

        TADPacote p;
        InicializaPacote(&p);
        SetConteudo(&p, conteudo);
        SetDestinatario(&p, destinatario);
        SetPesoPacote(&p, peso);
        SetDistanciaDest(&p, distancia);
        SetPrioridade(&p, prioridade);

        RecebePacote(galpao, &p);
    }
}
