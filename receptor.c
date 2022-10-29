#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "Padre.h"
#define LECTURA 0
#define ESCRITURA 1

int main(){
    int turno;
    read(STDIN_FILENO, &turno, sizeof(turno));
    printf("Mi turno es: %d y mi Pid: %d\n", turno, getpid());
    close(STDIN_FILENO);
    while(true);
    return 0;
}