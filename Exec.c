#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "Padre.h"
#include <time.h>
#define LECTURA 0
#define ESCRITURA 1


// ./Exec -i datos_juegos_3000.csv -o salida.txt -d 2000 -p 0.56 -n 5 -b
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
                p = true;
                break;
            case 'b':
                b = true;
                break;
            case 'n':
                n = true;
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
            char *args[] = {argv[0], argv[1], argv[2], argv[3], argv[4], 
            argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], NULL};
            pid = fork();
            if(pid == 0){
                execvp("./main", args);
            }else{
                wait(NULL);
            }
        }
        else{
            char *args[] = {argv[0], argv[1], argv[2], argv[3], argv[4], 
            argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], NULL};
            pid = fork();
            if(pid == 0){
                execvp("./main", args);
            }else{
                wait(NULL);
            }
        }
    }
    return 0;
}