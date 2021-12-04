ALL: main

main:	main.o sort.o 
		gcc main.o sort.o -o main

main.o: main.c sort.h 
		gcc -c main.c

sort.o: sort.c sort.h 
		gcc -c sort.c

clear: rm -f *.o main