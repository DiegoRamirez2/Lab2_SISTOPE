#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>
#include <getopt.h>
#define LECTURA 0
#define ESCRITURA 1

// Si se usa Dup2, no es necesario cerrar los descriptores de archivo, ya que se sobreescriben
// con los nuevos descriptores de archivo del standard de C, osea que se puede repartir información
// entre los procesos hijos y padres, sin necesidad de cerrar los descriptores de archivo,
// solo hacer uso de dup2 para repartir poco a poco
// ./lab2 -i datos_juegos_3000.csv -o salida.txt -d 2000 -p 0.56 -n 5 -b
int main(int argc, char *argv[]){
    int pid;
    int opt;
    bool i = false, o = false, d = false, p = false, n = false, b = false;
    while((opt = getopt(argc, argv, ":i:o:d:p:n:b::")) != -1){
        switch (opt){
            case 'i':
                i = true;
                break;
            case 'o':
                o = true;
                break;
            case 'd':
                d = true;
                break;
            case 'p':
                if(atof(optarg) >= 0.0){
                    p = true;
                }
                break;
            case 'b':
                b = true;
                break;
            case 'n':
                if(atoi(optarg) > 0){
                    n = true;
                }
                break;
            case '?':
                printf("unknown option: %c", optopt);
                return 1;
            case ':':
                printf("Missing arg for %c", optopt);
                return 1;
        }
    }
    if(i && o && d && p && n){
        if(b){
            argv[11] = "1";
        }
        else{
            argv[11] = "0";
        }
        char *args[] = {argv[2], argv[4], argv[6], argv[8], argv[10], argv[11], NULL};
            pid = fork();
            if(pid == 0){
                execvp("./broker", args);
            }else{
                wait(NULL);
            }
    }
    else{
        printf("Faltan argumentos válidos");
    }
    return 0;
}
    