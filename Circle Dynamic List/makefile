ALL: main

main:	main.o ListDinEncCir.o 
		gcc main.o ListDinEncCir.o -o main

main.o: main.c ListDinEncCir.h 
		gcc -c main.c

ListDinEncCir.o: ListDinEncCir.c ListDinEncCir.h 
		gcc -c ListDinEncCir.c

clear: rm -f *.o main
		
