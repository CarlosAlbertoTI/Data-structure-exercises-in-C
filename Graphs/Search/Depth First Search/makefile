ALL: main

main:	main.o graph.o 
		gcc main.o graph.o -o main

main.o: main.c graph.h 
		gcc -c main.c

graph.o: graph.c graph.h 
		gcc -c graph.c

clear: rm -f *.o main