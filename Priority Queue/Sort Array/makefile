ALL: main

main:	main.o priorityQueue.o 
		gcc main.o priorityQueue.o -o main

main.o: main.c priorityQueue.h 
		gcc -c main.c

priorityQueue.o: priorityQueue.c priorityQueue.h 
		gcc -c priorityQueue.c

clear: rm -f *.o main