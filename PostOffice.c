#include "PostOffice.h"

//Prototypes
Customer_t customer_createWT(int iWaitingTime);
Customer_t customer_create();


static void Test_shouldCreateEmptyQueue(){
	Node_t* aQueue = Queue_new();
  assert( Queue_isEmpty(aQueue) && "Test_shouldCreateEmptyQueue()" );
  Queue_print(aQueue);
}

static void Test_shouldAddCustomerToQueue(){
	Node_t* aQueue = Queue_new();

	aQueue = Queue_push(aQueue,customer_createWT(5));

  assert( !Queue_isEmpty(aQueue) && "Test_shouldAddCustomerToQueue()" );
  assert( (aQueue->value.waiting_time == 5)  && "Test_shouldAddCustomerToQueue()" );
  Queue_print(aQueue);
}

static void Test_shouldAddRandomCustomerInQueue(){
  Node_t* aQueue = Queue_new();
  Customer_t aRandomCustomer = customer_create();
  aQueue = Queue_push(aQueue,aRandomCustomer);
  assert( (Queue_size(aQueue) == 1) && "Test_shouldAddRandomCustomerInQueue()"  );
  Queue_print(aQueue);
}

static void Test_shouldAddTwoCustomersToQueue(){
  Node_t* aQueue = Queue_new();

  aQueue = Queue_push(aQueue,customer_createWT(1));
  aQueue = Queue_push(aQueue,customer_createWT(2));

  assert( (Queue_size(aQueue) == 2) && "Test_shouldAddTwoCustomersToQueue()"  );
  assert( (aQueue->value.waiting_time == 2)  && "Test_shouldAddCustomerToQueue()" );
  assert( (aQueue->next_ptr->value.waiting_time == 1)  && "Test_shouldAddCustomerToQueue()" );
  Queue_print(aQueue);
} 

static void Test_shouldPopACustomersFromTheQueue(){
  Node_t* aQueue = Queue_new();

  aQueue = Queue_push(aQueue,customer_createWT(1));
  aQueue = Queue_push(aQueue,customer_createWT(2));

  Customer_t aPoppedCustomer;
  aPoppedCustomer = Queue_pop(&aQueue);
  assert( (Queue_size(aQueue) == 1) && "Test_shouldPopACustomersFromTheQueue()"  );
  assert( (aQueue->value.waiting_time == 2) && "Test_shouldPopACustomersFromTheQueue()" );
  Queue_print(aQueue);
}

static void Test_shouldPopTheOnlyCustomerFromTheQueue(){
  Node_t* aQueue = Queue_new();
  
  aQueue = Queue_push(aQueue,customer_createWT(1));

  Customer_t aPoppedCustomer;
  aPoppedCustomer = Queue_pop(&aQueue);
  
  assert( Queue_isEmpty(aQueue) && "Test_shouldPopTheOnlyCustomerFromTheQueue()" );
  Queue_print(aQueue);
}

static void Test_shouldPopUninitializedCustomerFromAnEmptyQueue(){
  Node_t* aQueue = Queue_new();
  Customer_t Empty_customer;

  Empty_customer = Queue_pop(&aQueue);

  assert( Queue_isEmpty(aQueue) && "Test_shouldReturnUninitializedCustomerFromAnEmptyQueue()" );
  assert( (Empty_customer.waiting_time == -1) && "Test_shouldReturnUninitializedCustomerFromAnEmptyQueue()");
  Queue_print(aQueue);
}


static void Test_shouldRemoveAnExpiredCustomerFromENDOfTheQueue(){
  printf("Test_shouldRemoveAnExpiredCustomerFromENDOfTheQueue");
  Node_t* aQueue = Queue_new();

  aQueue = Queue_push(aQueue,customer_createWT(0));
  aQueue = Queue_push(aQueue,customer_createWT(1));
  aQueue = Queue_push(aQueue,customer_createWT(2));

  Queue_print(aQueue);
  aQueue = Queue_RemoveExpired(aQueue);
  Queue_print(aQueue);

  assert( (Queue_size(aQueue) == 2) && "Test_shouldRemoveAnExpiredCustomerFromENDOfTheQueue()"  );
  assert( (aQueue->value.waiting_time == 1 ) && "Test_shouldRemoveAnExpiredCustomerFromENDOfTheQueue()"  );
  assert( (aQueue->next_ptr->value.waiting_time == 0 ) && "Test_shouldRemoveAnExpiredCustomerFromENDOfTheQueue()"  );
}

static void Test_shouldRemoveAnExpiredCustomerFromMIDDLEOfTheQueue(){
  printf("Test_shouldRemoveAnExpiredCustomerFromMIDDLEOfTheQueue\n");
  Node_t* aQueue = Queue_new();

  aQueue = Queue_push(aQueue,customer_createWT(1));
  aQueue = Queue_push(aQueue,customer_createWT(0));
  aQueue = Queue_push(aQueue,customer_createWT(2));

  Queue_print(aQueue);
  aQueue = Queue_RemoveExpired(aQueue);
  Queue_print(aQueue);

  assert( (Queue_size(aQueue) == 2) && "Test_shouldRemoveAnExpiredCustomerFromMIDDLEOfTheQueue()"  );
  assert( (aQueue->value.waiting_time == 1 ) && "Test_shouldRemoveAnExpiredCustomerFromMIDDLEOfTheQueue()"  );
  assert( (aQueue->next_ptr->value.waiting_time == 0 ) && "Test_shouldRemoveAnExpiredCustomerFromMIDDLEOfTheQueue()"  );
}

static void Test_shouldRemoveAnExpiredCustomerFromSTARTOfTheQueue(){
  printf("Test_shouldRemoveAnExpiredCustomerFromSTARTOfTheQueue\n");
  Node_t* aQueue = Queue_new();

  aQueue = Queue_push(aQueue,customer_createWT(0));
  aQueue = Queue_push(aQueue,customer_createWT(1));
  aQueue = Queue_push(aQueue,customer_createWT(2));
  Queue_print(aQueue);

  aQueue = Queue_RemoveExpired(aQueue);
  Queue_print(aQueue);
  assert( (Queue_size(aQueue) == 2) && "Test_shouldRemoveAnExpiredCustomerFromSTARTOfTheQueue()"  );
  assert( (aQueue->value.waiting_time == 1 ) && "Test_shouldRemoveAnExpiredCustomerFromSTARTOfTheQueue()"  );
  assert( (aQueue->next_ptr->value.waiting_time == 0 ) && "Test_shouldRemoveAnExpiredCustomerFromSTARTOfTheQueue()"  );
}

static void Test_shouldDoNothingWhenExpiringCustomerFromAnEmptyQueue(){
  printf("Test_shouldDoNothingWhenExpiringCustomerFromAnEmptyQueue\n");
  Node_t* aQueue = Queue_new();

  aQueue = Queue_RemoveExpired(aQueue);
  
  assert( Queue_isEmpty(aQueue) && "Test_shouldDoNothingWhenExpiringCustomerFromAnEmptyQueue()" );
}



// static void Test_shouldNotAddCustomerToQueueIfQueueIsFull(){
//    Node_t* aQueue = Queue_new();

//   aQueue = Queue_push(aQueue,customer_createWT(0));
//   aQueue = Queue_push(aQueue,customer_createWT(1));

//   assert( (Queue_size(aQueue) == 2) && "Test_shouldNotAddCustomerToQueueIfQueueIsFull()"  );
// }

int main(){

  printf("\n== CREATE\n");
  Test_shouldCreateEmptyQueue();

  printf("\n== PUSH\n");
  Test_shouldAddCustomerToQueue();
  Test_shouldAddTwoCustomersToQueue();
  Test_shouldAddRandomCustomerInQueue();

  printf("\n== POP\n");
  Test_shouldPopACustomersFromTheQueue();
  Test_shouldPopTheOnlyCustomerFromTheQueue();
  Test_shouldPopUninitializedCustomerFromAnEmptyQueue();

  printf("\n== REMOVE EXPIRED\n");
  Test_shouldRemoveAnExpiredCustomerFromENDOfTheQueue();
  Test_shouldRemoveAnExpiredCustomerFromMIDDLEOfTheQueue();
  Test_shouldRemoveAnExpiredCustomerFromSTARTOfTheQueue();
  Test_shouldDoNothingWhenExpiringCustomerFromAnEmptyQueue();

  // Test_shouldNotAddCustomerToQueueIfQueueIsFull();

  printf ("All tests Passed!");
}

Customer_t customer_create() {
	Customer_t oNew_customer;
	oNew_customer.waiting_time = (rand() % 6) +4;
	return oNew_customer;
}
Customer_t customer_createWT(int iWaitingTime) {
	Customer_t oNew_customer;
	oNew_customer.waiting_time = iWaitingTime;
	return oNew_customer;
}


//creates a value of type customer (which for now has just a waiting time, which is constant). for testing purposes

//prototype

// void addToQueue(CUSTOMER value, NODE* lastNode);
// struct NODE* headQueue(CUSTOMER value);
// struct CUSTOMER customer_create_test();
// struct NODE* getFromLinkedList(NODE* head, int index);
// //void popAtEnd(NODE* head);			//not used so far

// int main() {
// 	//seeding for the random numbers
// 	srand(time(0));

// 	//creation of head of list
// 	struct NODE* testqueue;
// 	testqueue = headQueue(customer_create());

// 	//add 1 element to queue
// 	addToQueue(customer_create(), testqueue);
// 	//printing the value of billy(element 1) is coherent here but changes after a 3rd node is added to the list
// 	printf("the node after the header has a value of %i \n", testqueue->nextNode->value.waiting_time);
// 	fflush(stdout);

// 	//add another element to queue
// 	addToQueue(customer_create(), testqueue);
// 	//if i try printing the value of the element the value has changed and all of the values of the nodes are incoherent (negative and very big value)
// 	printf("waiting time of Alice(element 0) %i,\n", testqueue->value.waiting_time);
// 	printf("waiting time of Billy(element 1) %i,\n", testqueue->nextNode->value.waiting_time);
// 	//also it can't find conrad (problem with pointers?)
// 	printf("waiting time of Conrad %i,\n", testqueue->nextNode->nextNode->value.waiting_time);
// 	fflush(stdout);
	
// 	return 0;
// }

// //creates a value of type customer (which for now has just a waiting time, which is given to him randomly)



// //add an element to the queue
// void addToQueue(CUSTOMER value, NODE *head) {

	// //create new node

	// struct NODE newNode;
	// newNode.value = value;
	// newNode.nextNode = NULL;

	// //create pointer to that node
	// struct NODE* pointerToNewNode;
	// pointerToNewNode = (NODE*)malloc(sizeof(NODE));
	// // do the malloc test
	// pointerToNewNode = &newNode;
	

// 	//find the last node
// 	struct NODE* PointerToLastNode;
// 	PointerToLastNode = (NODE*)malloc(sizeof(NODE));
// 	PointerToLastNode = head;
// 	// do the malloc test
// 	printf("looking for the last node\n");
// 	fflush(stdout);

// 	//BIG PROBLEM HERE I THINK, THIS DOESNT ITERATE THROUGH THE LINKED LIST??
// 	while (!(PointerToLastNode->nextNode)) {
// 		printf("repeat\n");
// 		fflush(stdout);
// 		PointerToLastNode = PointerToLastNode->nextNode;
// 		}

// 	//set the pointer of the last node to the newly added node.
// 	PointerToLastNode->nextNode = pointerToNewNode;
// 	printf("head is pointing to %p\n", head->nextNode);
// 	fflush(stdout);
// 	}

// //returns an element at the head of the queue
// struct NODE* headQueue(CUSTOMER value) {
// 	struct NODE newNode;
// 	newNode.value = value;
// 	newNode.nextNode = NULL;
// 	struct NODE* pointerToNewNode;
// 	pointerToNewNode = (NODE*)malloc(sizeof(NODE));
// 	// do the malloc test
// 	return pointerToNewNode;
// }


// //so far not used
// struct NODE* getFromLinkedList(NODE* head,int index) {
// 	if (index == 0) {
// 		return head;
// 	}
// 	else {
// 		struct NODE* currentPointer;
// 		currentPointer = (NODE*)malloc(sizeof(NODE));
// 		// do the malloc test
// 		for (int i = 0; i < index; i++) {
// 			if (!(currentPointer->nextNode )) {
// 				printf("out of bounds");
// 				exit(-1);
// 			}
// 			currentPointer = head->nextNode;
// 		}
// 		return currentPointer;
// 	}
// }
// /*
// void popAtEnd(NODE* head) {
// 	struct NODE* currentPointer;
// 	currentPointer = (NODE*)malloc(sizeof(NODE));
// 	currentPointer = head;
// 	// do the malloc test
// 	while (!(currentPointer->nextNode->nextNode)) {
// 		currentPointer = currentPointer->nextNode;

// 	}
// 	struct NODE* PointerToDestroyedNode;
// 	PointerToDestroyedNode = (NODE*)malloc(sizeof(NODE));
// 	// do the malloc test
// 	PointerToDestroyedNode = currentPointer->nextNode;
// 	currentPointer->nextNode = NULL;
// 	free(PointerToDestroyedNode);
// }*/




