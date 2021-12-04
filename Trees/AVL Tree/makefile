ALL: main

main:	main.o arvoreAVL.o 
		gcc main.o arvoreAVL.o -o main

main.o: main.c arvoreAVL.h 
		gcc -c main.c

arvoreAVL.o: arvoreAVL.c arvoreAVL.h 
		gcc -c arvoreAVL.c

clear: rm -f *.o main