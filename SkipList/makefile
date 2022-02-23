ALL: main

main:	main.o SkipList.o 
		gcc main.o SkipList.o -o main

main.o: main.c SkipList.h 
		gcc -c main.c

SkipList.o: SkipList.c SkipList.h 
		gcc -c SkipList.c

clear: rm -f *.o main