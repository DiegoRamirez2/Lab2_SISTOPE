#include "Padre.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <getopt.h>
#include <time.h>
#define LECTURA 0
#define ESCRITURA 1

// Se pueden pasar Estructuras a través de los pipes.
// Para pruebas:
// ./lab1 -i datos_juegos_3000.csv -o salida.txt -d 2000 -p 0.56 -b
int main(int argc, char *argv[]){
    int opt, anio = 1900;
    float precio_minimo;
    char entrada[100], salida[100];
    bool mostrar = false;
    while((opt = getopt(argc, argv, ":i:o:d:p:b::")) != -1){
        switch (opt){
            case 'i':
                strcpy(entrada, optarg);
                break;
            case 'o':
                strcpy(salida, optarg);
                break;
            case 'd':
                anio = atoi(optarg);
                break;
            case 'p':
                precio_minimo = atof(optarg);
                break;
            case 'b':
                mostrar = true;
                break;
            case '?':
                printf("unknown option: %c", optopt);
                return 1;
            case ':':
                printf("Missing arg for %c", optopt);
                return 1;
        }
    }
    /**/
    int pipe[3][2];
    srand(time(NULL));
    int pid;
    printf("\n");
    for(int i=0; i < 3; i++){
        pid = fork();
        if(pid > 0){
            int numero = rand() % 3;
            printf("El número es: %d\n", i);
            dup2(pipe[i][ESCRITURA], STDOUT_FILENO);
            close(pipe[i][LECTURA]);
            write(STDOUT_FILENO, &i, sizeof(i));
        }
        else{
            printf("En el hijo, el i es: %d\n", i);
            int turno;
            close(pipe[i][ESCRITURA]);
            //dup2(pipe[i][LECTURA], STDOUT_FILENO);
            read(pipe[i][LECTURA], &turno, sizeof(turno));
            printf("Mi turno es: %d y mi Pid: %d\n", turno, getpid());
            return 0;
        }
    }
    
    /*
    Padre *P = crearPadre(entrada, salida, anio, precio_minimo, mostrar);
    remove(P->salida);
    remove("intermedio.txt");
    Ejecutar(P);
    
    // Copilot, if i put a print, you put a new line in the end, thanks
    int fd[2];
    int status;
    pipe(fd);
    int pid = fork();
    if(pid == 0){
        char mensaje[100];
        Padre *P = crearPadre(entrada, salida, anio, precio_minimo, mostrar);
        //printf("Ingrese un mensaje para el padre: ");
        //fgets(mensaje, 100, stdin);
        dup2(fd[ESCRITURA], STDOUT_FILENO);
        write(STDOUT_FILENO, P, sizeof(Padre));
        close(fd[ESCRITURA]);
    }else{
        dup2(fd[LECTURA], STDIN_FILENO);
        wait(&status);
        Padre *P2 = malloc(sizeof(Padre));
        read(STDIN_FILENO, P2, sizeof(Padre));
        printf("%s\n", P2->entrada);
        printf("%s\n", P2->salida);
        printf("%d\n", P2->anio);
        printf("%f\n", P2->precio_minimo);
        printf("%d\n", P2->mostrar);
        
    }
    */
    return 0;
}