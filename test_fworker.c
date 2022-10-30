#include "fworker.h"

int main(){
    Anio *N = crearAnio("10,Counter-Strike,0,0.0,False,2000,False,Yes,No,No", strlen("10,Counter-Strike,0,5.5,False,2000,False,Yes,Yes,Yes"));
    LA *la = crearLA2(N);
    agregarAnio(la, "10,Holaaaaa,0,4.0,False,2001,False,Yes,Yes,No", strlen("10,Holaaaaa,0,20.0,False,2000,False,Yes,Yes,No"));
    agregarAnio(la, "10,XDDDD,0,67.0,False,2001,False,Yes,Yes,No", strlen("10,Holaaaaa,0,20.0,False,2000,False,Yes,Yes,No"));
    //compararAnio(N, "10,Holaaaaa,0,4.0,False,2000,False,Yes,Yes,No", strlen("10,Holaaaaa,0,20.0,False,2000,False,Yes,Yes,No"));
    //compararAnio(N, "10,XDDDDD,0,0.0,False,2000,False,Yes,Yes,Yes", strlen("10,Holaaaaa,0,20.0,False,2000,False,Yes,Yes,No"));
    ImprimirLista(la);
    /*
    while(N->freeGames != NULL){
        printf("El juego es: %s\n", N->freeGames->nameGame);
        N->freeGames = N->freeGames->next;
    }
    */
    return 0;

}