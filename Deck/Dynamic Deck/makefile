ALL: main

main:	main.o DDeck.o 
		gcc main.o DDeck.o -o main

main.o: main.c DDeck.h 
		gcc -c main.c

DDeck.o: DDeck.c DDeck.h 
		gcc -c DDeck.c

clear: rm -f *.o main
		
