#ifndef PACOTE_H
#define PACOTE_H
#include <stdlib.h>
#include <stdio.h>

#define TAM_CONTEUDO 25
#define TAM_DESTINATARIO 30

typedef struct {
    char Conteudo[TAM_CONTEUDO];
    char Destinatario[TAM_DESTINATARIO];
    int PesoPacote;
    int DistanciaDestino;
    int Prioridade;
} TADPacote;

// SET 
void SetConteudo(TADPacote *Pacote, const char *conteudo);
void SetDestinatario(TADPacote *Pacote, const char *destinatario);
void SetPesoPacote(TADPacote *Pacote, int peso);
void SetDistanciaDest(TADPacote *Pacote, int distancia);
void SetPrioridade(TADPacote *Pacote, int prioridade);

// GET
const char *GetConteudo(const TADPacote *Pacote);
const char *GetDestinatario(const TADPacote *Pacote);
int GetPesoPacote(const TADPacote *Pacote);
int GetDistanciaDest(const TADPacote *Pacote);
int GetPrioridade(const TADPacote *Pacote);

// Inicia o pacote
void InicializaPacote(TADPacote *Pacote);

#endif
