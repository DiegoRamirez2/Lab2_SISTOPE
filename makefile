
# Se debe limpiar con make clean y luego compilar con make lab1 antes de volver a ejecutar ./lab1
# O si no va a crashear.
lab1: lab1.c
	gcc -o lab1 lab1.c Padre.c Hijo.c

clean:
	rm -f lab1 *.o *.txt main test_fworker

main: main.c
	gcc -o main main.c Padre.c Hijo.c

receptor: receptor.c
	gcc -o receptor receptor.c

Exec: Exec.c
	gcc -o Exec Exec.c

test_fworker: test_fworker.c
	gcc -o test_fworker test_fworker.c fworker.c

