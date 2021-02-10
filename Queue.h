#include <stdbool.h>


typedef struct CUSTOMER {
	int waiting_time;
} Customer_t;

typedef struct NODE {
	Customer_t value;
	struct NODE *next_ptr;
} Node_t;


//
//  Possible Idea for a fixed size queue? Improve the structure with max_size...
//
// typedef struct QUEUE {
// 	int max_size;
// 	Node_t *head_ptr;
// } Queue_t;
//
// Queue_t Queue_new(int iSize){
//    Queue_t aNewQueue;
//    aNewQueue.max_size = iSize;
//    aNewQueue.head_ptr = NULL;
//    return aNewQueue;
//}
//    ..and then refactor one by one all the tests.....
//
//

Node_t* Queue_new();
bool Queue_isEmpty(Node_t* iHead_ptr);
Node_t* Queue_push(Node_t* iHead_ptr, Customer_t iCustomer);
void Queue_print(Node_t* iHead_ptr);
int Queue_size(Node_t* iHead_ptr);
Customer_t Queue_pop(Node_t** iHead_ptr);
Node_t* Queue_RemoveExpired(Node_t* ioAddress_Head_ptr);