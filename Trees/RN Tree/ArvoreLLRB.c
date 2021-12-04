#include <stdio.h>
#include <stdlib.h>
#include "ArvoreLLRB.h"

const int RED = 1;
const int BLACK = 0;

ArvoreLLRB* createTree(){
    ArvoreLLRB* newTree = (ArvoreLLRB*) malloc(sizeof(ArvoreLLRB));
    if(newTree != NULL){
        (*newTree) = NULL;
    }
    return newTree;
}

void freeNode(struct No* node)
{
    if (node == NULL)
        return;
    freeNode((*node).left);
    freeNode((*node).right);
    free(node);
    node = NULL;
}

void freeTree(ArvoreLLRB* root)
{   
    printf("%i", root == NULL);
    if (root == NULL)
        return;
    freeNode((*root));
    free(root);
}

void preOrderTree(ArvoreLLRB* root)
{
    if ((*root) == NULL)
        return;
    printf("%d\n", (*root)->info);
    preOrderTree(&((*root)->left));
    preOrderTree(&((*root)->right));
}

int Color(struct No* node)
{
    if (node == NULL)
    {
        return BLACK;
    }
    else
    {
        return node->color;
    }
}

void changeColor(struct No* node)
{
    node->color = !node->color;
    if (node->left != NULL)
    {
        node->left->color = !node->left->color;
    }
    if (node->right != NULL)
    {
        node->right->color = !node->right->color;
    }
}

struct No* rotateLeft(struct No* node)
{
    struct No *B = node->right;
    node->right = B->left;
    B->left = node;
    node->color = B->color;
    node->color = RED;
    return B;
}

struct No* rotateRight(struct No* node)
{
    struct No *B = node->left;
    node->left = B->right;
    B->right = node;
    node->color = B->color;
    node->color = RED;
    return B;
}

struct No* moveLeftRed(struct No* node)
{
    changeColor(node);
    if (Color(node->right->left) == RED)
    {
        node->right = rotateRight(node->right);
        node = rotateLeft(node);
        changeColor(node);
    }
    return node;
}

struct No* moveRightRed(struct No* node)
{
    changeColor(node);
    if (Color(node->left->left) == RED)
    {
        node = rotateRight(node);
        changeColor(node);
    }
    return node;
}

struct No* balance(struct No* node)
{
    if (Color(node->right) == RED)
    {
        node = rotateLeft(node);
    }

    if ((node->left != NULL) && (Color(node->right) != RED) && (Color(node->left->left) != RED))
    {
        node = rotateRight(node);
    }

    if ((Color(node->left) == RED) && (Color(node->right) == RED))
    {
        changeColor(node);
    }
    return node;
}

struct No* insertNode(struct No* node, int value, int *resp){
    if(node == NULL){
        struct No *newNode;
        newNode = (struct No*)malloc(sizeof(struct No));
        if(newNode == NULL){
            *resp = 0;
            return NULL;
        }

        newNode->info = value;
        newNode->color = RED;
        newNode->right = NULL;
        newNode->left = NULL;
        *resp = 1;
        return newNode;
    }

    if(value == node->info)
        *resp = 0;
    else{
        if(value < node->info)
            node->left = insertNode(node->left,value,resp);
        else
            node->right = insertNode(node->right,value,resp);
    }

    if(Color(node->right) == RED && Color(node->left) == BLACK)
        node = rotateLeft(node);
    
    if(Color(node->left) == RED && Color(node->left->left) == RED)
        node = rotateRight(node);

    
    if(Color(node->left) == RED && Color(node->right) == RED)
        changeColor(node);

    return node;
}

int insertTree(ArvoreLLRB* root, int value){
    int resp;

    *root = insertNode(*root,value,&resp);
    if(*root != NULL)
        (*root)->color = BLACK;

    return resp;
}


int searchTree(ArvoreLLRB* root, int value){
    if(root == NULL) return 0;
    struct No* atual = (*root);
    while(atual != NULL){
        if(value == atual->info){
            printf("valor: %i\n", atual->info);
            return 1;
        }
        if(value > atual->info){
            atual = atual->right;
        }else{
            atual = atual->left;
        }
    }
    return 0;
}

// struct No* removeSmallNode(struct No* node){
//     if(node->left == NULL){
//         free(node);
//         return NULL;
//     }
//     if(Color(node->left) == BLACK && Color(node->left->left) == BLACK)
//         node = moveLeftRed(node);

//     node = removeSmallNode(node->left);
//     return balance(node);
// }


// struct No* searchSmallNode(struct No* node){
//     struct No* current = node;
//     struct No* next = node->left;

//     while(next != NULL){
//         current = next;
//         next = next->left;
//     }

//     return current;
// }

// struct No* removeNode(struct No* node, int value){
//     if(node->info > value){
//         if(Color(node->left) == BLACK && Color(node->left->left) == BLACK)
//             node = moveLeftRed(node);
//         node->left = removeNode(node->left, value);
//     }else{
//         if(Color(node->left) == RED)
//             node = rotateRight(node);
        
//         if(value == node->info && (node->right == NULL)){
//             free(node);
//             return NULL;
//         }

//         if(Color(node->right) == BLACK && Color(node->right->left) == BLACK)
//             node = moveRightRed(node);

//         if(value == node->info){
//             struct No* aux = searchSmallNode(node->right);
//             node->info = aux->info;
//             node->right = removeSmallNode(node->right);
//         }else{
//             node->right = removeNode(node->right, value);
//         }
//         return balance(node);
//     }
// }


// int removeTree(ArvoreLLRB *root, int value){
//     if(searchTree(root, value) == 1){
//         struct No* node = root;
//         root = removeNode(node, value);
//         if(root != NULL){
//             root->color = BLACK;
//         }
//         return 1;
//     }else{
//         return 0;
//     }
// }