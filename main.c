#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "Padre.h"
#include <time.h>
#define LECTURA 0
#define ESCRITURA 1

// Si se usa Dup2, no es necesario cerrar los descriptores de archivo, ya que se sobreescriben
// con los nuevos descriptores de archivo del standard de C, osea que se puede repartir información
// entre los procesos hijos y padres, sin necesidad de cerrar los descriptores de archivo,
// solo hacer uso de dup2 para repartir poco a poco

int main(int argc, char *argv[]){
    /*
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
    */
    int fd[3][2];
    //srand(time(NULL));
    int pid, pid2;
    for(int i=0; i<3; i++){
        pipe(fd[i]);
    }
    // FUNCIONAAAAAAAAAA, se puede trabajar con N pipes, solo hay que cambiar el for
    // Hacer uso de esto para repartir las líneas de lectura, no debe ser tan dificl.
    for(int i=0; i<3; i++){
        pid = fork();
        if(pid == 0){
            pid2 = fork();
            if(pid2 > 0){
                dup2(fd[i][ESCRITURA], STDOUT_FILENO);
                close(fd[i][LECTURA]);
                write(STDOUT_FILENO, &i, sizeof(i));
                return 0;
            }else{
                close(fd[i][ESCRITURA]);
                dup2(fd[i][LECTURA], STDIN_FILENO);
                execl("./receptor", "./receptor", NULL);
            }
        }else{
            wait(NULL);
            printf("Soy el padre y mi pid es: %d\n", getpid());
        }
    }
    return 0;
}
    /*
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
    */
    