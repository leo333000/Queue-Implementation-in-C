#include <stdbool.h>


typedef struct CUSTOMER {
	int waiting_time;
} Customer_t;

typedef struct NODE {
	Customer_t value;
	struct NODE *next_ptr;
} Node_t;

Node_t* Queue_new();
bool Queue_isEmpty(Node_t* iHead_ptr);
Node_t* Queue_push(Node_t* iHead_ptr, Customer_t iCustomer);
void Queue_print(Node_t* iHead_ptr);