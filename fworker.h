#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>

/*
    * Esta estructura permitirá almacenar la lista de juegos gratis, y
    * se irá actualizando a medida que se vayan encontrando más juegos.
*/
typedef struct freeGames{
    char *nameGame; // Nombre del juego
    struct freeGames *next; // Puntero al siguiente juego
}FG;
/*
    * Esta estructura representará los datos con respecto a las líneas
    * leídas, permitirán almacenar el juego más caro, el más barato, 
    * el promedio de precios, el soporte por SO y la lista de juegos gratis,
    * para a medida de que va progresando, vaya actualizando los datos
*/
typedef struct anio{
    int anio;
    char *cheapGame; // Juego más barato
    char *expensiveGame; // Juego más caro
    float cheapPrice; // Precio más barato
    float expensivePrice; // Precio más caro
    float priceAcum; // Precio promedio
    float nWindows; // Número de juegos para Windows
    float nMacOs; // Número de juegos para MacOs
    float nLinux; // Número de juegos para Linux
    int nGames; // Número de juegos
    FG *freeGames; // Lista de juegos gratis
}Anio;

/*
    * Esta estructura permitirá almacenar la lista de años con
    * sus respectivos datos 
*/
typedef struct listaAnios{
    Anio *anio;
    struct listaAnios *next;
}LA;
// Funciones
Anio *crearAnio(char linea[], int largo); // Función que crea un año
FG *crearFG(); // Función que crea una lista de juegos gratis vacía
FG *crearFG2(char *nameGame); // Función que crea una lista de juegos gratis con un juego
void agregarFG(FG *freeGames, char *nameGame); // Función que agrega un juego a la lista de juegos gratis
int posicion(char linea[], int largo, int comas); // Función que cuenta las comas de una linea
bool Linux(char linea[], int largo); // Función que verifica si un juego es para Linux
bool Windows(char linea[], int largo); // Función que verifica si un juego es para Windows
bool MacOs(char linea[], int largo); // Función que verifica si un juego es para MacOs
int obtenerAnio(char linea[], int largo); // Función que obtiene el año de un juego
void compararAnio(Anio *A, char linea[], int largo); // Función que compara los datos de un año con los datos de un juego
float precioJuego(char linea[], int largo); // Función que obtiene el precio de un juego
char *nombreJuego(char linea[], int largo); // Función que obtiene el nombre de un juego
LA *crearLA(); // Función que crea una lista de años vacía
LA *crearLA2(Anio *A); // Función que crea una lista de años con un año
void agregarAnio(LA *listaAnios, char linea[], int largo); // Función que agrega un año a la lista de años
void ImprimirLista(LA *listaAnios); // Función que imprime la lista de años
void ImprimirGratis(Anio *A); // Función que imprime la lista de juegos gratis
char *convertirAstring(LA *L); // Función que convierte la lista de años a un string