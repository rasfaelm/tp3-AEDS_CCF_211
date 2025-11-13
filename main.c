#include "header/leitura_de_arquivo.h"
#include "header/inserir_dados.h"
#include "header/selectionSort.h"
#include <time.h>
#include <stdio.h>

int main(void) {
    TADDrone drone;
    TADGalpao galpao;
    int opcao;

    printf("=== Sistema AEDS ===\n");
    printf("1 - Inserir dados manualmente\n");
    printf("2 - Ler arquivo da pasta 'arquivos/'\n");
    printf("Escolha a opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        InserirDadosManualmente(&galpao, &drone);
    } else if (opcao == 2) {
        char nomeArquivo[256];
        printf("Digite o nome do arquivo dentro de 'arquivos/': ");
        if (scanf("%255s", nomeArquivo) != 1) return 1;

        char caminho[512];
        snprintf(caminho, sizeof(caminho), "arquivos/%s", nomeArquivo);

        if (!LerArquivo(caminho, &galpao, &drone)) {
            printf("Erro ao abrir/ler o arquivo: %s\n", caminho);
            return 1;
        }
    } else {
        printf("Opcao invalida.\n");
        return 1;
    }

    printf("\n\n=== Ordenacao dos pacotes ===\n");
    printf("1 - SelectionSort\n");
    printf("2 - X'\n");
    printf("Escolha a opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        //ordena pelo selection sort
        SelectionSort(&galpao.Pacotes);
    } else if (opcao == 2) {
        
    } else {
        printf("Opcao invalida.\n");
        return 1;
    }

    //imprime os pacotes dentro do galpao  
    //ImprimirGalpao(&galpao);

    // entrega
    printf("\nIniciando o processo de carregamento e entregas...\n");

    int viagem = 1;
    int distanciaTotalDia = 0;

    while (!LEhVazia(&galpao.Pacotes)) {
        CarregaDrone(&galpao, &drone);
        RealizarEntrega(&drone, viagem, &distanciaTotalDia);
        viagem++;
    }

    printf("\nTotal de Quilometros Percorridos no Dia: %dkm.\n", distanciaTotalDia);

    printf("\n=== Execucao finalizada ===\n");

    return 0;
}
