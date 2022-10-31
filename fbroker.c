#include "fbroker.h"



/*
    *  Función que crea un año a partir de un mensaje con formato
    *  Entrada: String con el mensaje con formato
    *  Salida: Puntero a la estructura Year
*/
Year *crearYear(char *String){
    Year *N = (Year*)malloc(sizeof(Year));
    N->freeGames = crearFreeG();
    //printf("El string ingresado es: %s\n", String);
    char *token = strtok(String, ",");
    N->year = atoi(token);
    token = strtok(NULL, ",");
    N->nameExpensive = token;
    token = strtok(NULL, ",");
    N->nameCheap = token;
    token = strtok(NULL, ",");
    N->priceExpensive = atof(token);
    token = strtok(NULL, ",");
    N->priceCheap = atof(token);
    token = strtok(NULL, ",");
    N->priceAcum = atof(token);
    token = strtok(NULL, ","); 
    N->nGames = atoi(token);
    token = strtok(NULL, ","); 
    N->nNotFree = atoi(token);
    token = strtok(NULL, ",");  
    N->nWindows = atof(token);
    token = strtok(NULL, ",");   
    N->nMacOs = atof(token);
    token = strtok(NULL, ",");   
    N->nLinux = atof(token);
    token = strtok(NULL, ",");
    while(token != NULL){
        agregarFreeG(N, token);
        token = strtok(NULL, ",");
    }
    return N;
}
/*
    * Esta funcion crea una lista de juegos gratis
    * Entrada: void
    * Salida: Puntero a la estructura FreeG
*/
FreeG *crearFreeG(){
    FreeG *F = (FreeG*)malloc(sizeof(FreeG));
    F->name = (char *)calloc(256, sizeof(char));
    F->next = NULL;
    return F;
}
/*
    * Esta función crea una lista de juegos gratis con un juego
    * Entrada: Un puntero a un arreglo de caracteres que representa el nombre del juego
    * Retorno: Un puntero a una estructura freeGames
*/
FreeG *crearFreeG2(char *name){
    FreeG *F = (FreeG *)malloc(sizeof(FreeG));
    F->name = (char *)calloc(256, sizeof(char));
    strcpy(F->name, name);
    F->next = NULL;
    return F;
}
/*
    * Esta función añade un juego gratis a un año especifico
    * Entrada: Año al que se le quiere añadir el juego, nombre del juego
    * Retorno: void
*/
void agregarFreeG(Year *Y, char *nombreJ){
    if(Y->freeGames->next == NULL && Y->freeGames->name[0] == '\0'){
        Y->freeGames->name = nombreJ;
    }
    else{
        FreeG *aux = Y->freeGames;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = crearFreeG2(nombreJ);
    }
}
/*
    * Esta función crea una lista de años
    * Entrada: void
    * Retorno: Un puntero a una estructura Year
*/
ListY *crearListY(){
    ListY *L = (ListY*)malloc(sizeof(ListY));
    L->next = NULL;
    return L;
}
/*
    * Esta función crea una lista de años con un año
    * Entrada: Un puntero a una estructura Year
    * Retorno: Un puntero a una estructura ListY
*/
ListY *crearListY2(char *String){
    ListY *L = crearListY();
    char *token = strtok(String, "¿");
    char **array = (char **)calloc(40, sizeof(char *));
    int i = 0;
    while(token != NULL){
        array[i] = token;
        printf("%s\n", token);
        token = strtok(NULL, "¿");
        i++;
    }
    for(int j = 0; j < i; j++){
        agregarYear(L, crearYear(array[j]));
    }
    return L;
}
/*
    * Esta función añade un año a una lista de años
    * Entrada: Lista de años, año a añadir
    * Retorno: void
*/
void agregarYear(ListY *L, Year *Y){
    bool existe = false;
    if(L->year == NULL){
        printf("Entramos a la condicion 1\n");
        L->year = copiarYear(Y);
        printf("Falló esta wea\n");
    }else{
        ListY *aux = L->next;
        while(aux->next != NULL){
            printf("Estamos en el while\n");
            if(aux->year->year == Y->year){
                printf("Entramos a la condicion 2\n");
                existe = true;
                compararYear(aux->year, Y);
            }
            aux = aux->next;
        }
        if(aux->year->year == Y->year){
            printf("Entramos a la condicion 3\n");
            existe = true;
            compararYear(aux->year, Y);
        }
        if(!existe){
            printf("Entramos a la condicion 4\n");
            aux->next = crearListY();
            aux->next->year = Y;
        }
    }
}
/*
*/
Year *copiarYear(Year *Y){
    Year *N = (Year*)malloc(sizeof(Year));
    N->freeGames = crearFreeG();
    N->year = Y->year;
    N->nameExpensive = Y->nameExpensive;
    N->nameCheap = Y->nameCheap;
    N->priceExpensive = Y->priceExpensive;
    N->priceCheap = Y->priceCheap;
    N->priceAcum = Y->priceAcum;
    N->nGames = Y->nGames;
    N->nNotFree = Y->nNotFree;
    N->nWindows = Y->nWindows;
    N->nMacOs = Y->nMacOs;
    N->nLinux = Y->nLinux;
    printf("Todavìa no falla\n");
    FreeG *aux = Y->freeGames;
    printf("Si no falla hasta aqui, falla en el while\n");
    while(aux->next != NULL){
        printf("Entra al while\n");
        //agregarFreeG(N, aux->name);
        aux = aux->next;
    }
    //agregarFreeG(N, aux->name);
    return N;
}
/*
    * Esta función compara dos años y actualiza los datos del año que ya existe
    * Entrada: Año que ya existe, año que se quiere comparar
    * Retorno: void
*/
void compararYear(Year *Y1, Year *Y2){
    if(Y1->priceExpensive < Y2->priceExpensive){
        Y1->priceExpensive = Y2->priceExpensive;
        Y1->nameExpensive = Y2->nameExpensive;
    }
    if(Y1->priceCheap > Y2->priceCheap){
        Y1->priceCheap = Y2->priceCheap;
        Y1->nameCheap = Y2->nameCheap;
    }
    Y1->priceAcum += Y2->priceAcum;
    Y1->nGames += Y2->nGames;
    Y1->nNotFree += Y2->nNotFree;
    Y1->nWindows += Y2->nWindows;
    Y1->nMacOs += Y2->nMacOs;
    Y1->nLinux += Y2->nLinux;
    FreeG *aux = Y2->freeGames;
    while(aux->next != NULL){
        agregarFreeG(Y1, aux->name);
        aux = aux->next;
    }
    agregarFreeG(Y1, aux->name);
}
/*
*/
void ImprimirYear(Year *Y){
    printf("El año es: %d\n", Y->year);
    printf("El juego más caro es: %s\n", Y->nameExpensive);
    printf("El precio del juego más caro es: %f\n", Y->priceExpensive);
    printf("El juego más barato es: %s\n", Y->nameCheap);
    printf("El precio del juego más barato es: %f\n", Y->priceCheap);
    printf("El precio acumulado es: %f\n", Y->priceAcum);
    printf("La cantidad de juegos es: %d\n", Y->nGames);
    printf("La cantidad de juegos no gratis es: %d\n", Y->nNotFree);
    printf("Los juegos de Windows son: %f\n", Y->nWindows);
    printf("Los juegos de MacOs son: %f\n", Y->nMacOs);
    printf("Los juegos de Linux son: %f\n", Y->nLinux);
    while(Y->freeGames != NULL){
        printf("El juego gratis es: %s\n", Y->freeGames->name);
        Y->freeGames = Y->freeGames->next;
    }
}