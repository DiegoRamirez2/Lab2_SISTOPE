#include "fbroker.h"
#define LECTURA 0
#define ESCRITURA 1

// 2004,Holaaaa,XDDD,45.67,0.5,0,1,1,1,0,

// 2000,NONE,NONE,1000,0,0,1,1,0,0,Counter-Strike¿2004,NONE,NONE,1000,0,0,1,1,1,0,Holaaaaa¿2003,XDDDD,XDDDD,4.257,4.257,4.257,1,1,1,0,¿
int main(){
    char mensaje2[256] = "2004,Day of Defeat,Team Fortress Classic,72,3,75,3,2,3,2,2,Counter-Strike,Counter-Strike2,Counter-Strike3";
    char mensaje3[256] = "2005,Day of Defeat,Team Fortress Classic,72,3,75,3,2,3,2,2,Counter-Strike6";
    char mensaje4[256] = "2006,Day of Defeat,Team Fortress Classic,72,3,75,3,2,3,2,2,Counter-Strike5";
    char mensaje5[256] = "2005,NONE,NONE,0,1000,0,1,0,1,1,1,Team Fortress Classic";
    char mensaje6[1000] = "2005,NONE,NONE,0,1000,0,1,0,1,1,1,HolaMundo¿2004,Counter-Strike,Counter-Strike4,4,4,4,1,1,1,0,0,¿2006,Day of Defeat,Day of Defeat,72,72,72,1,1,1,1,1,¿";
    //printf("El mensaje es: %s\n", mensaje6);
    ListY *L = crearListY();
    agregarListYear(L, mensaje6);
    /*
    agregarYear(L, crearYear(mensaje5));
    agregarYear(L, crearYear(mensaje2));
    agregarYear(L, crearYear(mensaje3));
    agregarYear(L, crearYear(mensaje4));
    */
    ListY *aux = L;
    while(aux != NULL){
        ImprimirYear(aux->year);
        aux = aux->next;
    }
    return 0;
}