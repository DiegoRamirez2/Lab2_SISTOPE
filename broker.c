#include "fbroker.h"

int main(int argc, char *argv[]){
    Broker *B = crearBroker(argv[0], argv[1], atoi(argv[2]), atof(argv[3]), atoi(argv[5]), atoi(argv[4]));
    FILE *archivo = fopen(argv[1], "a");
    fputs("Hola Mundo\n", archivo);
    //printf("La salida es: %s\n", B->salida);
    Ejecutar(B);
    fputs("Hola Mundo2\n", archivo);
    fclose(archivo);
    return 0;
}