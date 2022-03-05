/*Rearrange linked list in increasing order (sort linked list). Given a linked list, write a function to rearrange its nodes to be sorted in increasing order.

Input : 6, 3, 4, 8, 2, 9
Output : 2-> 3-> 4-> 6-> 8-> 9-> NULL
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int info;
	struct Node* next;
};


void push(struct Node** , int);
void sortedInsert(struct Node** , struct Node* );
void insertSort(struct Node**);
void display(struct Node*);

int main() {
	
	int arr[] = {6, 3, 4, 8, 2, 9};
	int n = sizeof(arr)/sizeof(arr[0]);

	struct Node* head = NULL;
	
	for(int i = n-1; i >= 0; i--) {
		push(&head, arr[i]);
	}
	insertSort(&head);
	
	display(head);

return 0;
}

void display(struct Node* head) {
	struct Node* ptr = head;
	while(ptr) {
		printf("%d -> ", ptr->info);
		ptr = ptr->next;
	}
	printf("NULL");
}

void push(struct Node** head, int info) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->info = info;
	newNode->next = *head;
	*head = newNode;
}

void sortedInsert(struct Node** head, struct Node* newNode) {
	struct Node temp;
	struct Node* current = &temp;
	temp.next = *head;
	
	while(current->next != NULL && current->next->info < newNode->info) {
		current = current->next;
	}
	
	newNode->next = current->next;
	current->next = newNode;
	*head = temp.next;
}

void insertSort(struct Node** head) {
	struct Node* result = NULL;
	struct Node* current = *head;
	struct Node* next;
	
	while(current != NULL) {
		next = current->next;
		
		sortedInsert(&result, current);
		current = next;
	}
	
	*head = result;
} 


