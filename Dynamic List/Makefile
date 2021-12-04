ALL: main

main:	main.o ListDinEnc.o 
		gcc main.o ListDinEnc.o -o main

main.o: main.c ListDinEnc.h 
		gcc -c main.c

ListDinEnc.o: ListDinEnc.c ListDinEnc.h 
		gcc -c ListDinEnc.c

clear: rm -f *.o main
		
