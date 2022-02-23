ALL: main

main:	main.o generic.o 
		gcc main.o generic.o -o main

main.o: main.c generic.h 
		gcc -c main.c

generic.o: generic.c generic.h 
		gcc -c generic.c

clear: rm -f *.o main