ALL: main

main:	main.o graphs.o 
		gcc main.o graphs.o -o main

main.o: main.c graphs.h 
		gcc -c main.c

graphs.o: graphs.c graphs.h 
		gcc -c graphs.c

clear: rm -f *.o main