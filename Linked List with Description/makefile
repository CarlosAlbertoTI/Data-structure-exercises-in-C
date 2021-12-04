ALL: main

main:	main.o ListDinEncadDesc.o 
		gcc main.o ListDinEncadDesc.o -o main

main.o: main.c ListDinEncadDesc.h 
		gcc -c main.c

ListDinEncadDesc.o: ListDinEncadDesc.c ListDinEncadDesc.h 
		gcc -c ListDinEncadDesc.c

clear: rm -f *.o main
		
