#include "Hijo.h"


int main(){
    Hijo *H = crearHijo("datos_juegos_1000.csv", "salida.txt", 0, 10);
    char p[] = "58570,The Next BIG Thing,0,3333.74,False,2011,False,Yes,Yes,No";
    printf("P es: %s\n", p);
    char *name = nombreJuego(p, strlen(p));
    printf("El nombre es: %s\n", name);
    return 0;
}