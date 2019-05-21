#include <stdio.h>
#include <stdlib.h>
void limpar(int** arr, int linhas, int colunas);
void imprimirArray(int** arr, int linhas, int colunas);

int main()
{
    int linhas, colunas;
    FILE * fReserva = fopen("C:/Users/aluno/Desktop/Reserva/SalaAloisio.csv", "rt");
    if(fReserva == NULL){
        printf("Falhou");
        exit(1);
    }
    printf("Sucesso");
    fscanf(fReserva, "%d;", &linhas);
    fscanf(fReserva, "%d", &colunas);

    printf("Linhas: %d\n", linhas);
    printf("Colunas: %d\n", colunas);

    //Alocação
    int** reserva = (int**) malloc( sizeof(int*) * linhas);
    for(int i = 0; i < linhas; i++){
        reserva[i] = (int*) malloc(sizeof(int)*colunas);
    }

    limpar(reserva, linhas, colunas);

    for(int y = 0; y < linhas; y++){
        for(int x = 0; x < colunas; x++){
            fscanf(fReserva, "%d;", &reserva[y][x]);
        }
    }
    for(int i = 0; i < linhas; i++){
        fscanf(fReserva, "%d\n", &reserva[29][i]);
    }

    imprimirArray(reserva, linhas, colunas);

    int pcoluna, plinha;
    printf("Posição da linha: ");
    scanf("%d", &plinha);
    printf("Posição da coluna: ");
    scanf("%d", &pcoluna);



    imprimirArray(reserva, linhas, colunas);
    fclose(fReserva);
    return 0;
}

void limpar(int** arr, int linhas, int colunas){
    for(int y = 0; y < linhas; y++){
        for(int x = 0; x < colunas; x++){
            arr[y][x] = 0;
        }
    }
}

void imprimirArray(int** arr, int linhas, int colunas){
    for(int y = 0; y < linhas; y++){
        printf("%03d)", y);
        for(int x = 0; x < colunas; x++){
            printf(" %d |", arr[y][x]);
        }
        printf("\n");
    }

}

