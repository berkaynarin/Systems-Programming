#include<stdio.h>
#include <stdlib.h> //for memory allocation operations

int main() {
	
	struct Node {
		int value; //value of the node
		struct Node *next; //pointer of this struct
	};
	
	struct Node *head = NULL; //points to head of the list
	struct Node *tail = NULL; //points to tail of the list
	
	void enqueue(int newValue) {
		struct Node *newNode = NULL;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->value = newValue;
		if(head == NULL) { //It controls the tail to see if the list is empty
			head = (struct Node*)malloc(sizeof(struct Node));  //It allocates memory for head
			tail = (struct Node*)malloc(sizeof(struct Node)); 
			tail->next = newNode; //Should also set the tail because tail points to null in the first place 
			head->next = newNode;
		}
		else {
			tail->next->next = newNode; //Set old tail's next pointer to new one
			tail->next = newNode; //Set the tail pointer of the list to new one
		}	
		newNode->next = NULL; //Set next pointer to null because it'll be new the tail
	}
	
	void dequeue() {
		struct Node* oldNode = head->next;
		head->next = head->next->next; //Increment head pointer by one
		free(oldNode); //I hope this is the right way to free memory for dequeued node		 
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
	
	int input,Value;
	
	do{		
		printf("1. Enqueue new value to queue \n");
		printf("2. Dequeue a value from queue \n");
		printf("3. Display the queue \n");
		printf("(Press 0 to exit)\n\n");
		printf("Please choose from one of the options above: ");		
		scanf("%d", &input);
		switch(input) {
			case 1:
				printf("Enter the new value for the queue: ");
				scanf("%d", &Value);
				enqueue(Value);
				break;
			case 2:
				dequeue();
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
