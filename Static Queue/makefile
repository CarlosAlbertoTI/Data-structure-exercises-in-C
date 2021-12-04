ALL: main

main:	main.o StaticQueue.o 
		gcc main.o StaticQueue.o -o main

main.o: main.c StaticQueue.h 
		gcc -c main.c

ListDinEncCir.o: StaticQueue.c StaticQueue.h 
		gcc -c StaticQueue.c

clear: rm -f *.o main