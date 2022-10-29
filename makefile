
# Se debe limpiar con make clean y luego compilar con make lab1 antes de volver a ejecutar ./lab1
# O si no va a crashear.
lab1: lab1.c
	gcc -o lab1 lab1.c Padre.c Hijo.c

clean:
	rm -f lab1 *.o *.txt main

main: main.c
	gcc -o main main.c

receptor: receptor.c
	gcc -o receptor receptor.c
