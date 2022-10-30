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
FreeG *createFreeG(); // Función que crea una lista de juegos gratis vacía
void agregarFreeGame(char *nameGame); // Función que agrega un juego a la lista de juegos gratis
