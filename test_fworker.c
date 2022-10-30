#include "fworker.h"
#define LECTURA 0
#define ESCRITURA 1

int main(){
    char uno[] = "10,Counter-Strike,0,0.0,False,2004,False,Yes,No,No";
    char dos[] = "20,Team Fortress Classic,0,3.0,False,2004,False,Yes,Yes,Yes";
    char tres[] = "30,Day of Defeat,0,72.0,False,2004,False,Yes,Yes,Yes";
    Anio *N = crearAnio(uno, strlen(uno)); 
    LA *la = crearLA2(N);
    agregarAnio(la, dos, strlen(dos));
    agregarAnio(la, tres, strlen(tres));
    char datos[1000];
    ImprimirLista(la);
    strcpy(datos, convertirAstring(la));
    printf("%s", datos);
    printf("\n");
    //LA *la2 = convertirAlista(datos);
    //ImprimirLista(la2);
    //compararAnio(N, "10,Holaaaaa,0,4.0,False,2000,False,Yes,Yes,No", strlen("10,Holaaaaa,0,20.0,False,2000,False,Yes,Yes,No"));
    //compararAnio(N, "10,XDDDDD,0,0.0,False,2000,False,Yes,Yes,Yes", strlen("10,Holaaaaa,0,20.0,False,2000,False,Yes,Yes,No"));
    //ImprimirLista(la);
    /*
    int pid;
    int fd[2], fd2[2];
    pipe(fd);
    pipe(fd2);
    pid = fork();
    if(pid > 0){
        close(fd[LECTURA]);
        write(fd[ESCRITURA], la, sizeof(LA));
        close(fd[ESCRITURA]);
        wait(NULL);
        close(fd2[ESCRITURA]);
        LA *l2 = (LA*)malloc(sizeof(LA));
        char mensaje[1000];
        read(fd2[LECTURA], mensaje, sizeof(mensaje));
        //read(fd2[LECTURA], mensaje, sizeof(mensaje));
        printf("Soy el padre, y me llegó esto: %s\n", mensaje);
        //ImprimirLista(l2);
    }
    // La idea es crear un encriptador y un desencriptador de LA.
    else{
        char mensaje[1000];
        close(fd[ESCRITURA]);
        LA *la2 = crearLA();
        read(fd[LECTURA], la2, sizeof(LA));
        close(fd[LECTURA]);
        printf("Soy el hijo, este es mi mensaje recibido: \n\n");
        ImprimirLista(la2);
        close(fd2[LECTURA]);
        agregarAnio(la2, "10,Holi,0,0.0,False,2000,False,Yes,Yes,No", strlen("10,Holi,0,0.0,False,2003,False,Yes,Yes,No"));
        printf("Con el anio agregado: \n");
        ImprimirLista(la2);
        strcpy(mensaje, convertirAstring(la2));
        printf("El mensaje es: %s\n", mensaje);
        write(fd2[ESCRITURA], mensaje, sizeof(mensaje));
        close(fd2[ESCRITURA]);
        //write(fd2[ESCRITURA], "Hola, soy el hijo", sizeof("Hola, soy el hijo"));
    }
    */
    return 0;

}