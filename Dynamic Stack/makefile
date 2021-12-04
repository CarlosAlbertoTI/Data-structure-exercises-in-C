ALL: main

main:	main.o DynamicStack.o 
		gcc main.o DynamicStack.o -o main

main.o: main.c DynamicStack.h 
		gcc -c main.c

DynamicStack.o: DynamicStack.c DynamicStack.h 
		gcc -c DynamicStack.c

clear: rm -f *.o main