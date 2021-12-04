ALL: main

main:	main.o ListaSequencia.o 
		gcc main.o ListaSequencia.o -o main

main.o: main.c ListaSequencia.h 
		gcc -c main.c

bolha.o: ListaSequencia.c ListaSequencia.h 
		gcc -c ListaSequencia.c

clear: rm -f *.o main
		
