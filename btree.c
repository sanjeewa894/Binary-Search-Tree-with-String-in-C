#include "btree.h"

/*
 Get new Node
 */
node *get_node() {
   node *temp;
   temp = (node *) malloc(sizeof(node)); //alocate memory for the node
   temp->p_left = NULL; //create left branch null
   temp->p_right = NULL;//create right branch null
   return temp;
}


//inserts elements into the tree
void insert(node* new_node, node** leaf)
{
	int res;   
	if ((*leaf) == NULL){
		(*leaf) = new_node; //initial tree creation
	}else{
		res = strcmp (new_node->value, (*leaf)->value);
		if(res > 0){
			insert( new_node, &(*leaf)->p_left); //less value stand in left side of tree
		}else{
			insert( new_node, &(*leaf)->p_right);//higher value stand in right side of tree
		}
	}
}

//recursive function to print out the tree inorder
void in_order(node *root)
{
    if( root != NULL ) {
        in_order(root->p_left);//go to left side
        printf("   %s\n", root->value);     //print the value
        in_order(root->p_right);//go to right side 
    }
}
/*
 This function displays the tree in preorder fashion
 */
void preorder(node *temp) {
   if (temp != NULL) {
      printf("	%s\n", temp->value);//print the value
      preorder(temp->p_left); //go to left side
      preorder(temp->p_right); //go to right side 
   }
}
 
/*
 This function displays the tree in postorder fashion
 */
void postorder(node *temp) {
   if (temp != NULL) {
      postorder(temp->p_left); //go to left side
      postorder(temp->p_right); //go to right side 
      printf("	%s\n", temp->value); //print the value
   }
}

//searches elements in the tree
void search(char* key, node* leaf){
    int res;
    if( leaf != NULL ) {
        res = strcmp(key, leaf->value); //compare string.if equal return 0..
        if( res > 0)
            search( key, leaf->p_left); //go left side
        else if( res < 0)
            search( key, leaf->p_right); //go right side
        else
            printf("\nThe Search Key ('%s') is found!!\n", key);  //found the key in tree
    }
    else 
    	printf("\nThe Search Key is not in tree\n"); //no found
    	
    return;
}

//Show two stats of tree
int showStates(node *leaf){
	if( leaf == NULL ){
		return 0;
	}else{
		
		/* compute the depth of each subtree left and right */
       int lDepth = showStates(leaf->p_left);
       int rDepth = showStates(leaf->p_right);
 
       /* use the larger one as maximum depth
       */
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
		
	}
	 

}
/*
 * counting the number of nodes in a tree
 */
int countNodes(node *leaf)
{
    int c = 1;
    if (leaf == NULL)
        return 0; //no elements in tree
    else
    {
        c += countNodes(leaf->p_left); //count left side nodes into c
        c += countNodes(leaf->p_right);//count right side nodes into c
        return c;
     }
}
/*  This function traverses tree in post order to 
    to delete each and every node of the tree */
void deleteTree(node* leaf) 
{
    if (leaf == NULL) return;
 
    /* first delete both subtrees */
    deleteTree(leaf->p_left);
    deleteTree(leaf->p_right);
   
    /* then delete the node */
    printf("\n Deleting node: %s\n", leaf-> value);
    free(leaf);
} 

//displays menu for user to select
void menu()
{
	printf("\n1.Add Items");
	printf("\n2.Search");
   printf("\n3.Recursive Traversals in order");
  	printf("\n4.Recursive Traversals preorder");
	printf("\n5.Recursive Traversals postorder");
	printf("\n6.show two states");
	printf("\n7.Destroy the tree");
	printf("\n8.Destroy the tree and Exit");
	printf("\n9.Exit");
	printf("\nEnter your choice :");
}

