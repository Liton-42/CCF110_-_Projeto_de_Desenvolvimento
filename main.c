#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

int main(){
    setlocale(LC_ALL, "Portuguese");

    int i, j;

    //Voos disponiveis
    int nVoo;

    printf("Informe o número de voos disponíveis: ");
    scanf("%d", &nVoo);

    //Cadastro dos voos
    int idVoo[nVoo];

    printf("\n");
    for(i = 0; i < nVoo; i++){
        printf("Cadestre o %dº voo: ", i + 1);
        scanf("%d", &idVoo[i]);
    }

    //Vagas totais no aeroporto
    int assenMax;

    printf("\nInforme a capacidade máxima de assentos suportada pelo aeroporto: ");
    scanf("%d", &assenMax);

    int ocupMax[nVoo][assenMax + 1];

    //Liberando todas as poltronas
    for(i = 0; i < nVoo; i++){
        for(j = 0; j < assenMax + 1; j++){
            ocupMax[i][j] = 0;
        }
    }

    //Vagas especificas dos aviões
    int ocupMaxVoo[nVoo];

    printf("\n");
    for(i = 0; i < nVoo; i++){
        printf("Total de assentos no Voo %d: ", idVoo[i]);
        scanf("%d", &ocupMaxVoo[i]);
    }

    //Operando poltronas
    int select, contVaga, consulVoo, reserVoo, reserAssen, cancelVoo, cancelAssen, indiceVoo;

    contVaga = 0;

    printf("Informe a operação que deseja realizar:\n");
    printf(" 1. Consultar vagas\n");
    printf(" 2. Reservar assento\n");
    printf(" 3. Cancelar reserva\n");
    printf(" 4. Sair\n");

    scanf("%d", &select);

    switch (select){
        case 1:
            printf("\n");
            for(i = 0; i < nVoo; i++){
                printf("Voo %d\n", idVoo[i]);
            }
            
            printf("\nInforme o voo para consultar as poltronas vagas (para encerrar digite 0): ");
            scanf("%d", &consulVoo);

            for(i = 0; i < nVoo; i++){
                if(consulVoo == idVoo[i]){
                    indiceVoo = i;
                }
            }

            for(j = 1; j < ocupMaxVoo[indiceVoo] + 1; j++){
                if(ocupMax[indiceVoo][j] == 0){
                    contVaga++;
                }
            }

            printf("Quantidade de poltronas livres: %d", contVaga);
            
            break;
        
        case 2:
            printf("\n");
            for(i = 0; i < nVoo; i++){
                printf("Voo %d\n", idVoo[i]);
            }
            
            printf("\nInforme o voo em que se realizara a reserva (para encerrar digite 0): ");
            scanf("%d", &reserVoo);

            for(i = 0; i < nVoo; i++){
                if(reserVoo == idVoo[i]){
                    indiceVoo = i;
                }
            }

            printf("\nInforme a poltrona que será reservada (para encerrar digite 0): ");
            scanf("%d", &reserAssen);
            
            if(reserAssen > ocupMaxVoo[indiceVoo]){
                printf("\nA capacidade máxima do Voo %d é %d", idVoo[indiceVoo], ocupMaxVoo[indiceVoo]);
                printf("\nInforme a uma poltrona valida (para encerrar digite 0): ");
                scanf("%d", &reserAssen);
            }

            while(reserAssen > 0){
                ocupMax[indiceVoo][reserAssen] = 1;

                printf("\nInforme a poltrona que será reservada (para encerrar digite 0): ");
                scanf("%d", &reserAssen);

                if(reserAssen > ocupMaxVoo[indiceVoo]){
                    printf("\nA capacidade máxima do Voo %d é %d", idVoo[indiceVoo], ocupMaxVoo[indiceVoo]);
                    printf("\nInforme a uma poltrona valida (para encerrar digite 0): ");
                    scanf("%d", &reserAssen);
                }
            }

            break;

        case 3:
            printf("\n");
            for(i = 0; i < nVoo; i++){
                printf("Voo %d\n", idVoo[i]);
            }
            
            printf("\nInforme o voo em que a reserva será cancelada (para encerrar digite 0): ");
            scanf("%d", &cancelVoo);

            for(i = 0; i < nVoo; i++){
                if(cancelVoo == idVoo[i]){
                    indiceVoo = i;
                }
            }

            printf("\nInforme a poltrona que será cancelada (para encerrar digite 0): ");
            scanf("%d", &cancelAssen);

            while(cancelAssen > 0){
                ocupMax[indiceVoo][reserAssen] = 1;

                printf("\nInforme a poltrona que será reservada (para encerrar digite 0): ");
                scanf("%d", &cancelAssen);
            }

            break;

        default:
            break;
    }

    return 0;
}