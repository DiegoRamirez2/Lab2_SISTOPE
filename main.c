#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "Padre.h"
#define LECTURA 0
#define ESCRITURA 1

// Si se usa Dup2, no es necesario cerrar los descriptores de archivo, ya que se sobreescriben
// con los nuevos descriptores de archivo del standard de C, osea que se puede repartir información
// entre los procesos hijos y padres, sin necesidad de cerrar los descriptores de archivo,
// solo hacer uso de dup2 para repartir poco a poco

int main(){
    /*
    int fd[3][2];
    for(int i = 0; i < 3; i++){
        if(pipe(fd[i]) == -1){
            perror("Error al crear el pipe");
            exit(-1);
        }
    }
    int fd[2];
    int status;
    pipe(fd);
    int pid = fork();
    if(pid == 0){
        char mensaje[100];
        Padre *P = crearPadre()
        printf("Ingrese un mensaje para el padre: ");
        fgets(mensaje, 100, stdin);
        dup2(fd[ESCRITURA], STDOUT_FILENO);
        write(STDOUT_FILENO, mensaje, sizeof(mensaje));
        close(fd[ESCRITURA]);
    }
    else{
        dup2(fd[LECTURA], STDIN_FILENO);
        wait(&status);
        char buffer[100];
        read(STDIN_FILENO, buffer, 100);
        printf("%s", buffer);
    }
    */
    return 0;
}