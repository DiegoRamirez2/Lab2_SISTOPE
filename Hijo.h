#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

/* Realizando pruebas aaaaa
    * Esta estructura representará al proceso hijo
    * Va a almacenar el archivo intermedio, y el de salida
    * también las posiciones desde leerá y hasta donde leerá
    * además almacenará el precio más caro, el más barato y el promedio
    * de los precios de los juegos de ese año también almacerá el 
    * porcentaje de juegos que hay por sistema operativo
    * y por último almacenará los juegos gratis que hay
 */
typedef struct hijo{
    char entrada[100];   
    char salida[100];     
    int inicio;           
    int final;            
    float priceExpensive;      
    float priceCheap;
    char *nameExpensive;
    char *nameCheap;       
    float average;                      
    float nWindows;         
    float nMacOs;           
    float nLinuxs;          
}Hijo;

// Funciones
Hijo *crearHijo(char *entrada, char *salida, int inicio, int final); // Función que crea un hijo
int posicion(char linea[], int largo, int comas); // Función que cuenta las comas de una linea
bool Linux(char linea[], int largo); // Función que verifica si un juego es para Linux
bool Windows(char linea[], int largo); // Función que verifica si un juego es para Windows
bool MacOs(char linea[], int largo); // Función que verifica si un juego es para MacOs
void nombreJprecio(Hijo *H); // Función que obtiene el nombre con un precio dado
char *nombreJuego(char linea[], int largo); // Función que entrega el nombre de un juego
float precioJuego(char linea[], int largo); // Función que entrega el precio de un juego
void calcularDatosAnio(Hijo *H); // Función que calcula los datos de un archivo
void imprimirDatos(Hijo *H); // Función que imprime los datos de un archivo
void imprimirFree(Hijo *H); // Función que imprime los juegos gratis de un archivo
bool isFree(char linea[], int largo); // Función que verifica si un juego es gratis
