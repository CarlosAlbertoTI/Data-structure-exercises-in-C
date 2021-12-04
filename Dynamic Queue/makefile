ALL: main

main:	main.o DynaQueue.o 
		gcc main.o DynaQueue.o -o main

main.o: main.c DynaQueue.h 
		gcc -c main.c

ListDinEncCir.o: DynaQueue.c DynaQueue.h 
		gcc -c DynaQueue.c

clear: rm -f *.o main