ALL: main

main:	main.o ListaDinEncadDupla.o 
		gcc main.o ListaDinEncadDupla.o -o main

main.o: main.c ListaDinEncadDupla.h 
		gcc -c main.c

ListaDinEncadDupla.o: ListaDinEncadDupla.c ListaDinEncadDupla.h 
		gcc -c ListaDinEncadDupla.c

clear: rm -f *.o main
		
