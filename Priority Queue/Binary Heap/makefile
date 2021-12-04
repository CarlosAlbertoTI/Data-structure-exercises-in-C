ALL: main

main:	main.o binaryHeap.o 
		gcc main.o binaryHeap.o -o main

main.o: main.c binaryHeap.h 
		gcc -c main.c

binaryHeap.o: binaryHeap.c binaryHeap.h 
		gcc -c binaryHeap.c

clear: rm -f *.o main