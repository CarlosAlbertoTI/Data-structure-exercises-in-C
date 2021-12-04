#include <stdio.h>
#include <stdlib.h>
#include "ArvoreLLRB.h"

int main(int argc, char const *argv[])
{



    ArvoreLLRB* root = createTree();
    int valueOne = 7;
    int valueTwo = 6;
    int valueThree = 8;
    int valueFour = 5;
    // int valueFive = 0;
    

    int insertOne = insertTree(root, valueOne);
    printf("insert One: %i\n",  insertOne);

    int insertTwo = insertTree(root, valueTwo);
    printf("insert Two: %i\n",  insertTwo);

    int insertThree = insertTree(root, valueThree);
    printf("insert Three: %i\n",  insertThree);
    
    int insertFour = insertTree(root, valueFour);
    printf("insert Four: %i\n",  insertFour);
   
   printf("\n");
    // int insertFive = insertTree(root, valueFive);
    // printf("insert Five: %i\n",  insertFive);


    // if(((*root)->left)->color == RED){
        printf("root cor: %i\n",(*root)->color);
        
        
        printf("right cor: %i\n",((*root)->right)->color);
        printf("right value: %i\n",((*root)->right)->info);
        
        printf("left color: %i\n",(*root)->left->color);
        printf("left info: %i\n",(*root)->left->info);
        
        printf("left left color: %i\n",(((*root)->left)->left)->color);
        printf("left left info: %i\n",(((*root)->left)->left)->info);
        
        // printf("color: %i\n", (((*root)->left)->right)->info);
        // printf("color: %i\n", (((*root)->left)->left)->info);
    // }
    // int insertFive = insertTree(root, valueFive);
    // printf("%i",  insertFive);

    // preOrderTree(root);

    // int searchOne = searchTree(root, valueOne);
    // printf("search One: %i\n",  searchOne);

    // int removeOne = removeTree(root, valueFour);
    // printf("%i",  removeOne);

    freeTree(root);
    return 1;
}
