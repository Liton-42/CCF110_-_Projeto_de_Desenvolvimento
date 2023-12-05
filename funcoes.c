#include "stdio.h"
#include "stdlib.h"
#include "funcoes.h"

int i, j;

int QUANTIDADE_VOOS(){
    int quantidade;

    printf("Informe o número de voos disponíveis: ");
    scanf("%d", &quantidade);

    return quantidade;
}

int CAPACIDADE_MAXIMA(){
    int capacidade;

    printf("\nInforme a capacidade máxima de assentos suportada pelo aeroporto: ");
    scanf("%d", &capacidade);

    return capacidade;
}

void ID_VOOS(AEROPORTO *ponteiro_aeroporto, AVIOES avioes[]){
    for(i = 0; i < ponteiro_aeroporto->quantidadeVoos; i++){
        printf("Cadestre o %dº voo: ", i + 1);
        scanf("%d", &avioes[i].identificacaoVoo);
    }
}

void LIBERAR_POLTRONAS(AEROPORTO *ponteiro_aeroporto, int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos + 1]){
    int resetarAssentos;

    printf("Resetar assentos? (0 = Não, 1 = Sim) ");
    scanf("%d", &resetarAssentos);

    if (resetarAssentos == 1){
        for(i = 0; i < ponteiro_aeroporto->quantidadeVoos; i++){
            for (j = 0; j < (ponteiro_aeroporto->maximoAssentos + 1); j++){
                ocupacaoMaximaAeroporto[i][j] = 0;
            }
        }
    }
}

void OCUPACAO_MAXIMA_VOO(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[]){
    for(i = 0; i < ponteiro_aeroporto->quantidadeVoos; i++){
        printf("Total de assentos no Voo %d: ", (ponteiro_avioes + i)->identificacaoVoo);
        scanf("%d", &ocupacaoMaximaVoo[i]);
    }
}

void CONSULTAR_VAGAS(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos]){
    int indiceVoo, consultarVoo, contVagas = 0;

    for(i = 0; i < ponteiro_aeroporto->quantidadeVoos; i++){
        printf("Voo %d\n", (ponteiro_avioes + i)->identificacaoVoo);
    }
            
    printf("\nInforme o voo para consultar as poltronas vagas (para encerrar digite 0): ");
    scanf("%d", &consultarVoo);

    for(i = 0; i < ponteiro_aeroporto->quantidadeVoos; i++){
        if(consultarVoo == (ponteiro_avioes + i)->identificacaoVoo){
            indiceVoo = i;
        }
    }

    for(j = 1; j < ocupacaoMaximaVoo[indiceVoo] + 1; j++){
        if(ocupacaoMaximaAeroporto[indiceVoo][j] == 0){
            contVagas++;
        }
    }

    printf("Quantidade de poltronas livres: %d", contVagas);
}

int ESCOLHER_VOO_RESERVAR(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes){
    int indiceVoo, reservarVoo;

    for(i = 0; i < ponteiro_aeroporto->quantidadeVoos; i++){
        printf("Voo %d\n", (ponteiro_avioes + i)->identificacaoVoo);
    }
            
    printf("\nInforme o voo em que se realizara a reserva (para encerrar digite 0): ");
    scanf("%d", &reservarVoo);

    for(i = 0; i < ponteiro_aeroporto->quantidadeVoos; i++){
        if(reservarVoo == (ponteiro_avioes + i)->identificacaoVoo){
            indiceVoo = i;
        }
    }

    return indiceVoo;
}

int RESERVAR_ASSENTO(AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int indiceVoo){
    int reservarAssento;

    printf("\nInforme a poltrona que será reservada (para encerrar digite 0): ");
        scanf("%d", &reservarAssento);
            
    if(reservarAssento > ocupacaoMaximaVoo[indiceVoo]){
        printf("\nA capacidade máxima do Voo %d é %d", (ponteiro_avioes + indiceVoo)->identificacaoVoo, ocupacaoMaximaVoo[indiceVoo]);
        printf("\nInforme a uma poltrona valida (para encerrar digite 0): ");
        scanf("%d", &reservarAssento);
    }

    return reservarAssento;
}

void AINDA_RESERVANDO(AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int indiceVoo, int reservarAssento, int ocupacaoMaximaAeroporto[indiceVoo][reservarAssento]){
    while(reservarAssento > 0){
        ocupacaoMaximaAeroporto[indiceVoo][reservarAssento] = 1;

        printf("\nInforme a poltrona que será reservada (para encerrar digite 0): ");
        scanf("%d", &reservarAssento);

        if(reservarAssento > ocupacaoMaximaVoo[indiceVoo]){
            printf("\nA capacidade máxima do Voo %d é %d", (ponteiro_avioes + indiceVoo)->identificacaoVoo, ocupacaoMaximaVoo[indiceVoo]);
            printf("\nInforme a uma poltrona valida (para encerrar digite 0): ");
            scanf("%d", &reservarAssento);
        }
    }
}

int ESCOLHER_VOO_CANCELAMENTO(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes){
    int indiceVoo, cancelarVoo;

    for(i = 0; i < ponteiro_aeroporto->quantidadeVoos; i++){
        printf("Voo %d\n", (ponteiro_avioes + i)->identificacaoVoo);
    }
            
    printf("\nInforme o voo em que a reserva será cancelada (para encerrar digite 0): ");
    scanf("%d", &cancelarVoo);

    for(i = 0; i < ponteiro_aeroporto->quantidadeVoos; i++){
        if(cancelarVoo == (ponteiro_avioes + i)->identificacaoVoo){
            indiceVoo = i;
        }
    }

    return indiceVoo;
}

int CANCELAR_ASSENTO(AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int indiceVoo){
    int cancelarAssento;
    
    printf("\nInforme a poltrona que será cancelada (para encerrar digite 0): ");
    scanf("%d", &cancelarAssento);
    
    return cancelarAssento;
}

void AINDA_CANCELANDO(AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int indiceVoo, int cancelarAssento, int ocupacaoMaximaAeroporto[indiceVoo][cancelarAssento]){
    while(cancelarAssento > 0){
        ocupacaoMaximaAeroporto[indiceVoo][cancelarAssento] = 1;

        printf("\nInforme a poltrona que será reservada (para encerrar digite 0): ");
        scanf("%d", &cancelarAssento);
    }
}