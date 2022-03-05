/* Write a program to create a single linked list and display the node elements in reverse order*/


#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node* next;
};

static void reverse(struct Node** );				//function prototype
void push(struct Node** , int);				//function prototype
void Display(struct Node *);					//function prototype

int main()
{
    
    struct Node* head = NULL;
    
     push(&head, 20);
     push(&head, 4);
     push(&head, 15); 
     push(&head, 85);      
      
     printf("Given linked list\n");
     Display(head);    
     reverse(&head);                      
     printf("\nReversed Linked list \n");
     Display(head);    
     printf("\n");
     
     return 0;
}

static void reverse(struct Node** head_ref)				//function defination to reverse a linkedlist
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void push(struct Node** head_ref, int new_data)			//Function defination to push a node
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->info = new_data;
    new_node->next = (*head_ref);    
    (*head_ref)    = new_node;
}

void Display(struct Node *head)				//function defination to print linkedlist
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->info);    
        temp = temp->next;  
    }
}
