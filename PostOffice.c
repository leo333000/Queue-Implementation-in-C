#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct CUSTOMER {
	int waiting_time;
};

struct NODE {
	CUSTOMER value;
	struct NODE *nextNode;
};


//prototype
struct CUSTOMER customer_create();
void addToQueue(CUSTOMER value, NODE* lastNode);
struct NODE* headQueue(CUSTOMER value);
struct CUSTOMER customer_create_test();
struct NODE* getFromLinkedList(NODE* head, int index);
//void popAtEnd(NODE* head);			//not used so far

int main() {
	//seeding for the random numbers
	srand(time(0));

	//creation of head of list
	struct NODE* testqueue;
	testqueue = headQueue(customer_create());

	//add 1 element to queue
	addToQueue(customer_create(), testqueue);
	//printing the value of billy(element 1) is coherent here but changes after a 3rd node is added to the list
	printf("the node after the header has a value of %i \n", testqueue->nextNode->value.waiting_time);
	fflush(stdout);

	//add another element to queue
	addToQueue(customer_create(), testqueue);
	//if i try printing the value of the element the value has changed and all of the values of the nodes are incoherent (negative and very big value)
	printf("waiting time of Alice(element 0) %i,\n", testqueue->value.waiting_time);
	printf("waiting time of Billy(element 1) %i,\n", testqueue->nextNode->value.waiting_time);
	//also it can't find conrad (problem with pointers?)
	printf("waiting time of Conrad %i,\n", testqueue->nextNode->nextNode->value.waiting_time);
	fflush(stdout);
	
	return 0;
}

//creates a value of type customer (which for now has just a waiting time, which is given to him randomly)
struct CUSTOMER customer_create() {

	struct CUSTOMER new_customer;
	new_customer.waiting_time = (rand() % 6) +4;
	return new_customer;
}
//creates a value of type customer (which for now has just a waiting time, which is constant). for testing purposes
struct CUSTOMER customer_create_test() {

	struct CUSTOMER new_customer;
	new_customer.waiting_time = 100;
	return new_customer;
}

//add an element to the queue
void addToQueue(CUSTOMER value, NODE *head) {

	//create new node

	struct NODE newNode;
	newNode.value = value;
	newNode.nextNode = NULL;

	//create pointer to that node
	struct NODE* pointerToNewNode;
	pointerToNewNode = (NODE*)malloc(sizeof(NODE));
	// do the malloc test
	pointerToNewNode = &newNode;
	

	//find the last node
	struct NODE* PointerToLastNode;
	PointerToLastNode = (NODE*)malloc(sizeof(NODE));
	PointerToLastNode = head;
	// do the malloc test
	printf("looking for the last node\n");
	fflush(stdout);

	//BIG PROBLEM HERE I THINK, THIS DOESNT ITERATE THROUGH THE LINKED LIST??
	while (!(PointerToLastNode->nextNode)) {
		printf("repeat\n");
		fflush(stdout);
		PointerToLastNode = PointerToLastNode->nextNode;
		}

	//set the pointer of the last node to the newly added node.
	PointerToLastNode->nextNode = pointerToNewNode;
	printf("head is pointing to %p\n", head->nextNode);
	fflush(stdout);
	}

//returns an element at the head of the queue
struct NODE* headQueue(CUSTOMER value) {
	struct NODE newNode;
	newNode.value = value;
	newNode.nextNode = NULL;
	struct NODE* pointerToNewNode;
	pointerToNewNode = (NODE*)malloc(sizeof(NODE));
	// do the malloc test
	return pointerToNewNode;
}


//so far not used
struct NODE* getFromLinkedList(NODE* head,int index) {
	if (index == 0) {
		return head;
	}
	else {
		struct NODE* currentPointer;
		currentPointer = (NODE*)malloc(sizeof(NODE));
		// do the malloc test
		for (int i = 0; i < index; i++) {
			if (!(currentPointer->nextNode )) {
				printf("out of bounds");
				exit(-1);
			}
			currentPointer = head->nextNode;
		}
		return currentPointer;
	}
}
/*
void popAtEnd(NODE* head) {
	struct NODE* currentPointer;
	currentPointer = (NODE*)malloc(sizeof(NODE));
	currentPointer = head;
	// do the malloc test
	while (!(currentPointer->nextNode->nextNode)) {
		currentPointer = currentPointer->nextNode;

	}
	struct NODE* PointerToDestroyedNode;
	PointerToDestroyedNode = (NODE*)malloc(sizeof(NODE));
	// do the malloc test
	PointerToDestroyedNode = currentPointer->nextNode;
	currentPointer->nextNode = NULL;
	free(PointerToDestroyedNode);
}*/




