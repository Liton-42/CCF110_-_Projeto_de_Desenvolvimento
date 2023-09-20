#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

int main(){
    setlocale(LC_ALL, "Portuguese");

    int nVoo, selectVaga, i, consulVoo, reserVoo, cancelVoo; //nVoo = 3;

    //Criar o trecho para cadastrar voos
    //Voos disponiveis
    int voo[] = {42, 77, 214};

    //Criar o trecho para  cadastrar as poltronas
    //Vagas totais nos voos
    int assenTemp;

    assenTemp = 411;
    int vagaVoo042[assenTemp], vagaVoo077[assenTemp], vagaVoo214[assenTemp], contVaga, reserAssen,
        cancelAssen;

    contVaga = 0;

    for(i = 0; i < assenTemp; i++){
        vagaVoo042[i] = 0;//rand()%2;
        vagaVoo077[i] = 0;//rand()%2;
        vagaVoo214[i] = 0;//rand()%2;
    }

    //Operando poltronas
    printf("Informe a operação que deseja realizar:\n");
    printf(" 1. Consultar vagas\n");
    printf(" 2. Reservar assento\n");
    printf(" 3. Cancelar reserva\n");
    printf(" 4. Sair\n");

    scanf("%d", &selectVaga);

    switch (selectVaga){
        case 1:
            printf("\n");
            for(i = 0; i < 3; i++){
                printf("Voo %d\n", voo[i]);
            }
            
            printf("\nInforme o voo para consultar as poltronas vagas (para encerrar digite 0): ");
            scanf("%d", &consulVoo);

            if(consulVoo == voo[0]){
                for(i = 1; i < assenTemp; i++){
                    if(vagaVoo042[i] == 0){
                        printf("  Poltrona %d\n", i);
                        contVaga++;
                    }
                }

                printf("Quantidade de poltronas livres: %d", contVaga);
            }
            else if(consulVoo == voo[1]){
                for(i = 1; i < assenTemp; i++){
                    if(vagaVoo077[i] == 0){
                        printf("  Poltrona %d\n", i);
                        contVaga++;
                    }
                }

                printf("Quantidade de poltronas livres: %d", contVaga);
            }
            else if(consulVoo == voo[2]){
                for(i = 1; i < assenTemp; i++){
                    if(vagaVoo214[i] == 0){
                        printf("  Poltrona %d\n", i);
                        contVaga++;
                    }
                }

                printf("Quantidade de poltronas livres: %d", contVaga);
            }
            else if(consulVoo == 0){
                break;
            }
            else{
                printf("Informe um valor válido: ");
                scanf("%d", &consulVoo);
            }
            break;
        
        //Adicionar verificação da disponibilidade da poltrona antes de "mudar" o status da vaga
        case 2:
            printf("\n");
            for(i = 0; i < 3; i++){
                printf("Voo %d\n", voo[i]);
            }
            
            printf("\nInforme o voo em que se realizara a reserva (para encerrar digite 0): ");
            scanf("%d", &reserVoo);
            
            if(reserVoo == voo[0]){
                printf("\nInforme a poltrona que sera reservada (para encerrar digite 0 ou um valor acima da capacidade máxima): ");
                scanf("%d", &reserAssen);
                
                while(reserAssen > 0){
                    vagaVoo042[reserAssen] = 1;

                    printf("\nInforme a poltrona que sera reservada (para encerrar digite 0 ou um valor acima da capacidade máxima): ");
                    scanf("%d", &reserAssen);
                }
            }
            else if(reserVoo == voo[1]){
                printf("\nInforme as poltronas que sera reservadas (para encerrar digite 0 ou um valor acima da capacidade máxima): ");
                scanf("%d", &reserAssen);
                
                while(reserAssen > 0){
                    vagaVoo077[reserAssen] = 1;

                    printf("\nInforme a poltrona que sera reservada (para encerrar digite 0 ou um valor acima da capacidade máxima): ");
                    scanf("%d", &reserAssen);
                }
            }
            else if(reserVoo == voo[2]){
                printf("\nInforme as poltronas que sera reservadas (para encerrar digite 0 ou um valor acima da capacidade máxima): ");
                scanf("%d", &reserAssen);
                
                while(reserAssen > 0){
                    vagaVoo214[reserAssen] = 1;

                    printf("\nInforme a poltrona que sera reservada (para encerrar digite 0 ou um valor acima da capacidade máxima): ");
                    scanf("%d", &reserAssen);
                }
            }
            else if(reserVoo == 0){
                break;
            }
            else{
                printf("Informe um valor válido: ");
                scanf("%d", &reserVoo);
            }
            break;

        //Adicionar verificação da disponibilidade da poltrona antes de "mudar" o status da vaga
        case 3:
            printf("\n");
            for(i = 0; i < 3; i++){
                printf("Voo %d\n", voo[i]);
            }
            
            printf("\nInforme o voo em que se realizara a reserva (para encerrar digite 0): ");
            scanf("%d", &cancelVoo);
            
            if(cancelVoo == voo[0]){
                printf("\nInforme a poltrona que sera reservada (para encerrar digite 0 ou um valor acima da capacidade máxima): ");
                scanf("%d", &cancelAssen);
                
                while(cancelAssen > 0){
                    vagaVoo042[cancelAssen] = 0;

                    printf("\nInforme a poltrona que sera reservada (para encerrar digite 0 ou um valor acima da capacidade máxima): ");
                    scanf("%d", &cancelAssen);
                }
            }
            else if(cancelVoo == voo[1]){
                printf("\nInforme as poltronas que sera reservadas (para encerrar digite 0 ou um valor acima da capacidade máxima): ");
                scanf("%d", &cancelAssen);
                
                while(cancelAssen > 0){
                    vagaVoo077[cancelAssen] = 0;

                    printf("\nInforme a poltrona que sera reservada (para encerrar digite 0 ou um valor acima da capacidade máxima): ");
                    scanf("%d", &cancelAssen);
                }
            }
            else if(cancelVoo == voo[2]){
                printf("\nInforme as poltronas que sera reservadas (para encerrar digite 0 ou um valor acima da capacidade máxima): ");
                scanf("%d", &cancelAssen);
                
                while(cancelAssen > 0){
                    vagaVoo214[cancelAssen] = 0;

                    printf("\nInforme a poltrona que sera reservada (para encerrar digite 0 ou um valor acima da capacidade máxima): ");
                    scanf("%d", &cancelAssen);
                }
            }
            else if(cancelVoo == 0){
                break;
            }
            else{
                printf("Informe um valor válido: ");
                scanf("%d", &cancelVoo);
            }
            break;

        default:
            break;
        }

    return 0;
}