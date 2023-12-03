#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "structs.h"

int main(){
    setlocale(LC_ALL, "Portuguese");

    int i, j;
    AEROPORTO aeroporto;

    //Voos disponiveis
    printf("Informe o número de voos disponíveis: ");
    scanf("%d", &aeroporto.quantidadeVoos);

    //Cadastro dos voos
    AVIOES avioes[aeroporto.quantidadeVoos];

    printf("\n");
    for(i = 0; i < aeroporto.quantidadeVoos; i++){
        printf("Cadestre o %dº voo: ", i + 1);
        scanf("%d", &avioes[i].identificacaoVoo);
    }

    //Vagas totais no aeroporto
    printf("\nInforme a capacidade máxima de assentos suportada pelo aeroporto: ");
    scanf("%d", &aeroporto.maximoAssentos);

    int ocupacaoMaximaAeroporto[aeroporto.quantidadeVoos][aeroporto.maximoAssentos + 1];

    //Liberando todas as poltronas
    for(i = 0; i < aeroporto.quantidadeVoos; i++){
        for(j = 0; j < aeroporto.maximoAssentos + 1; j++){
            ocupacaoMaximaAeroporto[i][j] = 0;
        }
    }

    //Vagas especificas dos aviões
    int ocupacaoMaximaVoo[aeroporto.quantidadeVoos];

    printf("\n");
    for(i = 0; i < aeroporto.quantidadeVoos; i++){
        printf("Total de assentos no Voo %d: ", avioes[i].identificacaoVoo);
        scanf("%d", &ocupacaoMaximaVoo[i]);
    }

    //Operando poltronas
    int select, contVaga, consultarVoo, reservarVoo, reservarAssento, cancelarVoo, cancelarAssento, indiceVoo;

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
            for(i = 0; i < aeroporto.quantidadeVoos; i++){
                printf("Voo %d\n", avioes[i].identificacaoVoo);
            }
            
            printf("\nInforme o voo para consultar as poltronas vagas (para encerrar digite 0): ");
            scanf("%d", &consultarVoo);

            for(i = 0; i < aeroporto.quantidadeVoos; i++){
                if(consultarVoo == avioes[i].identificacaoVoo){
                    indiceVoo = i;
                }
            }

            for(j = 1; j < ocupacaoMaximaVoo[indiceVoo] + 1; j++){
                if(ocupacaoMaximaAeroporto[indiceVoo][j] == 0){
                    contVaga++;
                }
            }

            printf("Quantidade de poltronas livres: %d", contVaga);
            
            break;
        
        case 2:
            printf("\n");
            for(i = 0; i < aeroporto.quantidadeVoos; i++){
                printf("Voo %d\n", avioes[i].identificacaoVoo);
            }
            
            printf("\nInforme o voo em que se realizara a reserva (para encerrar digite 0): ");
            scanf("%d", &reservarVoo);

            for(i = 0; i < aeroporto.quantidadeVoos; i++){
                if(reservarVoo == avioes[i].identificacaoVoo){
                    indiceVoo = i;
                }
            }

            printf("\nInforme a poltrona que será reservada (para encerrar digite 0): ");
            scanf("%d", &reservarAssento);
            
            if(reservarAssento > ocupacaoMaximaVoo[indiceVoo]){
                printf("\nA capacidade máxima do Voo %d é %d", avioes[indiceVoo].identificacaoVoo, ocupacaoMaximaVoo[indiceVoo]);
                printf("\nInforme a uma poltrona valida (para encerrar digite 0): ");
                scanf("%d", &reservarAssento);
            }

            while(reservarAssento > 0){
                ocupacaoMaximaAeroporto[indiceVoo][reservarAssento] = 1;

                printf("\nInforme a poltrona que será reservada (para encerrar digite 0): ");
                scanf("%d", &reservarAssento);

                if(reservarAssento > ocupacaoMaximaVoo[indiceVoo]){
                    printf("\nA capacidade máxima do Voo %d é %d", avioes[indiceVoo].identificacaoVoo, ocupacaoMaximaVoo[indiceVoo]);
                    printf("\nInforme a uma poltrona valida (para encerrar digite 0): ");
                    scanf("%d", &reservarAssento);
                }
            }

            break;

        case 3:
            printf("\n");
            for(i = 0; i < aeroporto.quantidadeVoos; i++){
                printf("Voo %d\n", avioes[i].identificacaoVoo);
            }
            
            printf("\nInforme o voo em que a reserva será cancelada (para encerrar digite 0): ");
            scanf("%d", &cancelarVoo);

            for(i = 0; i < aeroporto.quantidadeVoos; i++){
                if(cancelarVoo == avioes[i].identificacaoVoo){
                    indiceVoo = i;
                }
            }

            printf("\nInforme a poltrona que será cancelada (para encerrar digite 0): ");
            scanf("%d", &cancelarAssento);

            while(cancelarAssento > 0){
                ocupacaoMaximaAeroporto[indiceVoo][reservarAssento] = 1;

                printf("\nInforme a poltrona que será reservada (para encerrar digite 0): ");
                scanf("%d", &cancelarAssento);
            }

            break;

        default:
            break;
    }

    return 0;
}