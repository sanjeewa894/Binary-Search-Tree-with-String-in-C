#include "btree.h"

int main()
{
	node *p_root, *new_node;
	char val[100];
	int choice,ans;
	p_root = NULL; //itialize the root
	
	/* loop untill exit by user */	
	while(1) {
		menu();
		scanf("%d", &choice);  //get the user choice
		
		switch (choice) {
			case 1: //enter values to tree
				do {
					printf("\nEnter The Element ");
				   scanf("%s", val);
				   new_node = get_node(); //create new node
					new_node->value = (char *) malloc(sizeof( strlen(val)+1));  //allocate memory for value
					strcpy(new_node->value, val); //copy the value into node
						
					insert(new_node, &p_root);//insert data
					
				   printf("\nWant To enter More Elements?('y->1'/'n->0')");
				   scanf("%d", &ans); 
				} while (ans);
				break;
		 
			case 2:
				printf("\nEnter Element to be searched :");
				scanf("%s", val);
				if( p_root == NULL ) {
					printf("Please create a tree before search !!!\n");
					break;
					}
				search(val, p_root);  //search value 
				break;
		 
			case 3:
				if( p_root == NULL ) {
					printf("Please create a tree before print !!!\n");
					break;
				}
				in_order(p_root);		//print values inorder		   
				break;
			case 4:
				if( p_root == NULL ) {
					printf("Please create a tree before print !!!\n");
					break;
				}
				preorder(p_root);  //print values  in preorder
				break;
			case 5:
				if( p_root == NULL ) {
					printf("Please create a tree before print !!!\n");
					break;
				}
				postorder(p_root);	//print values  in postorder
				break;
			case 6: //print the two states of tree
				printf("The depth and the number of nodes in the tree - %d , %d\n",showStates(p_root),countNodes(p_root));
				break;
			case 7:
				if( p_root == NULL ) {
					printf("Please create a tree before destroy !!!\n");
					break;
				}
				deleteTree(p_root); //delete the tree
				p_root = NULL;
				break;
			case 8:
				if( p_root == NULL ) {
					printf("Please create a tree before destroy  !!!\n");
					break;
				}
				deleteTree(p_root); //delete the tree
				p_root = NULL;
				break;
			}
			/*.. exit from the tree ....*/
		if(choice == 9 || choice == 8){
			printf("Now Exit ...\n");
			break; 
		}
			   
	}
    
return 0;

}
