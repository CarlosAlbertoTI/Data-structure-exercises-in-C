ALL: main

main:	main.o ArvoreLLRB.o 
		gcc main.o ArvoreLLRB.o -o main

main.o: main.c ArvoreLLRB.h 
		gcc -c main.c

ArvoreLLRB.o: ArvoreLLRB.c ArvoreLLRB.h 
		gcc -c ArvoreLLRB.c

clear: rm -f *.o main