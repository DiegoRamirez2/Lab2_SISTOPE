#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "Hijo.h"

/* 
    * Esta estructura representará al proceso padre
    * Va a almacenar el archivo de entrada, y el de salida
    * el cual se lo otorgará al hijo para que lo sobreescribe
    * además el poseerá el año desde el cual se filtrará y el
    * precio mínimo que se filtrará, también poseerá un booleano
    * que indicará si se mostrará por consola o no y un entero
    * que almacenará la cantidad de años que se encontraron
*/
typedef struct padre{
    char entrada[100];
    char salida[100];
    int anio;
    float precio_minimo;
    bool mostrar;
    int n_anios;
    int n_pos;
}Padre;

// Funciones
Padre* crearPadre(char input[], char output[], int year, float minimun_price, bool show); // Función que crea un padre
int* obtenerAnios(Padre *P); // Función que obtiene los años de un archivo
void archivoOrdenado(Padre *P, int *anios); // Función que ordena el archivo
int buscarAnio(int anio, int *anios); // Función que verifica si un año ya fue agregado
int obtenerAnio(char linea[], int largo); // Función que obtiene el año de una linea
int ordenarAnios(const void *a, const void *b); // Función que ordena los años
void escribirArchivo(char entrada[], int anio, float precio_min, FILE *archivo); // Función que escribe en un archivo
void printArchivo(char archivo[]); // Función que imprime en consola
float obtenerPrecio(char linea[], int largo); // Función que obtiene el precio de una linea
int *posicionesArchivo(Padre *P); // Función que obtiene las posiciones de los años en el archivo
void Ejecutar(Padre *P); // Función que calcula los datos de un archivo
void escribirAnios(Padre *P, int anio); // Función que escribe los años en un archivo