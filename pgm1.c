/*Module 2
Assignment no 2
1.singly linked list
*/

#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *next;
};


/*inserting the node at start.........*/
void insertFront(struct node** head_ref, int new_data)
{	
	/*craeting an new_node*/
	struct node *new_node=NULL;

	/*allocate the memory*/
	new_node=(struct node*)malloc(sizeof(struct node));

	/* insert the data*/
	new_node->data=new_data;

	/*make new_node next points to the head(*head_ref)*/
	new_node->next=(*head_ref);
	
	/*move head to pint to new_node*/
	(*head_ref)=new_node;	
}

/*insert the node after particular node..........*/
void insertAfter(struct node* prev_node, int new_data)
{
    	/*create an  new node */
    	struct node* new_node =(struct node*) malloc(sizeof(struct node));
    	/* insert the data  */
    	new_node->data=new_data;
 
    	/* Make next of new node as next of prev_node */
    	new_node->next = prev_node->next;
 
    	/*  move the next of prev_node as new_node */
    	prev_node->next = new_node;
}


/*insert node at the end............*/
void insertEnd(struct node** head_ref, int new_data)
{
    	/*create an new node */
   	 struct node* new_node = (struct node*) malloc(sizeof(struct node));
   	 struct node *last = *head_ref;
    	/* put in the data  */
    	new_node->data  = new_data;
 
    	/*This new node is going to be the last node, so make next of it as NULL*/
    	new_node->next = NULL;
 
   	 /* If the Linked List is empty, then make the new node as head */
    	if (*head_ref == NULL)
    	{
       		*head_ref = new_node;
       		return;
    	}
 
    	/*  traverse upto the last node */
    	while (last->next != NULL)
       		 last = last->next;
 
    	/*Change the next of last node as new_node*/
    	last->next = new_node;
   	 return;
}
/*print the element of node.........*/
void printList(struct node *node)
{
  	while (node != NULL)
  	{	
     		printf(" %d---> ", node->data);
     		node = node->next;
  	}

}

/*delete an element from front*/
int deleteFront(struct node** head_ref)
{
	struct node *next_node=NULL;
	int retval=-1;
	if(*head_ref==NULL)
	{
	printf("\n linked list empty..");	
	}
	next_node= (*head_ref)->next;
	retval=(*head_ref)->data;
	*head_ref= next_node;
	return retval;

}
/*delete node at specific position*/
void deleteAt(struct node **head_ref, int position)
{
   // If linked list is empty
   if (*head_ref == NULL)
      return;
 
   // Store head node
   struct node* temp = *head_ref;
 
    // If head needs to be removed
    if (position == 0)
    {
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }
 
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct node *next = temp->next->next;
 
    // Unlink the node from linked list
    free(temp->next);  // Free memory
 
    temp->next = next;  // Unlink the deleted node from list
}






void delete(struct node *head)
{
  struct node *temp =head;
  struct node *t;
  while(temp->next != NULL)
  {
    t=temp;
    temp=temp->next;
  }
  free(t->next);
  t->next=NULL; 
}  







int main()
{
	struct node* head = NULL;int position,/*item,*/new_data;
	int choice;
	while(1)
	{	printf("\n==============......This is singly linked list.....===\n");
		printf("\n1)Insert_At_Front\n2)Insert_After\n3)Insert_At_End\n.........\n4)printList\n.........\n5)Delete_front\n6)Delete_At\n7)Delete_last\n8)Exit\n");
		printf("\n enter the choice..");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\n enter the num which you want to 'insert at front'....");scanf("%d",&new_data);
				insertFront(&head,new_data);
				break;
			case 2:printf("\n enter the num which you want to 'insert at after'....");scanf("%d",&new_data);
				insertAfter(head->next,new_data);
				break;

			case 3:printf("\n enter the num which you want to 'insert at end'....");scanf("%d",&new_data);
				insertEnd(&head,new_data);
				break;
			case 4:
				printList(head);
				break;
			case 5:
				deleteFront(&head);
				break;
	
			case 6:
				printf("\n enter the position u want to delete..");scanf("%d",&position);				
				deleteAt(&head,position);
				break;
				
			case 7:
				delete(head);
				break;
			case 8:
				exit(0);
			default:
			printf("\n Invalid chioce...");	

		}//close of switch
	}


}
