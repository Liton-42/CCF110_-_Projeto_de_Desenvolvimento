#ifndef FUNCOES_H
#define FUNCOES_H

#include "aeroporto.h"
#include "avioes.h"

int QUANTIDADE_VOOS();
int CAPACIDADE_MAXIMA();
void ID_VOOS(AEROPORTO *ponteiro_aeroporto, AVIOES avioes[]);
void LIBERAR_POLTRONAS(AEROPORTO *ponteiro_aeroporto, AVIOES avioes[], int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos + 1]);
void OCUPACAO_MAXIMA_VOO(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[]);
void CONSULTAR_VAGAS(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos + 1]);
void RESERVAR_ASSENTO(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos + 1]);
void CANCELAR_ASSENTO(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos + 1]);
void MENU(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos + 1]);

#endif