#include "../header/pacote.h"
#include <string.h>

// ====== SET ======

void SetConteudo(TADPacote *Pacote, const char *conteudo) {
    strncpy(Pacote->Conteudo, conteudo, TAM_CONTEUDO - 1);
    Pacote->Conteudo[TAM_CONTEUDO - 1] = '\0';
}

void SetDestinatario(TADPacote *Pacote, const char *destinatario) {
    strncpy(Pacote->Destinatario, destinatario, TAM_DESTINATARIO - 1);
    Pacote->Destinatario[TAM_DESTINATARIO - 1] = '\0';
}

void SetPesoPacote(TADPacote *Pacote, int peso) {
    Pacote->PesoPacote = peso;
}

void SetDistanciaDest(TADPacote *Pacote, int distancia) {
    Pacote->DistanciaDestino = distancia;
}

void SetPrioridade(TADPacote *Pacote, int prioridade) {
    if (prioridade < 1) prioridade = 1;
    if (prioridade > 5) prioridade = 5;
    Pacote->Prioridade = prioridade;
}

// ====== GET ======

const char *GetConteudo(const TADPacote *Pacote) {
    return Pacote->Conteudo;
}

const char *GetDestinatario(const TADPacote *Pacote) {
    return Pacote->Destinatario;
}

int GetPesoPacote(const TADPacote *Pacote) {
    return Pacote->PesoPacote;
}

int GetDistanciaDest(const TADPacote *Pacote) {
    return Pacote->DistanciaDestino;
}

int GetPrioridade(const TADPacote *Pacote) {
    return Pacote->Prioridade;
}

// ====== INICIALIZA ======

void InicializaPacote(TADPacote *Pacote) {
    Pacote->PesoPacote = 0;
    Pacote->DistanciaDestino = 0;
    Pacote->Prioridade = 1;
    Pacote->Conteudo[0] = '\0';
    Pacote->Destinatario[0] = '\0';
}
