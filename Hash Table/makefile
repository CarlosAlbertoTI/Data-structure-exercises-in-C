ALL: main

main:	main.o hash_table.o 
		gcc main.o hash_table.o -o main

main.o: main.c hash_table.h 
		gcc -c main.c

hash_table.o: hash_table.c hash_table.h 
		gcc -c hash_table.c

clear: rm -f *.o main