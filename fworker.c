#include "fworker.h"

/*
    * Esta función crea una estructura año que almacenará los datos de un año
    * Entrada: Un entero que representa el año
    * Retorno: Un puntero a una estructura año
*/
Anio *crearAnio(char linea[], int largo){
    Anio *A = (Anio *)malloc(sizeof(Anio));
    A->anio = obtenerAnio(linea, largo);
    A->nGames = 1;
    A->cheapGame = "No hay juegos más baratos, solo gratis";
    A->expensiveGame = "No hay juegos más caros, solo gratis";
    if(precioJuego(linea, largo) != 0.0){
        A->cheapGame =  nombreJuego(linea, largo);
        A->expensiveGame = nombreJuego(linea, largo);
        A->cheapPrice = precioJuego(linea, largo);
        A->expensivePrice = precioJuego(linea, largo);
        A->priceAcum = precioJuego(linea, largo);
        A->freeGames = crearFG();
    }
    else{
        A->cheapGame = "No hay juegos más baratos, solo gratis";
        A->expensiveGame = "No hay juegos más caros, solo gratis";
        A->cheapPrice = 1000.0;
        A->expensivePrice = 0.0;
        A->priceAcum = 0.0;
        A->freeGames = crearFG2(nombreJuego(linea, largo));
    }
    if(Windows(linea, largo)){
        A->nWindows = 1.0;
    }else{
        A->nWindows = 0.0;
    }
    if(MacOs(linea, largo)){
        A->nMacOs = 1.0;
    }else{
        A->nMacOs = 0.0;
    }
    if(Linux(linea, largo)){
        A->nLinux = 1.0;
    }else{
        A->nLinux = 0.0;
    }
    return A;
}
/*
    * Esta función crea una lista de juegos gratis
    * Entrada: void
    * Retorno: Un puntero a una estructura freeGames
*/
FG *crearFG(){
    FG *nuevoFG = (FG *)malloc(sizeof(FG));
    nuevoFG->nameGame = (char *)calloc(256, sizeof(char));
    nuevoFG->next = NULL;
    return nuevoFG;
}
/*
    * Esta función crea una lista de juegos gratis con un juego
    * Entrada: Un puntero a un arreglo de caracteres que representa el nombre del juego
    * Retorno: Un puntero a una estructura freeGames
*/
FG *crearFG2(char *nameGame){
    FG *nuevoFG = (FG *)malloc(sizeof(FG));
    nuevoFG->nameGame = (char *)calloc(256, sizeof(char));
    strcpy(nuevoFG->nameGame, nameGame);
    nuevoFG->next = NULL;
    return nuevoFG;
}
/*
    * Esta funcion entrega la posicion después de la coma n ingresada
    * Entrada: Linea a leer, largo de la línea y número de comas que se
    * quieren saltar
    * Retorno: Posición después de la coma n
*/
int posicion(char linea[], int largo, int comas){
    int cont = 0;
    while(cont != comas){
        if(linea[largo] == ','){
            cont++;
        }
        largo--;
    }
    return largo + 2;
}
/*
    * Esta función verifica si un juego está para Linux
    * Entrada: Linea a leer y largo de la línea
    * Retorno: True si es para Linux, False si no lo es
*/
bool Linux(char linea[], int largo){
    if(linea[posicion(linea, largo, 1)] == 'Y'){
        return true;
    }
    else{
        return false;
    }
}
/*
    * Esta función verifica si un juego está para MacOs
    * Entrada: Linea a leer y largo de la línea
    * Retorno: True si es para Windows, False si no lo es
*/
bool MacOs(char linea[], int largo){
    if(linea[posicion(linea, largo, 2)] == 'Y'){
        return true;
    }
    else{
        return false;
    }
}
/*
    * Esta función verifica si un juego está para MacOs
    * Entrada: Linea a leer y largo de la línea
    * Retorno: True si es para MacOs, False si no lo es
*/
bool Windows(char linea[], int largo){
    if(linea[posicion(linea, largo, 3)] == 'Y'){
        return true;
    }
    else{
        return false;
    }
}
/*
    * Esta función obtiene el nombre de un juego
    * Entrada: Linea a leer y largo de la línea
    * Retorno: Nombre del juego
*/
char *nombreJuego(char linea[], int largo){
    int pos = posicion(linea, largo, 9);
    int i = 0;
    char *nombre = (char*)calloc(100, sizeof(char));
    while(linea[pos] != ','){
        nombre[i] = linea[pos];
        i++;
        pos++;
    }
    return nombre;
}/*
    * Esta función obtiene el precio de un juego
    * Entrada: Linea a leer y largo de la línea
    * Retorno: Precio del juego
*/
float precioJuego(char linea[], int largo){
    int i = posicion(linea, largo, 7);
    char *precio = (char*)calloc(10, sizeof(char));
    int j = 0;
    while(linea[i] != ','){
        precio[j] = linea[i];
        j++;
        i++;
    }
    return atof(precio);
}
/*
    * Esta función obtiene los años de cada juego del archivo de entrada
    * Entrada: Recibe la linea a evaluar, y el largo de la línea
    * Salida: Retorna el año del juego
*/
int obtenerAnio(char linea[], int largo){
    int comas = 0;
    while(comas != 5){
        if(linea[largo] == ','){
            comas++;
        }
        largo--;
    }
    char anio[4] = {linea[largo + 2], linea[largo + 3],
    linea[largo + 4], linea[largo + 5]};
    return atoi(anio);
}
/*

*/
void agregarJuegoGratis(Anio *A, char *nombreJuego){
    if(A->freeGames->next == NULL && A->freeGames->nameGame[0] == '\0'){
        A->freeGames->nameGame = nombreJuego;
    }
    else{
        FG *aux = A->freeGames;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = crearFG2(nombreJuego);
    }
}
/*

*/
void compararAnio(Anio *A, char linea[], int largo){
    if(A->cheapPrice > precioJuego(linea, largo) && precioJuego(linea, largo) != 0.0){
        A->cheapPrice = precioJuego(linea, largo);
        A->cheapGame = nombreJuego(linea, largo);
    }
    if(A->expensivePrice < precioJuego(linea, largo) && precioJuego(linea, largo) != 0.0){
        A->expensivePrice = precioJuego(linea, largo);
        A->expensiveGame = nombreJuego(linea, largo);
    }
    if(Windows(linea, largo)){
        A->nWindows++;
    }
    if(MacOs(linea, largo)){
        A->nMacOs++;
    }
    if(Linux(linea, largo)){
        A->nLinux++;
    }
    A->nGames++;
    A->priceAcum += precioJuego(linea, largo);
    if(precioJuego(linea, largo) == 0.0){
        agregarJuegoGratis(A, nombreJuego(linea, largo));
        }
}
/*
*/
LA *crearLA(){
    LA *nuevoLA = (LA*)malloc(sizeof(LA));
    nuevoLA->next = NULL;
    return nuevoLA;
}
/*
*/
LA *crearLA2(Anio *A){
    LA *nuevoLA = (LA*)malloc(sizeof(LA));
    nuevoLA->next = NULL;
    nuevoLA->anio = A;
    return nuevoLA;
}
/*
*/
void agregarAnio(LA *L, char linea[], int largo){
    bool existe = false;
    //printf("Estamos en agregarAnio\n");
    if(L->anio == NULL){
        //printf("La lista de años está vacía\n");
        L->anio = crearAnio(linea, largo);
    }
    else{
        LA *aux = L;
        while(aux->next != NULL){
            if(aux->anio->anio == obtenerAnio(linea, largo)){
                //printf("Se comparan los años\n");
                existe = true;
                compararAnio(aux->anio, linea, largo);
            }
            aux = aux->next;
        }
        if(aux->anio->anio == obtenerAnio(linea, largo)){
            //printf("Se comparan los años\n");
            existe = true;
            compararAnio(aux->anio, linea, largo);
        }
        if(!existe){
            //printf("Se agregó un nuevo año\n");
            aux->next = crearLA2(crearAnio(linea, largo));
            //printf("No falló esta wea\n");
        }
    }
}

void ImprimirLista(LA *L){
    if(L == NULL){
        printf("No hay datos para mostrar");
    }
    else{
        LA *aux = L;
        while(aux != NULL){
            printf("El anio es: %d\n", aux->anio->anio);
            printf("El juego más caro es: %s\n", aux->anio->expensiveGame);
            printf("El juego más barato es: %s\n", aux->anio->cheapGame);
            printf("El precio más barato es: %f\n", aux->anio->cheapPrice);
            printf("El precio más caro es: %f\n", aux->anio->expensivePrice);
            printf("El promedio de precios es: %f\n", aux->anio->priceAcum);
            printf("La cantidad de juegos es: %d\n", aux->anio->nGames);
            printf("La cantidad de juegos en Windows es: %f\n", aux->anio->nWindows);
            printf("La cantidad de juegos en MacOs es: %f\n", aux->anio->nMacOs);
            printf("La cantidad de juegos en Linux es: %f\n", aux->anio->nLinux);
            ImprimirGratis(aux->anio);
            printf("\n");
            aux = aux->next;
        }
    }
}

void ImprimirGratis(Anio *A){
    if(A->freeGames == NULL || A->freeGames->nameGame[0] == '\0'){
        printf("No hay juegos gratis\n");
    }
    else{
        FG *aux = A->freeGames;
        while(aux != NULL){
            printf("El juego gratis es: %s\n", aux->nameGame);
            aux = aux->next;
        }
    }
}