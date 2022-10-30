#include "fbroker.h"




Year *crearYear(char *String){
    Year *N = (Year*)malloc(sizeof(Year));
    //printf("El string ingresado es: %s\n", String);
    char *token = strtok(String, ",");
    printf("El token es: %s\n", token);
    N->year = atoi(token);
    token = strtok(NULL, ",");
    printf("El token es: %s\n", token);
    N->nameExpensive = token;
    token = strtok(NULL, ",");
    printf("El token es: %s\n", token);
    N->nameCheap = token;
    token = strtok(NULL, ",");
    printf("El token es: %s\n", token);
    N->priceExpensive = atof(token);
    token = strtok(NULL, ",");
    printf("El token es: %s\n", token);
    N->priceCheap = atof(token);
    token = strtok(NULL, ",");
    printf("El token es: %s\n", token);
    N->priceAcum = atof(token);
    token = strtok(NULL, ",");
    printf("El token es: %s\n", token);
    N->nGames = atoi(token);
    token = strtok(NULL, ",");
    printf("El token es: %s\n", token);
    N->nWindows = atof(token);
    token = strtok(NULL, ",");
    printf("El token es: %s\n", token);
    N->nMacOs = atof(token);
    token = strtok(NULL, ",");
    printf("El token es: %s\n", token);
    N->nLinux = atof(token);
    token = strtok(NULL, ",");
    printf("El token es: %s\n", token);
    while(token != NULL){
            printf("El token 3 es: %s\n", token);
            //A->freeGames = crearFG(token3, strlen(token3));
            token = strtok(NULL, ",");
        }
    return N;
}
/*
    * Esta función convierte un string a una lista de años, funcionará
    * como "desencriptador" para recibir mensajes entre procesos.
    * Entrada: String con los datos de la lista de años.
    * Retorno: Lista de años.
*/
/*
ListY *convertirAlista(char *string){
    ListY *Y = crearListY();
    char *token = strtok(string, "¿");
    // /*
    int i = 0;
    while(token != NULL){
        agregarAnio()
        //L = crearLA2(A);
        token = strtok(NULL, "¿");
    // 
    }
    printf("I es: %d\n", i);
    return L;
}

char *AnioAstring(char *string){
        char *token2 = strtok(string, ",");
        printf("El token 2 es: %s\n", token2);
        //Anio *A = (Anio*)malloc(sizeof(Anio));
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //strcpy(A->expensiveGame, token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //strcpy(A->cheapGame, token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);  
        //A->cheapPrice = atof(token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //A->expensivePrice = atof(token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //A->priceAcum = atof(token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //A->nGames = atoi(token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //A->nWindows = atof(token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //A->nMacOs = atof(token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //A->nLinux = atof(token2);
        token2= strtok(NULL, ",");
        i++;
        while(token2 != NULL){
            printf("El token 3 es: %s\n", token2);
            //A->freeGames = crearFG(token3, strlen(token3));
            token2 = strtok(NULL, ",");
        }
}
*/