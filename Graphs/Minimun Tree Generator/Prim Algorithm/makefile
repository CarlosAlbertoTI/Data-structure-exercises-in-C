ALL: main

main:	main.o grafo.o 
		gcc main.o grafo.o -o main

main.o: main.c grafo.h 
		gcc -c main.c

grafo.o: grafo.c grafo.h 
		gcc -c grafo.c

clear: rm -f *.o main