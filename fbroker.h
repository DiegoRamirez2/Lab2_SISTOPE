#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

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
    char entrada[100];
    char salida[100];
    int anio;
    float precio_minimo;
    bool mostrar;
    int n_workers;
    int n_anios;
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
void agregarListYear(ListY *listYear, char *String); // Función que agrega un año a la lista de años
int obtenerAnio(char linea[], int largo); // Función que obtiene el año de una linea
int buscarAnio(int anio, int *anios); // Función que verifica si un año ya fue agregado
Broker* crearBroker(char input_[], char output_[], int year_, float minimun_price_, bool show_, int n_workers_); // Función que crea un padre
int ordenarAnios(const void *a, const void *b); // Función que ordena los años
float obtenerPrecio(char linea[], int largo); // Función que obtiene el precio de una linea
int *obtenerAnios(Broker *B); // Función que obtiene los años de un archivo
void Ejecutar(Broker *B); // Función que ejecuta el programa
void escribirArchivo(ListY *listYear, char *salida); // Función que escribe en un archivo
