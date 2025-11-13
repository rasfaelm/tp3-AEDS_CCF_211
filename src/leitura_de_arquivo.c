#include "../header/leitura_de_arquivo.h"

int LerArquivo(const char *caminho, TADGalpao *galpao, TADDrone *drone) {
    FILE *f = fopen(caminho, "r");
    if (!f) return 0;

    int pesoMaximo = 0;
    int qtd = 0;

    if (fscanf(f, "%d", &pesoMaximo) != 1) { fclose(f); return 0; }
    if (fscanf(f, "%d", &qtd) != 1) { fclose(f); return 0; }

    InicializaDrone(drone, pesoMaximo);
    InicializaGalpao(galpao);

    for (int i = 0; i < qtd; ++i) {
        char conteudo[TAM_CONTEUDO];
        char destinatario[TAM_DESTINATARIO];
        int peso, distancia, prioridade;

        if (fscanf(f, "%24s %29s %d %d %d", conteudo, destinatario, &peso, &distancia, &prioridade) != 5) {
            break;
        }

        TADPacote p;
        InicializaPacote(&p);
        SetConteudo(&p, conteudo);
        SetDestinatario(&p, destinatario);
        SetPesoPacote(&p, peso);
        SetDistanciaDest(&p, distancia);
        SetPrioridade(&p, prioridade);

        RecebePacote(galpao, &p);
    }

    fclose(f);
    return 1;
}
