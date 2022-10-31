#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct freeGames{
    char *name;
    struct freeGames *next;
}FreeG;

typedef struct year{
    int year;
    float priceExpensive;
    float priceCheap;
    char *nameExpensive;
    char *nameCheap;
    float priceAcum;
    float nWindows;
    float nMacOs;
    float nLinux;
    int nGames;
    int nNotFree;
    FreeG *freeGames;
}Year;

typedef struct listYears{
    Year *year;
    struct listYears *next;
}ListY;

typedef struct broker{
}Broker;


// Funciones
Year *crearYear(char *String); // Función que crea un año
Year *copiarYear(Year *Y); // Función que crea un año
ListY *crearListY(); // Función que crea una lista de años vacía
ListY *crearListY2(char *String); // Función que crea una lista de años vacía
FreeG *crearFreeG(); // Función que crea una lista de juegos gratis vacía
FreeG *crearFreeG2(char *name); // Función que crea una lista de juegos gratis con un juego
void agregarFreeGame(char *nameGame); // Función que agrega un juego a la lista de juegos gratis
void agregarFreeG(Year *Y, char *nameGame); // Función que agrega un juego a la lista de juegos gratis
void agregarYear(ListY *listYear, Year *Y); // Función que agrega un año a la lista de años
void compararYear(Year *Y1, Year *Y2); // Función que compara un año con la lista de años
void ImprimirYear(Year *Y); // Función que imprime un año