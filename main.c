#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "funcoes.h"

int main(){
    setlocale(LC_ALL, "Portuguese");

    int i, j;
    
    AEROPORTO aeroporto, *ponteiro_aeroporto;
    ponteiro_aeroporto = &aeroporto;

    aeroporto.quantidadeVoos = QUANTIDADE_VOOS();

    AVIOES avioes[aeroporto.quantidadeVoos], *ponteiro_avioes;
    ponteiro_avioes = &avioes[0];

    printf("\n");
    ID_VOOS(ponteiro_aeroporto, avioes);

    aeroporto.maximoAssentos = CAPACIDADE_MAXIMA();

    int ocupacaoMaximaAeroporto[aeroporto.quantidadeVoos][aeroporto.maximoAssentos + 1];

    LIBERAR_POLTRONAS(ponteiro_aeroporto, ocupacaoMaximaAeroporto);

    int ocupacaoMaximaVoo[aeroporto.quantidadeVoos];

    printf("\n");
    OCUPACAO_MAXIMA_VOO(ponteiro_aeroporto, ponteiro_avioes, ocupacaoMaximaVoo);

    MENU(ponteiro_aeroporto, ponteiro_avioes, ocupacaoMaximaVoo, ocupacaoMaximaAeroporto);

    return 0;
}