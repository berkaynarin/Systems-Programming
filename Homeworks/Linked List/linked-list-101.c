#include <stdio.h>
#include <stdlib.h> //for memory allocation operations

void main() {

	struct Node {
		int value; //value of the node
		struct Node *next; //pointer of this struct
	};
	
	struct Node *head = NULL; //points to head of the list
	struct Node *tail = NULL; //points to tail of the list		
	
	void insertHead(struct Node* Head, int newValue) {
		struct Node *newNode = NULL;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->value = newValue; //Set newNode's value to given value
		if(Head == NULL) { //It controls the parameter Head to see if the list is empty 
			head = (struct Node*)malloc(sizeof(struct Node));  //It allocates for actual head
			tail = (struct Node*)malloc(sizeof(struct Node)); //We should allacote memory inside the if, if we do it outside, we cannot check if it's null or not
			tail->next = newNode; //Should also set the tail because tail points to null in the first place 
			newNode->next = NULL; //First node's next pointer points to null
			head->next = newNode;
		}
		else {
			newNode->next = head->next;	//Set newNode's pointer's to old head		
			head->next = newNode;	
		}
							
	}

	void insertTail(struct Node* Tail, int newValue){
		struct Node *newNode = NULL;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->value = newValue;
		if(Tail == NULL) { //It controls the parameter Tail to see if the list is empty
			head = (struct Node*)malloc(sizeof(struct Node));  //It allocates for actual head
			tail = (struct Node*)malloc(sizeof(struct Node)); 
			tail->next = newNode; //Should also set the tail because tail points to null in the first place 
			head->next = newNode;
		}
		else {
			Tail->next->next = newNode; //Set old tail's next pointer to new one
			Tail->next = newNode; //Set the tail pointer of the list to new one
		}	
		newNode->next = NULL; //Set next pointer to null because it'll be new the tail
	}	
	
	insertHead(head, 5);
	insertHead(head, 7);
	insertHead(head, 13);
	insertTail(tail, 14);	
	
	struct Node *i = head;
	int j = 1;
	
	while(i != NULL) {
		i = i->next;
		printf("%d. item: %d\n", j, i->value);		
		j++;
	}
}







