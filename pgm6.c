/*module 2
Assignment no 2
6. Study Linked list its usage its advantages and disadvantages and implement following:

Write a program to create a doubly linked list. The code should have following functions.
a. Add node at begning
b. Add node at end
c. Add a node at a given position
d. Delete a node at end
e. Delete a node at begining
f. Deleate a node at given position.*/

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node* next;
	struct node* prev;
};

void insertFront(struct node** head_ref,int new_data)
{
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	
	new_node->data=new_data;
	new_node->next=(*head_ref);
	new_node->prev=NULL;
	(*head_ref)=new_node;

}
void insertAfter(struct node* prev_node, int new_data)
{
    	struct node* new_node = (struct node*)malloc(sizeof(struct node));
    	new_node->data = new_data;
 
   	/*1 Make next of new node as next of prev_node */
    	new_node->next = prev_node->next;
 
    	/* 2 Make the next of prev_node as new_node */
   	 prev_node->next = new_node;
 
    	/* 3 Make prev_node as previous of new_node */
    	new_node->prev = prev_node;
 
    	/* 4 Change previous of new_node's next node */
    	if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void insertEnd(struct node** head_ref, int new_data)
{
    	struct node* new_node = (struct node*)malloc(sizeof(struct node));
 	struct node* last = *head_ref;
	new_node->data = new_data;
    	new_node->next = NULL;
 
    	/*If the Linked List is empty, then make the new
         node as head */
    	if (*head_ref == NULL) 
	{
       		 new_node->prev = NULL;
       		 *head_ref = new_node;
        		return;
    	}
 
    /*Else traverse till the last node */
    	while (last->next != NULL)
        last = last->next;
 
    /* Change the next of last node */
    	last->next = new_node;
 
    /*Make last node as previous of new node */
    	new_node->prev = last;
	return;
}

void deleteFront(struct node ** head_ref)
{
   if(*head_ref == NULL)
      printf("List is Empty!!! Deletion not possible!!!");
   else
   {
      struct node *temp = *head_ref;
      if(temp -> prev== temp -> next)
      {
         *head_ref = NULL;
         free(temp);
      }
      else{
         *head_ref = temp -> next;
        ( *head_ref) -> prev = NULL;
         free(temp);
      }
      
   }
}

void deleteAt(struct node**head_ref,int x)  
{  
    struct node* temp1=*head_ref;  
    if(*head_ref==NULL)  
    {  
        printf("No records to delete");       
    }  
else if(temp1->data==x)  
    {  
        *head_ref=temp1->next;  
        free(temp1);  
    }  
    else  
    {  
        struct node* temp2=NULL;  
        temp2=temp1->next;  
        while(temp1->next->data!=x)  
        {  
            temp1=temp1->next;  
            temp2=temp1->next;  
        }  
        temp1->next=temp2->next;  
        temp2->prev=temp1;  
          
        free(temp2);  
          
    }  
 
 
}  

void deleteEnd(struct node ** head_ref)
{
   if(*head_ref == NULL)
      printf("List is Empty!!! Deletion not possible!!!");
   else
   {
      struct node *temp = *head_ref;
   
         while(temp -> next != NULL)
            temp = temp -> next;
         temp -> prev -> next = NULL;
         free(temp);
    
      
   }
}
void printList(struct node *head)
{
	while (head != NULL)
  	{	
     		printf(" %d---> ", head->data);
     		head = head->next;
  	}	

}

int main()
{
	struct node* head=NULL;
	int new_data;int choice;
	while(1)
	{		
		printf("\n1)insert_front\n2)insert_At\n3)insert_end\n4)delete_front\n5)delete_At\n6)delete_End\n7)printlist\n8)exit");
		
		printf("\n enter the choice..");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("\n enter the item to insert..");
		       		scanf("%d",&new_data);
		       		insertFront(&head,new_data);
			break;
			case 2:printf("\n enter the item to insert..");
		       		scanf("%d",&new_data);
		       		insertAfter(head->next,2);
			break;	
			case 3:printf("\n enter the item to insert..");
		      		scanf("%d",&new_data);
		      		 insertEnd(&head,new_data);
			break;
			case 4:
				deleteFront(&head);
			break;
			case 5:
				printf("\n enter the item to delete...");
				scanf("%d",&new_data);
				deleteAt(&head,new_data);
			
			break;
			case 6:
				deleteEnd(&head);
			break;
			case 7:
				printList(head);
			break;
			case 8:
				exit(0);
			break;
			default:
				printf("\n InVaLiD OpTiOn...");
		
		}//switch close	
	
	}	
}

