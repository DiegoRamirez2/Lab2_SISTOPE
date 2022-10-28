#include "Hijo.h"


/*
    * Constructor de la estructura hijo
    * Entrada: Nombre del archivo de entrada, el de salida, la posición inicial y final
    * desde donde leerá y hasta donde leerá.
    * Retorno: Un hijo
    * 
*/
Hijo *crearHijo(char *entrada, char *salida, int inicio, int final){
    Hijo *H = (Hijo*)malloc(sizeof(Hijo));
    strcpy(H->entrada, entrada);
    strcpy(H->salida, salida);
    H->inicio = inicio;
    H->final = final;
    H->priceExpensive = 0.0;
    H->priceCheap = 1000;
    H->average = 0.0;
    H->nWindows = 0.0;
    H->nMacOs = 0.0;
    H->nLinuxs = 0.0;
    H->nameExpensive = (char*)calloc(256, sizeof(char));
    H->nameCheap = (char*)calloc(256, sizeof(char));
    return H;
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
    * Esta función calcula el precio más alto, el precio más bajo
    * el promedio de juegos, y el porcentaje de juegos para cada
    * sistema operativo
    * Entrada: Un Hijo
    * Retorno: No retorna nada
*/
void calcularDatosAnio(Hijo *H){
    FILE *fp = fopen(H->entrada, "r");
    char linea[256];
    int i = 0;
    int j = 0;
    float precio_acum = 0;
    float precio_J;
    fseek(fp, H->inicio, SEEK_SET);
    while(fgets(linea, 256, fp)){
        precio_J = precioJuego(linea, strlen(linea));
        if(precio_J != 0.0){
            precio_acum += precio_J;
            j++;
        }
        if(Linux(linea, strlen(linea))){
            H->nLinuxs++;
        }
        if(MacOs(linea, strlen(linea))){
            H->nMacOs++;
        }
        if(Windows(linea, strlen(linea))){
            H->nWindows++;
        }
        if(precio_J > H->priceExpensive){
            H->priceExpensive = precio_J;
        }
        if(precio_J < H->priceCheap 
            && precio_J != 0.0){
            H->priceCheap = precio_J;
        }
        i++;
        memset(linea, 0, 256);
        if(ftell(fp) == H->final){
            // Esto funciona bien
            break;
        }
    }
    if(j == 0){
        H->average = precio_acum;
    }
    else{
        H->average = precio_acum / j;
    }
    H->nWindows = (H->nWindows / i) * 100;
    H->nMacOs = (H->nMacOs / i) * 100;
    H->nLinuxs = (H->nLinuxs / i) * 100;
    fclose(fp);
}
/*
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
}
/*
    * Esta función obtiene el nombre del juego más caro
    * y del juego más barato
    * Entrada: Un Hijo
    * Retorno: No retorna nada
*/
void nombreJprecio(Hijo *H){
    FILE *fp = fopen(H->entrada, "r");
    char linea[256];
    float precio_J;
    char *nombre_J;
    bool flag_expensive = true, flag_cheap = true;
    fseek(fp, H->inicio, SEEK_SET);
    while(fgets(linea, 256, fp)){
        precio_J = precioJuego(linea, strlen(linea));
        nombre_J = nombreJuego(linea, strlen(linea));
        if(precio_J == H->priceExpensive && flag_expensive){
            flag_expensive = false;
            H->nameExpensive = nombre_J;
        }
        if(precio_J == H->priceCheap && flag_cheap){
            flag_cheap = false;
            H->nameCheap = nombre_J;
        }
        memset(linea, 0, 256);
        if(ftell(fp) == H->final){
            break;
        }
    }
    fclose(fp);
}
/*
    * Esta función imprime los juegos gratis de un año
    * Entrada: Un Hijo
    * Retorno: No retorna nada
*/
void imprimirFree(Hijo *H){
    FILE *entrada = fopen(H->entrada, "r");
    FILE *fp = fopen(H->salida, "a");
    fseek(entrada, H->inicio, SEEK_SET);
    int i = 0;
    char linea[256];
    while(fgets(linea, 256, entrada)){
        if(isFree(linea, strlen(linea))){
            fputs(nombreJuego(linea, strlen(linea)), fp); fputs("\n", fp);
            i++;
        }
        memset(linea, 0, 256);
        if(ftell(entrada) == H->final){
            break;
        }
    }
    if(i == 0){
        fputs("No hay juegos gratis\n", fp);
    }
    fclose(entrada);
    fclose(fp);
}
/*
    * Esta función imprime los datos de un año
    * Entrada: Un Hijo
    * Retorno: No retorna nada
*/
void imprimirDatos(Hijo *H){
    FILE *fp = fopen(H->salida, "a");
    char expensive[6], cheap[6], average[4], windows[4], macos[4], linuxs[4];
    fputs("Juego mas caro: ", fp);
    if(H->priceExpensive == 0.0){
        fputs("No hay juegos con precio mayor al mínimo ingresado, solo gratis\n", fp);
    }else{
        fputs(H->nameExpensive, fp); fputs(" ", fp); 
        fputs(gcvt(H->priceExpensive, 6, expensive), fp); fputs("\n", fp);
    }
    fputs("Juego mas barato: ", fp);
    if(H->priceCheap == 1000){
        fputs("No hay juegos con precio mayor al mínimo ingresado, solo gratis\n", fp);
    }else{
        fputs(H->nameCheap, fp); fputs(" ", fp);
        fputs(gcvt(H->priceCheap, 6, cheap), fp); fputs("\n", fp);
    }
    fputs("Promedio de precios: ", fp); fputs(gcvt(H->average, 4, average), fp); fputs("\n", fp);
    fputs("Windows: ", fp); fputs(gcvt(H->nWindows, 4, windows), fp); fputs("% ", fp);
    fputs("Mac: ", fp); fputs(gcvt(H->nMacOs, 4, macos), fp); fputs("% ", fp);
    fputs("Linux: ", fp); fputs(gcvt(H->nLinuxs, 4, linuxs), fp); fputs("%\n", fp);
    fputs("Juegos gratis: ", fp); fputs("\n", fp);
    fclose(fp);
    imprimirFree(H);
}
/*
    * Esta función verifica si un juego es gratis
    * Entrada: Linea a leer y largo de la línea
    * Retorno: True si es gratis, False si no lo es
*/
bool isFree(char linea[], int largo){
    if(precioJuego(linea, largo) == 0.0){
        return true;
    }
    return false;
}