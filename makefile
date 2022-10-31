
# Se debe limpiar con make clean y luego compilar con make lab1 antes de volver a ejecutar ./lab1
# O si no va a crashear.
lab2: lab2.c
	gcc -o lab2 lab2.c

clean:
	rm -f lab2 *.o *.txt main test_fworker test_fbroker broker worker

main: main.c
	gcc -o main main.c Padre.c Hijo.c

receptor: receptor.c
	gcc -o receptor receptor.c

Exec: Exec.c
	gcc -o Exec Exec.c

test_fworker: test_fworker.c
	gcc -o test_fworker test_fworker.c fworker.c

test_fbroker: test_fbroker.c
	gcc -o test_fbroker test_fbroker.c fbroker.c

broker: broker.c
	gcc -o broker broker.c fbroker.c

worker: worker.c
	gcc -o worker worker.c fworker.c

run:
	gcc -o lab2 lab2.c
	gcc -o broker broker.c fbroker.c
	gcc -o worker worker.c fworker.c
	./lab2 -i datos_juegos_3000.csv -o salida.txt -d 2010 -p 20.0 -n 5 -b


