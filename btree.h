
/*

** Author: My Name 
** CPSC 121 Lab 10
** <12/11/2017> (Current Date)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct for node
typedef struct BST {
    char* value;   
    struct BST *p_left;
    struct BST *p_right;
}node;


//inserts elements into the tree
void insert(node*, node** );

//recursive function to print out the tree inorder
void in_order(node *);

//searches elements in the tree
void search(char* , node* );

//displays menu for user
void menu();
/*
 Get new Node
 */
node *get_node();

/*
 This function displays the tree in preorder fashion
 */
void preorder(node *);

/*
 This function displays the tree in postorder fashion
 */
void postorder(node *); 

/*
 * counting the number of nodes in a tree
 */
int countNodes(node *leaf);

/*  This function traverses tree in post order to 
    to delete each and every node of the tree */
void deleteTree(node* leaf);

//Show two stats of tree
int showStates(node *leaf);
