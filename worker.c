#include "fworker.h"


int main(){
    LA *L = crearLA();
    char recibido[500];
    char mensaje[5000];
    int total = 0;
    while(1){
        read(STDIN_FILENO, recibido, 500);
        if(!strcmp(recibido, "FIN")){
            write(STDOUT_FILENO, convertirAstring(L), sizeof(convertirAstring(L)));
            //write(STDOUT_FILENO, &total, sizeof(int));
            close(STDOUT_FILENO);
            memset(mensaje, 0, sizeof(mensaje));
            return 0; 
        }
        else{
            agregarAnio(L, recibido, strlen(recibido));
            total++;
        }
    }
    return 0;
}


