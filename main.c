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

    int ocupacaoMaximaAeroporto[aeroporto.quantidadeVoos][aeroporto.maximoAssentos + 1], *ponteiro_ocupacaoMaximaAeroporto;
    ponteiro_ocupacaoMaximaAeroporto = &ocupacaoMaximaAeroporto[0][0];

    LIBERAR_POLTRONAS(ponteiro_aeroporto, ponteiro_ocupacaoMaximaAeroporto);   

    int ocupacaoMaximaVoo[aeroporto.quantidadeVoos];

    printf("\n");
    OCUPACAO_MAXIMA_VOO(ponteiro_aeroporto, ponteiro_avioes, ocupacaoMaximaVoo);

    int select, contVagas, consultarVoo, reservarVoo, reservarAssento, cancelarVoo, cancelarAssento, indiceVoo;

    contVagas = 0;

    printf("Informe a operação que deseja realizar:\n");
    printf(" 1. Consultar vagas\n");
    printf(" 2. Reservar assento\n");
    printf(" 3. Cancelar reserva\n");
    printf(" 4. Sair\n");

    scanf("%d", &select);

    switch (select){
        case 1:
            printf("\n");
            indiceVoo = CONSULTAR_VAGAS(ponteiro_aeroporto, ponteiro_avioes);
            
            for(j = 1; j < ocupacaoMaximaVoo[indiceVoo] + 1; j++){
                if(ocupacaoMaximaAeroporto[indiceVoo][j] == 0){
                    contVagas++;
                }
            }
            printf("Quantidade de poltronas livres: %d", contVagas);
            
            break;
        
        case 2:
            printf("\n");
            indiceVoo = ESCOLHER_VOO_RESERVAR(ponteiro_aeroporto, ponteiro_avioes);
            
            reservarAssento = RESERVAR_ASSENTO(ponteiro_avioes, ocupacaoMaximaVoo, indiceVoo);
            AINDA_RESERVANDO(ponteiro_avioes, ocupacaoMaximaVoo, indiceVoo, reservarAssento, ocupacaoMaximaAeroporto);

            break;

        case 3:
            printf("\n");
            indiceVoo = ESCOLHER_VOO_CANCELAMENTO(ponteiro_aeroporto, ponteiro_avioes);
            cancelarAssento = CANCELAR_ASSENTO(ponteiro_avioes, ocupacaoMaximaVoo, indiceVoo);
            AINDA_CANCELANDO(ponteiro_avioes, ocupacaoMaximaVoo, indiceVoo, cancelarAssento, ocupacaoMaximaAeroporto);

            break;

        default:
            break;
    }

    return 0;
}