ALL: main

main:	main.o deck.o 
		gcc main.o deck.o -o main

main.o: main.c deck.h 
		gcc -c main.c

deck.o: deck.c deck.h 
		gcc -c deck.c

clear: rm -f *.o main
		
