#include <stdio.h>

void main() {

	struct Node {
		int value; //value of the node
		struct Node* next; //pointer of this struct
	};
	
	struct Node* head = NULL; //points to head of the list
	struct Node* tail = NULL; //points to tail of the list
	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL; //create nodes 
	
	
	//Allacote memory for nodes
	
	head = (struct Node*)malloc(sizeof(struct Node)); // allacote memory as much as size of the struct
	tail = (struct Node*)malloc(sizeof(struct Node));
	/*first = (struct Node*)malloc(sizeof(struct Node));  
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));	
	
	head->next = first;
	tail->next = first;
	
	first->value = 1;
	first->next = second;*/
	
	/*second->value = 5;
	second->next = third;
	
	third->value = 8;
	third->next = NULL;*/
	
	void insertHead(struct Node* head, int newValue) {
		struct Node* newNode = NULL;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->value = newValue; //Set newNode's value to given value
		newNode->next = head->next;	//Set newNode's pointer's to old head
		head->next = newNode;		
	}

	void insertTail(struct Node* tail, int newValue){
		struct Node* newNode = NULL;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->value = newValue;
		newNode->next = NULL; //Set next pointer to null because it'll be new the tail
		tail->next->next = newNode; //Set old tail's next pointer to new one
		tail->next = newNode; //Set the tail pointer of the list to new one
	}	
	
	insertHead(head, 5);
	insertTail(tail, 14);
	insertTail(tail, 17);
	
	
	struct Node* i = head;
	int j = 1;
	
	while(i != NULL) {
		i = i->next;
		printf("%d. item: %d\n", j, i->value);		
		j++;
	}
}







