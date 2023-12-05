#ifndef FUNCOES_H
#define FUNCOES_H

#include "aeroporto.h"
#include "avioes.h"

int QUANTIDADE_VOOS();
int CAPACIDADE_MAXIMA();
void ID_VOOS(AEROPORTO *ponteiro_aeroporto, AVIOES avioes[]);
void LIBERAR_POLTRONAS(AEROPORTO *ponteiro_aeroporto, int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos + 1]);
void OCUPACAO_MAXIMA_VOO(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[]);
void CONSULTAR_VAGAS(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos]);
int ESCOLHER_VOO_RESERVAR(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes);
int RESERVAR_ASSENTO(AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int indiceVoo);
void AINDA_RESERVANDO(AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int indiceVoo, int reservarAssento, int ocupacaoMaximaAeroporto[indiceVoo][reservarAssento]);
int ESCOLHER_VOO_CANCELAMENTO(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes);
int CANCELAR_ASSENTO(AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int indiceVoo);
void AINDA_CANCELANDO(AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int indiceVoo, int cancelarAssento, int ocupacaoMaximaAeroporto[indiceVoo][cancelarAssento]);

#endif