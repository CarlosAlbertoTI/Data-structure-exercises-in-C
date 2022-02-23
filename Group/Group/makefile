ALL: main

main.c:	main.o Set.o  
		gcc main.o Set.o -o main

main.o: main.c Set.h 
		gcc -c main.c

Set.o: Set.c Set.h 
		gcc -c Set.c

clear: rm -f *.o main