#include "fbroker.h"
#define LECTURA 0
#define ESCRITURA 1

// 2004,Holaaaa,XDDD,45.67,0.5,0,1,1,1,0,

// 2000,NONE,NONE,1000,0,0,1,1,0,0,Counter-Strike¿2004,NONE,NONE,1000,0,0,1,1,1,0,Holaaaaa¿2003,XDDDD,XDDDD,4.257,4.257,4.257,1,1,1,0,¿
int main(){
    printf("Hola Mundo\n");
    char mensaje[256] = "2000,NONE,NONE,1000,0,0,1,1,0,0,Counter-Strike";
    char mensaje2[256] = "2004,Holaaaa,XDDD,45.67,0.5,0,1,1,1,0,";
    Year *Y = crearYear(mensaje2);
    printf("El año es: %d\n", Y->year);
    printf("El juego más caro es: %s\n", Y->nameExpensive);
    printf("El precio del juego más caro es: %f\n", Y->priceExpensive);
    printf("El juego más barato es: %s\n", Y->nameCheap);
    printf("El precio del juego más barato es: %f\n", Y->priceCheap);
    printf("El precio acumulado es: %f\n", Y->priceAcum);
    printf("La cantidas de juegos es: %d\n", Y->nGames);
    printf("Los juegos de Windows son: %f\n", Y->nWindows);
    printf("Los juegos de MacOs son: %f\n", Y->nMacOs);
    printf("Los juegos de Linux son: %f\n", Y->nLinux);
    
    return 0;
}