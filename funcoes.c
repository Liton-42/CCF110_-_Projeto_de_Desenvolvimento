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

void CONSULTAR_VAGAS(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos + 1]){
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

void RESERVAR_ASSENTO(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos + 1]){
    int indiceVoo, reservarVoo, reservarAssento;

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

    printf("\nInforme a poltrona que será reservada (para encerrar digite 0): ");
        scanf("%d", &reservarAssento);
            
    if(reservarAssento > ocupacaoMaximaVoo[indiceVoo]){
        printf("\nA capacidade máxima do Voo %d é %d", (ponteiro_avioes + indiceVoo)->identificacaoVoo, ocupacaoMaximaVoo[indiceVoo]);
        printf("\nInforme a uma poltrona valida (para encerrar digite 0): ");
        scanf("%d", &reservarAssento);
    }

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

void CANCELAR_ASSENTO(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos + 1]){
    int indiceVoo, cancelarVoo, cancelarAssento;

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
    
    printf("\nInforme a poltrona que será cancelada (para encerrar digite 0): ");
    scanf("%d", &cancelarAssento);

    while(cancelarAssento > 0){
        ocupacaoMaximaAeroporto[indiceVoo][cancelarAssento] = 1;

        printf("\nInforme a poltrona que será reservada (para encerrar digite 0): ");
        scanf("%d", &cancelarAssento);
    }
}

void MENU(AEROPORTO *ponteiro_aeroporto, AVIOES *ponteiro_avioes, int ocupacaoMaximaVoo[], int ocupacaoMaximaAeroporto[][ponteiro_aeroporto->maximoAssentos + 1]){
    int select;

    printf("\n");
    printf("Informe a operação que deseja realizar:\n");
    printf(" 1. Consultar vagas\n");
    printf(" 2. Reservar assento\n");
    printf(" 3. Cancelar reserva\n");
    printf(" 4. Sair\n");

    scanf("%d", &select);

    while (select != 4){
        switch (select){
            case 1:
                printf("\n");
                CONSULTAR_VAGAS(ponteiro_aeroporto, ponteiro_avioes, ocupacaoMaximaVoo, ocupacaoMaximaAeroporto);
                
                break;
            
            case 2:
                printf("\n");
                RESERVAR_ASSENTO(ponteiro_aeroporto, ponteiro_avioes, ocupacaoMaximaVoo, ocupacaoMaximaAeroporto);

                break;

            case 3:
                printf("\n");
                CANCELAR_ASSENTO(ponteiro_aeroporto, ponteiro_avioes, ocupacaoMaximaVoo, ocupacaoMaximaAeroporto);

                break;

            case 4:
                break;
            
            default:
                printf("\nSeleção inválida.");

                break;
        }
    printf("\n\n");
    printf("Informe a operação que deseja realizar:\n");
    printf(" 1. Consultar vagas\n");
    printf(" 2. Reservar assento\n");
    printf(" 3. Cancelar reserva\n");
    printf(" 4. Sair\n");

        scanf("%d", &select);
    }
}