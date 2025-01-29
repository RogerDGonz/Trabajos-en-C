
/*C Program to Print Level of a Given Node in Binary Tree


Write a C program to print level of a node in binary tree.
Recursive function in C to find level of a given node in binary tree.

Given a binary tree and a node N, we have to print the level of node N in binary tree. To print the level of a node N, first of all we have to search it in binary tree. Here, we can use In Order, pre Order or post Order traversal to search node N in binary tree. We will also keep track of level of current node while traversing.

Algorithm to find level of a given node in binary tree
Traverse given binary tree using pre order traversal by keeping track of levels of nodes.
Let node be the pointer to any node at level L.
If node is equal to NULL, return.
If node is equal to N, then print the level of node(L) on screen else continue traversal of sub trees at level L+1.
Time Complexity : O(n), we are traversing binary tree only once.
C program to print level of a given node of binary tree*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}Nodo;

Nodo* getNewNode(int data) {
  /* dynamically allocate memory for a new node */
  Nodo* newNode = (Nodo*)malloc(sizeof(Nodo));

  /* populate data in new Node */
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

/*
This function returns below tree
            1
           / \
         2    3
        / \  / \
       4  5 6  7
      / \       \
     8  9       10
*/
Nodo* generateBTree(){
    // Root Node
    Nodo* root =  getNewNode(1);

    root->left = getNewNode(2);
    root->right = getNewNode(3);

    root->left->left = getNewNode(4);
    root->left->right = getNewNode(5);
    root->right->left = getNewNode(6);
    root->right->right = getNewNode(7);

    root->left->left->left = getNewNode(8);
    root->left->left->right = getNewNode(9);

    root->right->right->right = getNewNode(10);

    return root;
}

/*
   Prints level of all nodes. It does pre Order
   traversal and keeps track of the current level and prints it.
*/
void printLevelOfNode(Nodo* root, int currentLevel, int num) {

    if(root == NULL) {
        return;
    }

 if(root->data == num) {
        printf("Level of %d is %d \n", num, currentLevel);
 }

    printLevelOfNode(root->left, currentLevel+1, num);
    printLevelOfNode(root->right, currentLevel+1, num);
}

int main() {
    Nodo *root = generateBTree();

    /*Printing level of nodes */
    printLevelOfNode(root, 0, 1);
    printLevelOfNode(root, 0, 5);
    printLevelOfNode(root, 0, 7);
    printLevelOfNode(root, 0, 9);

    getchar();
    return 0;
}
