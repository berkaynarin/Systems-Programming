#include<stdio.h>
#include <stdlib.h> //for memory allocation operations

//I should use doubly linked list to track the node before last one

int main() {
	
	struct Node {
		int value; //value of the node
		struct Node *next; //next pointer of this struct
		struct Node *previous; //previous pointer of this struct
	};
	
	struct Node *head = NULL; //points to head of the list
	struct Node *tail = NULL; //points to head of the list
	
	void push(int newValue) {
		struct Node *newNode = NULL;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->value = newValue;
		if(head == NULL) { //It controls the head to see if the list is empty
			head = (struct Node*)malloc(sizeof(struct Node));  //It allocates memory for head
			tail = (struct Node*)malloc(sizeof(struct Node)); 
			tail->next = newNode; //Should also set the tail because tail points to null in the first place 
			head->next = newNode;
			//newNode->previous = NULL; //We should set the previous pointer to null because its the first node
		}
		else {
			tail->next->next = newNode; //Set old tail's next pointer to new one
			newNode->previous = tail->next;
			tail->next = newNode; //Set the tail pointer of the list to new one
		}	
		newNode->next = NULL; //Set next pointer to null because it'll be new the tail
	}
	
	void pop() {
		tail->next = tail->next->previous; //Set tail to node before last one
		struct Node* oldNode = tail->next->next;
		free(oldNode);
		tail->next->next = NULL;
	}	
	

	void display(){
		struct Node *i = head;
		int j = 1;
		
		while(i != NULL) {
			i = i->next;
			printf("%d. item: %d\n", j, i->value);		
			j++;
		}
	}	
	
	int input,pushValue;
	
	do{		
		printf("1. Push new value to stack \n");
		printf("2. Pop a value from stack \n");
		printf("3. Display the stack \n");
		printf("(Press 0 to exit)\n\n");
		printf("Please choose from one of the options above: ");		
		scanf("%d", &input);
		switch(input) {
			case 1:
				printf("Enter the new value for the stack: ");
				scanf("%d", &pushValue);
				push(pushValue);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
		}
	}while(input!=0);
	
	return 0;	
}

/*	
	Berkay Narin
	1804010008
	Computer Engineering
*/


