ALL: main

main:	main.o StaticStack.o 
		gcc main.o StaticStack.o -o main

main.o: main.c StaticStack.h 
		gcc -c main.c

StaticStack.o: StaticStack.c StaticStack.h 
		gcc -c StaticStack.c

clear: rm -f *.o main