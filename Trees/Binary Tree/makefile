ALL: main

main:	main.o BinaryTree.o 
		gcc main.o BinaryTree.o -o main

main.o: main.c BinaryTree.h 
		gcc -c main.c

BinaryTree.o: BinaryTree.c BinaryTree.h 
		gcc -c BinaryTree.c

clear: rm -f *.o main