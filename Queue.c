#include "Queue.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

Node_t* Queue_new(){
    return NULL;
}

bool Queue_isEmpty(Node_t* iHead_ptr){
    return (iHead_ptr == NULL);
}

Node_t* Queue_push(Node_t* iHead_ptr, Customer_t iCustomer){
    Node_t * newNode_ptr;
    newNode_ptr = (Node_t *) malloc(sizeof(Node_t));

    newNode_ptr->value = iCustomer;
    newNode_ptr->next_ptr = iHead_ptr;
    return newNode_ptr;
}

void Queue_print(Node_t* iHead_ptr){
    Node_t * aCurrent_ptr = iHead_ptr;

    while (aCurrent_ptr != NULL) {
        printf("->%d", aCurrent_ptr->value);
        aCurrent_ptr = aCurrent_ptr->next_ptr;
    }
    printf("->NULL \n");
}